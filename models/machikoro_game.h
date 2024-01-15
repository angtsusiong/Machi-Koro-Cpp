#pragma once

#include <drogon/utils/Utilities.h>
#include <string>
#include <vector>
#include <memory>
#include <deque>

#include "bank.h"
#include "player.h"
#include "architecture_market.h"
#include "events/domain_event.h"

class MachiKoroGame {
public:
    MachiKoroGame() : game_id_(drogon::utils::getUuid()) {}
    MachiKoroGame(const std::vector<std::string>& player_names);
    MachiKoroGame(const MachiKoroGame& game) = delete;
    MachiKoroGame(MachiKoroGame&& game) = delete;
    ~MachiKoroGame();

    MachiKoroGame& operator = (const MachiKoroGame& rhs) = delete;
    MachiKoroGame& operator = (MachiKoroGame&& rhs) = delete;

    void GameStart();

    std::unique_ptr<DomainEvent> 
    RollDice(std::shared_ptr<Player> player, int dice_count);

    std::string get_game_id() const { return game_id_; }

    const int get_bank_coin() const { return bank_->get_coin(); }

    // TODO(smart pointer): implement this function.
    std::deque<std::shared_ptr<Player>> get_players() const;

private:
    const std::string game_id_;
    std::unique_ptr<Bank> bank_ = std::make_unique<Bank>();
    std::deque<std::shared_ptr<Player>> players_;
    std::unique_ptr<ArchitectureMarket> market_ = std::make_unique<ArchitectureMarket>();
};