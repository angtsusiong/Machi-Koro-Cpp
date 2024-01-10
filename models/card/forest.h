#pragma once

#include "building.h"

class Forest : public Building {
public:
    Forest();
    ~Forest() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;

};