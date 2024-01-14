#include "train_station.h"

TrainStation::TrainStation()
    : Landmark(4, CardName::TRAIN_STATION, CardType::MAJOR_ESTABLISHMENT) {}

void TrainStation::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}