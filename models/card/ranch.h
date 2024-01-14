#pragma once

#include "building.h"

class Ranch : public Building {
public:
    Ranch();
    ~Ranch() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;

    static const int get_price() { return price_; }
    static const CardName get_name() { return name_; }
    static const CardType get_card_type() { return card_type_; }
    static const std::vector<int> get_points() { return points_; }
    static const IndustryType get_industry_type() { return industry_type_; }

    static const int price_ = 1;
    static const CardName name_= CardName::RANCH;
    static const CardType card_type_ = CardType::ANIMAL_HUSBANDRY;
    static const std::vector<int> points_;
    static const IndustryType industry_type_ = IndustryType::PRIMARY_INDUSTRY;
};