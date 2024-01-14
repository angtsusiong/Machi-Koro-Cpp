#include "amusement_park.h"

AmusementPark::AmusementPark()
    : Landmark(16, CardName::AMUSEMENT_PARK, CardType::MAJOR_ESTABLISHMENT) {}

void AmusementPark::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}