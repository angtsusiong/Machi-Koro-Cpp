#include "cafe.h"

Cafe::Cafe()
    : Building(2, CardName::CAFE, CardType::RESTAURANT, {3},
               IndustryType::RESTAURANT) {}

void Cafe::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}