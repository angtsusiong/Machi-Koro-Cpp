#pragma once

#include <vector>
#include <memory>

#include "card/card.h"

class Card;

class Hand {
public:
    Hand();
    ~Hand();

    void AddBuilding(std::unique_ptr<Card> card) 
    { buildings_.push_back(std::move(card)); }

    void AddLandmark(std::unique_ptr<Card> card) 
    { landmarks_.push_back(std::move(card)); }

    std::vector<std::shared_ptr<Card>> get_buildings() const;

    std::vector<std::shared_ptr<Card>> get_landmarks() const;

private:
    friend class Player;
    std::vector<std::shared_ptr<Card>> buildings_;
    std::vector<std::shared_ptr<Card>> landmarks_;
};