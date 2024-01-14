#pragma once

#include <string>
#include <vector>
#include <memory>

enum class CardType {
    CROP,
    NATURE_RESOURCES,
    ANIMAL_HUSBANDRY,
    SHOP,
    RESTAURANT,
    FACTORY_OR_MARKET,
    MAJOR_ESTABLISHMENT
};

enum class CardName {
    APPLE_ORCHARD,
    BAKERY,
    BUSINESS_CENTER,
    CAFE,
    CHEESE_FACTORY,
    CONVENIENCE_STORE,
    FAMILY_RESTAURANT,
    FOREST,
    FRUIT_AND_VEGETABLE_MARKET,
    FURNITURE_FACTORY,
    MINE,
    RANCH,
    STADIUM,
    TV_STATION,
    WHEAT_FIELD,
    TRAIN_STATION,
    SHOPPING_MALL,
    AMUSEMENT_PARK,
    RADIO_TOWER
};

class Bank;
class Player;

class Card {
public:
    Card() = delete;
    Card(const int price, const CardName name, const CardType type);
    ~Card() = default;

    // TODO: Resolve this dependency relationship.
    virtual void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) = 0;

    const int get_price() const { return price_; }
    const CardName get_name() const { return name_; }
    const CardType get_card_type() const { return card_type_; }

    const int price_;
    const CardName name_;
    const CardType card_type_;
};