#include "cafe.h"

#include "models/bank.h"
#include "models/player.h"

Cafe::Cafe()
    : Building(CardName::CAFE, CardType::RESTAURANT, 2, IndustryType::RESTAURANT, { 2, 3 })
{
}

void Cafe::OperateEffect(Player* owner,
                         Player* dice_roller,
                         std::vector<Player*> players,
                         std::shared_ptr<Bank> bank)
{
}