#include "wheat_field.h"

WheatField::WheatField()
    : Building(1, CardName::WHEAT_FIELD, CardType::CROP, {1},
               IndustryType::PRIMARY_INDUSTRY) {}

void WheatField::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}