#pragma once

#include "card.h"

class Landmark: public Card {
public:
    Landmark() = delete;
    Landmark(const int price, const CardName name, const CardType type);
    ~Landmark() = default;

    virtual void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) = 0;

    bool IsActivate() const { return is_activated_; };
    void Activate() { is_activated_ = true; }

private:
    // False: 背面, True: 正面。
    bool is_activated_ = false;
};