#include "hand.h"
#include <algorithm>

Hand::Hand() {}

Hand::~Hand() {
  for (auto &c : buildings_)
    c = nullptr;
  buildings_.clear();
  for (auto &l : landmarks_)
    l = nullptr;
  landmarks_.clear();
}

bool Hand::IsLandmarkInHand(const CardName card_name) const {
  auto it = std::find_if(
      landmarks_.begin(), landmarks_.end(),
      [card_name](std::shared_ptr<Card> card) {
        return card->get_name() == card_name &&
               std::dynamic_pointer_cast<Landmark>(card)->IsActivate();
      });
  return it != landmarks_.end();
}

bool Hand::IsBuildingInHand(const CardName card_name) const {
  auto it = std::find_if(
      buildings_.begin(), buildings_.end(),
      [card_name](std::shared_ptr<Card> building) {
        return building->get_name() == card_name;
      });
  return it != buildings_.end();
}

int Hand::NumOfBuildingInHand(const CardName card_name) const {
  return std::count_if(
      buildings_.begin(), buildings_.end(),
      [card_name](std::shared_ptr<Card> building) {
        return building->get_name() == card_name;
      });
}

void Hand::ActivateLandmark(const CardName card_name) {
  auto it = std::find_if(
      landmarks_.begin(), landmarks_.end(),
      [card_name](std::shared_ptr<Card> card) {
        return card->get_name() == card_name;
      });
  if (it != landmarks_.end())
    std::dynamic_pointer_cast<Landmark>(*it)->Activate();
}