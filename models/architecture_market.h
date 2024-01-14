#pragma once

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

    const std::map<CardName, std::vector<std::unique_ptr<Card>>>&
    get_buildings() const { return buildings_; }
    template <typename T> void addCards(const int num);

private:
    // key: Card name; Value : Cards.
    std::map<CardName, std::vector<std::unique_ptr<Card>>> buildings_;
};