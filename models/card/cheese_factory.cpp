#include "cheese_factory.h"

CheeseFactory::CheeseFactory()
    : Building(5, CardName::CHEESE_FACTORY, CardType::FACTORY_OR_MARKET, {7},
               IndustryType::SECONDARY_INDUSTRY) {}

void CheeseFactory::OperateEffect(Player *owner, Player *dice_roller,
                                  std::vector<Player *> players, Bank *bank) {}