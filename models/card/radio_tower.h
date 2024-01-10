#pragma once

#include "landmark.h"

class RadioTower : public Landmark {
public:
    RadioTower();
    ~RadioTower() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;

};