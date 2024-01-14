#include "radio_tower.h"

RadioTower::RadioTower()
    : Landmark(22, CardName::RADIO_TOWER, CardType::MAJOR_ESTABLISHMENT) {}

void RadioTower::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}