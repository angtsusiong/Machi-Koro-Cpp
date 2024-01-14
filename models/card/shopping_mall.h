#pragma once

#include "landmark.h"

class ShoppingMall : public Landmark{
public:
    ShoppingMall();
    ~ShoppingMall() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;

    static const int get_price() { return price_; }
    static const CardName get_name() { return name_; }
    static const CardType get_card_type() { return card_type_; }

    static const int price_ = 10;
    static const CardName name_= CardName::SHOPPING_MALL;
    static const CardType card_type_ = CardType::MAJOR_ESTABLISHMENT;
};