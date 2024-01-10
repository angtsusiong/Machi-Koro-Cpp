#pragma once

#include "building.h"

class CheeseFactory : public Building {
public:
    CheeseFactory();
    ~CheeseFactory() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;

};