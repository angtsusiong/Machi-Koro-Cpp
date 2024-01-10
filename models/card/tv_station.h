#pragma once

#include "building.h"

class TvStation : public Building {
public:
    TvStation();
    ~TvStation() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;
};