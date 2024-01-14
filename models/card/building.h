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