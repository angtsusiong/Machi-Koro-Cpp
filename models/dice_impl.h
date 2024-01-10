#pragma once

#include "dice.h"

class DiceImpl : public Dice {
public:
    DiceImpl() = default;
    ~DiceImpl() = default;

    int GeneratePoint() const final;
};