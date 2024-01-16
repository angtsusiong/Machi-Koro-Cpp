#pragma once

#include <array>
#include <map>
#include <string>
#include <vector>
#include <memory>

#include "card/building.h"
#include "card/landmark.h"

class ArchitectureMarket {
public:
    ArchitectureMarket();
    ~ArchitectureMarket();

    ArchitectureMarket& operator = (const ArchitectureMarket& rhs) = delete;
    ArchitectureMarket& operator = (ArchitectureMarket&& rhs) = delete;

    std::vector<std::unique_ptr<Card>> GetInitialBuildingsForOnePlayer();
    std::vector<std::unique_ptr<Card>> GetLandmarksForOnePlayer();
    std::vector<CardName> acquireInitBuildings();

    template <typename T> void addCards(const int num);

private:
    // key: Card name; Value : Cards.
    std::map<CardName, std::vector<std::unique_ptr<Card>>> buildings_;
    std::array<int, 19> m_cards{0};
};