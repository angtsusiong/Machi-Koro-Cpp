#pragma once

#include "building.h"

class Stadium : public Building {
public:
    Stadium();
    ~Stadium() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;

};