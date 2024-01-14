#include "stadium.h"

Stadium::Stadium()
    : Building(6, CardName::STADIUM, CardType::MAJOR_ESTABLISHMENT, {6},
               IndustryType::IMPORTANT_BUILDING) {}

void Stadium::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}