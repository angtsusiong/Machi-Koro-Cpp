#pragma once

#include <string>
#include <vector>
#include <memory>
#include <utility>

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

    void PayCoin2AnotherPlayer(int coin, std::shared_ptr<Player> other);

    void GainLandmarks(std::vector<std::unique_ptr<Card>>&& cards);

    void GainInitialBuildings(std::vector<std::unique_ptr<Card>>&& cards);

    int get_coin() const { return coin_; }

    void set_name(const std::string& name) { name_ = name; }
    std::string get_name() const { return name_; }

    std::shared_ptr<Hand> get_hand() const { return hand_; }

    bool isLandmarkActivated(const CardName card_name) const;
    void activateLandmark(const CardName card_name);
    int numOfRestaurantInHand(const CardName card_name) const;
    int numOfSecondaryInHand(const CardName card_name) const;
    int numOfPrimaryInHand(const CardName card_name) const;
    bool isImportantInHand(const CardName card_name) const;

    void acquireInitBuildings(const std::vector<CardName>& cards) {
        hand_->add_buildings(cards);
    }
private:
    int coin_ = 0;
    std::string name_;
    std::shared_ptr<Hand> hand_;
};