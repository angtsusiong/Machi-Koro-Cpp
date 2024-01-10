#pragma once

class Dice {
public:
    Dice() = default;
    ~Dice() = default;

    virtual int GeneratePoint() const = 0;
};