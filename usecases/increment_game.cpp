#include "increment_game.h"

#include <memory>

#include "loggers/logger_base.h"
#include "models/events/increment_game_event.h"
#include "models/machikoro_game.h"
#include "presenters/presenter.h"
#include "repos/repository.h"
#include "utils/util_base.h"

IncrementGameRequest::IncrementGameRequest(const std::string& id)
    : id_(id)
{
}

IncrementGameUsecase::IncrementGameUsecase(std::shared_ptr<LoggerBase> logger, std::shared_ptr<UtilBase> util)
    : log_(logger)
    , util_(util)
{
}

void IncrementGameUsecase::execute(IncrementGameRequest& req, Repository& repo, Presenter& presenter)
{
    // Find.
    auto game = repo.findById(req.id());

    if (!game)
    {
        auto err_event = std::make_shared<IncrementGameEvent>();
        err_event->set_status(StatusCode::BadRequest);
        err_event->set_message("Failed to init game because cannot find the game ID !");
        log_->error(err_event->message());
        presenter.present(err_event.get());
        return;
    }

    // Modify.
    auto event = game->incrementCurrentPlayer();

    // Save.
    // Save in memory currently.

    // Push back.
    presenter.present(event.get());
}