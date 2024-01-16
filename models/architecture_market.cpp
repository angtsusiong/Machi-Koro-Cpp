#include "architecture_market.h"

#include <cassert>

#include "card/wheat_field.h"
#include "card/ranch.h"
#include "card/bakery.h"
#include "card/cafe.h"
#include "card/convenient_store.h"
#include "card/forest.h"
#include "card/stadium.h"
#include "card/tv_station.h"
#include "card/business_center.h"
#include "card/cheese_factory.h"
#include "card/furniture_factory.h"
#include "card/mine.h"
#include "card/family_restaurant.h"
#include "card/apple_orchard.h"
#include "card/fruit_and_vegetable_market.h"
#include "card/amusement_park.h"
#include "card/radio_tower.h"
#include "card/shopping_mall.h"
#include "card/train_station.h"

ArchitectureMarket::ArchitectureMarket()
{
    m_cards = {6, 10, 4, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 10,
        4, 4, 4, 4};

    // Buildings.
    addCards<WheatField>(10);
    addCards<Ranch>(6);
    addCards<Bakery>(10);
    addCards<Cafe>(6);
    addCards<ConvenientStore>(6);
    addCards<Forest>(6);
    addCards<Stadium>(4);
    addCards<TvStation>(4);
    addCards<BusinessCenter>(4);
    addCards<CheeseFactory>(6);
    addCards<FurnitureFactory>(6);
    addCards<Mine>(6);
    addCards<FamilyRestaurant>(6);
    addCards<AppleOrchard>(6);
    addCards<FruitAndVegetableMarket>(6);

    // Landmarks.
    addCards<AmusementPark>(4);
    addCards<RadioTower>(4);
    addCards<ShoppingMall>(4);
    addCards<TrainStation>(4);
}

template <typename T>
void ArchitectureMarket::addCards(const int num) {
    for (int i = 0; i < num; ++i)
        buildings_[T::get_name()].emplace_back(std::make_unique<T>());
}

ArchitectureMarket::~ArchitectureMarket()
{
    for (auto& cards : buildings_)
        for (auto& c : cards.second) c = nullptr;
    buildings_.clear();
}

std::vector<std::unique_ptr<Card>> ArchitectureMarket::GetInitialBuildingsForOnePlayer()
{
    // 每個玩家一開始都各持有一張小麥田和麵包店。
    std::vector<std::unique_ptr<Card>> cards;
    if (!buildings_[CardName::WHEAT_FIELD].empty() && buildings_[CardName::WHEAT_FIELD].back()) {
        cards.emplace_back(std::move(buildings_[CardName::WHEAT_FIELD].back()));
        buildings_[CardName::WHEAT_FIELD].pop_back();
    }
    if (!buildings_[CardName::BAKERY].empty() && buildings_[CardName::BAKERY].back()) {
        cards.emplace_back(std::move(buildings_[CardName::BAKERY].back()));
        buildings_[CardName::BAKERY].pop_back();
    }
    return cards;
}

std::vector<CardName> ArchitectureMarket::acquireInitBuildings() {
    for (size_t card : {static_cast<size_t>(CardName::WHEAT_FIELD), static_cast<size_t>(CardName::BAKERY)})
        --m_cards[card];
    return {CardName::WHEAT_FIELD, CardName::BAKERY};
}

std::vector<std::unique_ptr<Card>> ArchitectureMarket::GetLandmarksForOnePlayer()
{
    // 每個玩家一開始各分到一張主題樂園、一張廣播電台、一張購物中心，以及一張火車站。
    std::vector<std::unique_ptr<Card>> cards;
    if (!buildings_[CardName::AMUSEMENT_PARK].empty() && buildings_[CardName::AMUSEMENT_PARK].back()) {
        cards.emplace_back(std::move(buildings_[CardName::AMUSEMENT_PARK].back()));
        buildings_[CardName::AMUSEMENT_PARK].pop_back();
    }
    if (!buildings_[CardName::RADIO_TOWER].empty() && buildings_[CardName::RADIO_TOWER].back()) {
        cards.emplace_back(std::move(buildings_[CardName::RADIO_TOWER].back()));
        buildings_[CardName::RADIO_TOWER].pop_back();
    }
    if (!buildings_[CardName::SHOPPING_MALL].empty() && buildings_[CardName::SHOPPING_MALL].back()) {
        cards.emplace_back(std::move(buildings_[CardName::SHOPPING_MALL].back()));
        buildings_[CardName::SHOPPING_MALL].pop_back();
    }
    if (!buildings_[CardName::TRAIN_STATION].empty() && buildings_[CardName::TRAIN_STATION].back()) {
        cards.emplace_back(std::move(buildings_[CardName::TRAIN_STATION].back()));
        buildings_[CardName::TRAIN_STATION].pop_back();
    }
    return cards;
}