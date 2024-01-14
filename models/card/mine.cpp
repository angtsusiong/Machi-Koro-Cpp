#include "mine.h"

Mine::Mine() :
    Building(6, CardName::MINE, CardType::NATURE_RESOURCES, {9}, IndustryType::PRIMARY_INDUSTRY)
{
}

void Mine::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}