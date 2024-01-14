#include "bakery.h"

Bakery::Bakery()
    : Building(1, CardName::BAKERY, CardType::SHOP, {2, 3},
               IndustryType::SECONDARY_INDUSTRY) {}

void Bakery::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}