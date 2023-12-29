#ifndef MACHIKORO_GAME_H
#define MACHIKORO_GAME_H

#include <drogon/utils/Utilities.h>
#include <string>
#include <vector>
#include <memory>

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
    RollDice(const std::string& player_id, int dice_count);

    std::string get_game_id() const { return game_id_; }

    const Bank* get_bank() const { return bank_.get(); }

    const ArchitectureMarket* get_market() const { return market_.get(); }

    // TODO(smart pointer): implement this function.
    std::vector<Player*> get_players();

private:
    const std::string game_id_;
    std::unique_ptr<Bank> bank_ = std::make_unique<Bank>();
    std::vector<std::unique_ptr<Player>> players_;
    std::unique_ptr<ArchitectureMarket> market_ = std::make_unique<ArchitectureMarket>();
};

#endif