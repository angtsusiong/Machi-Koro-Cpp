#include "family_restaurant.h"

FamilyRestaurant::FamilyRestaurant()
    : Building(3, CardName::FAMILY_RESTAURANT, CardType::RESTAURANT, {9, 10},
               IndustryType::RESTAURANT) {}

void FamilyRestaurant::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}