#include "increment_game_controller.h"

#include "loggers/logger_base.h"
#include "presenters/increment_game_present.h"
#include "repos/memory_repository.h"
#include "usecases/increment_game.h"
#include "utils/util_base.h"

void IncrementGame::incrementGame(const HttpRequestPtr& req,
                        std::function<void(const HttpResponsePtr&)>&& callback,
                        const std::string& game_id)
{
    log_->info("Receive init game request. ID: " + game_id);

    IncrementGameRequest increment_req(game_id);
    IncrementGameUsecase uc(log_, util_);
    IncrementGamePresenter presenter(util_);

    uc.execute(increment_req, MemoryRepository::self(), presenter);

    auto res = HttpResponse::newHttpJsonResponse(presenter.view_model()->getJson());
    res->setStatusCode(presenter.status());
    callback(res);
}