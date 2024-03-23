#include "create_game.h"

#include <memory>
#include <vector>
#include <string>

#include "models/dice_impl.h"

CreateGameRequest::CreateGameRequest(const std::vector<std::string>& names)
    : names_(names)
{
}

std::vector<Player> CreateGameRequest::players()
{
    // TODO: 有關骰子的部分，到底要在哪裡塞進遊戲裡（為了假骰子、做測試），待商確。
    std::vector<Player> players;
    auto dice = std::make_shared<DiceImpl>();
    for (const auto& name : names_) players.emplace_back(name, dice);
    return players;
}

CreateGameUsecase::CreateGameUsecase(std::shared_ptr<Logger> logger, std::shared_ptr<Util> util)
    : log_(logger)
    , util_(util)
{
}

void CreateGameUsecase::execute(CreateGameRequest& req, Repository& repo, Presenter& presenter)
{
    // Find.
    auto game = std::make_unique<MachiKoroGame>(log_, util_);

    // Modify.
    auto event = game->createGame(std::move(req.players()));

    // Save.
    if (event->status() == StatusCode::Ok) repo.save(std::move(game));

    // Push back.
    presenter.present(event.get());
}