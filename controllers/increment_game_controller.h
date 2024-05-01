#ifndef CONTROLLERS_INCREMENT_GAME_CONTROLLER_H
#define CONTROLLERS_INCREMENT_GAME_CONTROLLER_H

#include <memory>

#include "drogon/HttpController.h"
#include "utils/util.h"
#include "loggers/logger.h"

class LoggerBase;
class UtilBase;

using namespace drogon;

class IncrementGame : public drogon::HttpController<IncrementGame> {
public:
    METHOD_LIST_BEGIN
    METHOD_ADD(IncrementGame::incrementGame, "/{game_id}", Post);
    METHOD_LIST_END

    void incrementGame(const HttpRequestPtr& req,
                  std::function<void(const HttpResponsePtr&)>&& callback,
                  const std::string& game_id);

private:
    // Logger.
    std::shared_ptr<LoggerBase> log_ = Logger::self();

    // Utility.
    std::shared_ptr<UtilBase> util_ = Util::self();
};

#endif  // CONTROLLERS_INCREMENT_GAME_CONTROLLER_H