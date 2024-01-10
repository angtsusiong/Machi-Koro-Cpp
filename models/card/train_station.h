#pragma once

#include "landmark.h"

class TrainStation : public Landmark{
public:
    TrainStation();
    ~TrainStation() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;

};