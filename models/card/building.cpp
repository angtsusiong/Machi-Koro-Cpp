#include "building.h"

Building::Building(const int price, const CardName name,
                   const CardType card_type, const std::vector<int> &points,
                   const IndustryType industry_type)
    : Card(price, name, card_type), price_(price), name_(name), card_type_(card_type), points_(points),
      industry_type_(industry_type) {}