#include "apple_orchard.h"

AppleOrchard::AppleOrchard()
    : Building(3, CardName::APPLE_ORCHARD, CardType::CROP, {10},
               IndustryType::PRIMARY_INDUSTRY) {}

void AppleOrchard::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}