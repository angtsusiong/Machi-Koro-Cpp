#pragma once

#include "../models/machikoro_game.h"

class Presenter {
public:
    virtual void Present(std::shared_ptr<MachiKoroGame> game) = 0;
};
