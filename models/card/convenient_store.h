#pragma once

#include "building.h"

class ConvenientStore : public Building {
public:
    ConvenientStore();
    ~ConvenientStore() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;

};