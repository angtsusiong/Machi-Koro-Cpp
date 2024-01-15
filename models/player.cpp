#include "player.h"

#include <algorithm>
#include <random>

#include "card/card.h"
#include "card/landmark.h"

Player::Player()
    : hand_(std::make_shared<Hand>())
{
}

Player::Player(const std::string& name)
    : name_(name)
    , hand_(std::make_shared<Hand>())
{
}

Player::~Player()
{
}

std::pair<int, int> Player::RollDice(int dice_count) {
    // If have TrainStation and want to roll 2 dice,
    // then let it roll 2 dice.
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 6);
    if (hand_->IsLandmarkInHand(CardName::TRAIN_STATION) && dice_count == 2)
        return {dist(gen), dist(gen)};
    return {dist(gen), 0};
}

void Player::PayCoin(int coin)
{
    coin_ -= coin;
}

void Player::GainCoin(int coin)
{
    coin_ += coin;
}

void Player::PayCoin2AnotherPlayer(int coin, std::shared_ptr<Player> other)
{
    this->PayCoin(coin);
    other->GainCoin(coin);
}

void Player::GainLandmarks(std::vector<std::unique_ptr<Card>>&& cards)
{
    for (auto& card : cards)
        hand_->AddLandmark(std::move(card));
}

void Player::GainInitialBuildings(std::vector<std::unique_ptr<Card>>&& cards)
{
    for (auto& card : cards)
        hand_->AddBuilding(std::move(card));
}

bool Player::isLandmarkActivated(const CardName card_name) const
{
    return hand_->IsLandmarkInHand(card_name);
}

void Player::activateLandmark(const CardName card_name)
{
    hand_->ActivateLandmark(card_name);
}

int Player::numOfRestaurantInHand(const CardName card_name) const
{
    return hand_->NumOfBuildingInHand(card_name);
}

int Player::numOfSecondaryInHand(const CardName card_name) const
{
    if (card_name == CardName::BAKERY || card_name == CardName::CONVENIENCE_STORE
        || card_name == CardName::CHEESE_FACTORY || card_name == CardName::FURNITURE_FACTORY
        || card_name == CardName::FRUIT_AND_VEGETABLE_MARKET)
        return hand_->NumOfBuildingInHand(card_name);
    return 0;
}

int Player::numOfPrimaryInHand(const CardName card_name) const
{
    return hand_->NumOfBuildingInHand(card_name);
}

bool Player::isImportantInHand(const CardName card_name) const {
    if (card_name == CardName::STADIUM || card_name == CardName::TV_STATION ||
        card_name == CardName::BUSINESS_CENTER)
        return hand_->IsBuildingInHand(card_name);
    return false;
}