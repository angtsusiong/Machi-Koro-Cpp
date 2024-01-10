#pragma once

#include "building.h"

class FruitAndVegetableMarket: public Building {
public:
    FruitAndVegetableMarket();
    ~FruitAndVegetableMarket() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;

};