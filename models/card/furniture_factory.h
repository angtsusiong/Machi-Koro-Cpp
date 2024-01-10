#pragma once

#include "building.h"

class FurnitureFactory : public Building {
public:
    FurnitureFactory();
    ~FurnitureFactory() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;

};