#include "business_center.h"

BusinessCenter::BusinessCenter()
    : Building(8, CardName::BUSINESS_CENTER, CardType::MAJOR_ESTABLISHMENT, {6},
               IndustryType::IMPORTANT_BUILDING) {}

void BusinessCenter::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}