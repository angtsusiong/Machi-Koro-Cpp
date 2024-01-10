#pragma once

#include "building.h"

class Mine : public Building {
public:
    Mine();
    ~Mine() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;

};