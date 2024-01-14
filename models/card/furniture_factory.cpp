#include "furniture_factory.h"

FurnitureFactory::FurnitureFactory()
    : Building(3, CardName::FURNITURE_FACTORY, CardType::FACTORY_OR_MARKET, {8},
               IndustryType::SECONDARY_INDUSTRY) {}

void FurnitureFactory::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}