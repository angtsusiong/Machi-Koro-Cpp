#pragma once

#include <array>
#include <vector>
#include <memory>
#include <unordered_set>

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

    void add_buildings(const std::vector<CardName>& cards) {
        for (auto card : cards) ++m_buildings[static_cast<size_t>(card)];
    }
    std::array<int, 15> get_buildings_count() const { return m_buildings; }
private:
    friend class Player;
    std::array<int, 15> m_buildings{};
    std::unordered_set<CardName> m_landmarks{};
    std::vector<std::shared_ptr<Card>> buildings_;
    std::vector<std::shared_ptr<Card>> landmarks_;
};