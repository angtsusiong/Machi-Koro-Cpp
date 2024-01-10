#pragma once

#include "building.h"

class FamilyRestaurant : public Building {
public:
    FamilyRestaurant();
    ~FamilyRestaurant() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;

};