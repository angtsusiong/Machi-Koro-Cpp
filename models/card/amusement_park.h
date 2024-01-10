#pragma once

#include "landmark.h"

class AmusementPark : public Landmark {
public:
    AmusementPark();
    ~AmusementPark() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;

};