#ifndef USECASES_INCREMENT_GAME_H
#define USECASES_INCREMENT_GAME_H

#include <string>
#include <memory>

class LoggerBase;
class Presenter;
class Repository;
class UtilBase;

class IncrementGameRequest {
public:
    IncrementGameRequest() = default;

    explicit IncrementGameRequest(const std::string& id);

    ~IncrementGameRequest() = default;

    std::string id() { return id_; }

private:
    // Game ID.
    std::string id_;
};

class IncrementGameUsecase {
public:
    IncrementGameUsecase(std::shared_ptr<LoggerBase> logger, std::shared_ptr<UtilBase> util);

    ~IncrementGameUsecase() = default;

    // Find / Modify / Save / Push back.
    void execute(IncrementGameRequest& req, Repository& repo, Presenter& presenter);

private:
    std::shared_ptr<LoggerBase> log_ = nullptr;

    std::shared_ptr<UtilBase> util_ = nullptr;
};

#endif  // USECASES_INCREMENT_GAME_H