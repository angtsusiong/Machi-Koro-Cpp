#pragma once

#include <vector>
#include "card.h"

enum class IndustryType {
    RESTAURANT,
    SECONDARY_INDUSTRY,
    PRIMARY_INDUSTRY,
    IMPORTANT_BUILDING
};

class Building : public Card {
public:
    Building() = delete;
    Building(const int price, const CardName name, const CardType card_type,
             const std::vector<int> &points, const IndustryType industry_type);
    ~Building() = default;

    virtual void OperateEffect(Player* owner,
        Player* dice_roller, std::vector<Player*> players, Bank* bank) = 0;

    static std::vector<CardName> getCardsAtPoint(const int point) {
        switch(point) {
            case 1:
                return {CardName::WHEAT_FIELD};
            case 2:
                return {CardName::BAKERY, CardName::RANCH};
            case 3:
                return {CardName::BAKERY, CardName::CAFE};
            case 4:
                return {CardName::CONVENIENCE_STORE};
            case 5:
                return {CardName::FOREST};
            case 6:
                return {CardName::STADIUM, CardName::TV_STATION, CardName::BUSINESS_CENTER};
            case 7:
                return {CardName::CHEESE_FACTORY};
            case 8:
                return {CardName::FURNITURE_FACTORY};
            case 9:
                return {CardName::MINE, CardName::FAMILY_RESTAURANT};
            case 10:
                return {CardName::FAMILY_RESTAURANT, CardName::APPLE_ORCHARD};
            case 11:
                return {CardName::FRUIT_AND_VEGETABLE_MARKET};
            case 12:
                return {CardName::FRUIT_AND_VEGETABLE_MARKET};
            default:
                return {};
        }
    }
    const int get_price() { return price_; }
    const CardName get_name() { return name_; }
    const CardType get_card_type() { return card_type_; }
    const std::vector<int> get_points() { return points_; }
    const IndustryType get_industry_type() { return industry_type_; }

    const int price_;
    const CardName name_;
    const CardType card_type_;
    const std::vector<int> points_;
    const IndustryType industry_type_;
};