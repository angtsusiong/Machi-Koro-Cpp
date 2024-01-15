#pragma once

#include <vector>
#include <memory>

#include "card/card.h"
#include "card/landmark.h"

class Hand {
public:
    Hand();
    ~Hand();

    void AddBuilding(std::unique_ptr<Card> card) 
    { buildings_.push_back(std::move(card)); }

    void AddLandmark(std::unique_ptr<Card> card) 
    { landmarks_.push_back(std::move(card)); }

    std::vector<std::shared_ptr<Card>> get_buildings() const { return buildings_; }
    std::vector<std::shared_ptr<Card>> get_landmarks() const { return landmarks_; }

    bool IsLandmarkInHand(const CardName card_name) const;
    bool IsBuildingInHand(const CardName card_name) const;
    int NumOfBuildingInHand(const CardName card_name) const;
    void ActivateLandmark(const CardName card_name);

private:
    friend class Player;
    std::vector<std::shared_ptr<Card>> buildings_;
    std::vector<std::shared_ptr<Card>> landmarks_;
};