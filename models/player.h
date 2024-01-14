#pragma once

#include <string>
#include <vector>
#include <memory>
#include <utility>

#include "dice_impl.h"
#include "hand.h"

class Player {
public:
    Player();
    Player(const std::string& name);
    Player(const Player& player) = delete;
    Player(Player&& player) = delete;
    ~Player();

    Player& operator = (const Player& rhs) = delete;
    Player& operator = (Player&& rhs) = delete;

    std::pair<int, int> RollDice(int dice_count);

    void PayCoin(int coin);

    void GainCoin(int coin);

    void PayCoin2AnotherPlayer(int coin, Player* other);

    void GainLandmarks(std::vector<std::unique_ptr<Card>>&& cards);

    void GainInitialBuildings(std::vector<std::unique_ptr<Card>>&& cards);

    int get_coin() const { return coin_; }

    void set_name(const std::string& name) { name_ = name; }
    std::string get_name() const { return name_; }

    std::shared_ptr<Hand> get_hand() const { return hand_; }

private:
    int coin_ = 0;
    DiceImpl dice_;
    std::string name_;
    std::shared_ptr<Hand> hand_;
};