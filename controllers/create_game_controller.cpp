#include "create_game_controller.h"

#include <iostream>
#include <string>
#include <vector>

#include "utils.h"
#include "in_memory_repository.h"

// Add definition of your processing function here
// TODO: deal with same gameName
void CreateGame::createGame(const drogon::HttpRequestPtr &req,
               std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
    LOG_INFO << "Receive createGame request.";

    auto json = req->getJsonObject();
    if (!json)
    {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setBody("missing 'value' in body");
        resp->setStatusCode(drogon::HttpStatusCode::k400BadRequest);
        callback(resp);
        return;
    }
    
    std::vector<std::string> player_names = 
        controllers::utils::JsonValueToVectorOfString((*json)[controllers::utils::player_names]);
    
    CreateGamePresenter presenter;
    
    CreateGameUsecase uc;
    uc.CreateGameExecute(
        CreateGameUsecaseRequest(player_names), InMemoryRepository::self(), presenter);
    
    auto resp = drogon::HttpResponse::newHttpJsonResponse(presenter.GetViewModel());
    callback(resp);
}

void CreateGamePresenter::Present(std::shared_ptr<MachiKoroGame> game)
{
    game_id_ = game->get_game_id();
}

Json::Value CreateGamePresenter::GetViewModel() const
{
    Json::Value res;
    res["result"] = "ok";
    res[controllers::utils::game_id] = game_id_; 
    return res;
}
