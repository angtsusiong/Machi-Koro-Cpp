#pragma once

#include "building.h"

class BusinessCenter : public Building {
public:
    BusinessCenter();
    ~BusinessCenter() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;

};