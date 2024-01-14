#include "tv_station.h"

TvStation::TvStation()
    : Building(7, CardName::TV_STATION, CardType::MAJOR_ESTABLISHMENT, {6},
               IndustryType::IMPORTANT_BUILDING) {}

void TvStation::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}