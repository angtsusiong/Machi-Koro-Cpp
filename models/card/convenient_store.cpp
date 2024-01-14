#include "convenient_store.h"

ConvenientStore::ConvenientStore()
    : Building(2, CardName::CONVENIENCE_STORE, CardType::SHOP, {4},
               IndustryType::SECONDARY_INDUSTRY) {}

void ConvenientStore::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}