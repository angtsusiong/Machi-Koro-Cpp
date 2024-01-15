#include "machikoro_game.h"

#include <iostream>
#include <algorithm>

#include <drogon/utils/Utilities.h>
#include "events/roll_dice_event.h"

MachiKoroGame::MachiKoroGame(const std::vector<std::string>& player_names) : 
    game_id_(drogon::utils::getUuid())
{
    for (const auto& name : player_names)
        players_.emplace_back(std::make_shared<Player>(name));

    bank_ = std::make_unique<Bank>();
    for (auto& player : players_)
        bank_->PayCoin2Player(3, player);

    market_ = std::make_unique<ArchitectureMarket>();

    for (auto& player : players_) {
        player->GainInitialBuildings(std::move(market_->GetInitialBuildingsForOnePlayer()));
        player->GainLandmarks(std::move(market_->GetLandmarksForOnePlayer()));
    }

    // Choose one player as starter

}

MachiKoroGame::~MachiKoroGame()
{
    bank_ = nullptr;
    market_ = nullptr;
    for (auto& p : players_)
        p.reset();
    players_.clear();
}

void MachiKoroGame::GameStart()
{
    std::cout << "Game Start !!" << std::endl;
}

std::vector<std::shared_ptr<Player>> MachiKoroGame::get_players() const
{
    return players_;
}

std::unique_ptr<DomainEvent> 
MachiKoroGame::RollDice(std::shared_ptr<Player> player, int dice_count) 
{
    auto [pt1, pt2] = player->RollDice(dice_count);
    auto event = std::make_unique<RollDiceEvent>(pt1, pt2,
        !(dice_count == 2 && pt2 == 0));
    if (player->isLandmarkActivated(CardName::RADIO_TOWER)) {
        // Can reroll the dice or not.
        event->set_can_reroll(true);
        return event;
    }
    const int pts = pt1 + pt2;
    const std::vector<CardName> card_names = Building::getCardsAtPoint(pts);
    for (const auto card_name : card_names) {
        switch (card_name) {
            case CardName::CAFE: {
                for (auto& other : players_) {
                    if (other == player) continue;
                    for (int i = other->numOfRestaurantInHand(CardName::CAFE); i > 0; --i) {
                        if (player->get_coin())
                            player->PayCoin2AnotherPlayer(1, other.get());
                    }
                }
                break;
            }
            case CardName::FAMILY_RESTAURANT: {
                for (auto& other : players_) {
                    if (other == player) continue;
                    for (int i = other->numOfRestaurantInHand(CardName::FAMILY_RESTAURANT); i > 0; --i) {
                        if (player->get_coin() >= 2)
                            player->PayCoin2AnotherPlayer(2, other.get());
                        else if (player->get_coin() == 1)
                            player->PayCoin2AnotherPlayer(1, other.get());
                    }
                }
                break;
            }
            default:
                break;
        }
    }

    for (const auto card_name : card_names) {
        int num_of_secondary = player->numOfSecondaryInHand(card_name);
        if (num_of_secondary) {
            switch (card_name) {
                case CardName::BAKERY: {
                    bank_->PayCoin2Player(1 * num_of_secondary, player);
                    break;
                }
                case CardName::CONVENIENCE_STORE: {
                    bank_->PayCoin2Player(3 * num_of_secondary, player);
                    break;
                }
                case CardName::CHEESE_FACTORY: {
                    int num_of_animal =
                        player->numOfPrimaryInHand(CardName::RANCH);
                    if (num_of_animal)
                        bank_->PayCoin2Player(3 * num_of_secondary * num_of_animal, player);
                    break;
                }
                case CardName::FURNITURE_FACTORY: {
                    int num_of_natural = player->numOfPrimaryInHand(CardName::FOREST) + 
                        player->numOfPrimaryInHand(CardName::MINE);
                    if (num_of_natural) 
                        bank_->PayCoin2Player(3 * num_of_secondary * num_of_natural, player);
                    break;
                }
                case CardName::FRUIT_AND_VEGETABLE_MARKET: {
                    int num_of_crop = player->numOfPrimaryInHand(CardName::WHEAT_FIELD) + 
                        player->numOfPrimaryInHand(CardName::APPLE_ORCHARD);
                    if (num_of_crop)
                        bank_->PayCoin2Player(2 * num_of_secondary * num_of_crop, player);
                    break;
                }
                default:
                    break;
            }
        }
    }

    for (const auto card_name : card_names) {
        switch (card_name) {
            case CardName::WHEAT_FIELD: {
                for (auto& p : players_) {
                    int num_of_primary = p->numOfPrimaryInHand(CardName::WHEAT_FIELD);
                    if (num_of_primary)
                        bank_->PayCoin2Player(1 * num_of_primary, p);
                }
                break;
            }
            case CardName::RANCH: {
                for (auto& p : players_) {
                    int num_of_primary = p->numOfPrimaryInHand(CardName::RANCH);
                    if (num_of_primary)
                        bank_->PayCoin2Player(1 * num_of_primary, p);
                }
                break;
            }
            case CardName::FOREST: {
                for (auto& p : players_) {
                    int num_of_primary = p->numOfPrimaryInHand(CardName::FOREST);
                    if (num_of_primary)
                        bank_->PayCoin2Player(1 * num_of_primary, p);
                }
                break;
            }
            case CardName::MINE: {
                for (auto& p : players_) {
                    int num_of_primary = p->numOfPrimaryInHand(CardName::MINE);
                    if (num_of_primary)
                        bank_->PayCoin2Player(5 * num_of_primary, p);
                }
                break;
            }
            case CardName::APPLE_ORCHARD: {
                for (auto& p : players_) {
                    int num_of_primary = p->numOfPrimaryInHand(CardName::APPLE_ORCHARD);
                    if (num_of_primary)
                        bank_->PayCoin2Player(3 * num_of_primary, p);
                }
                break;
            }
            default:
                break;
        }
    }
    // Operate effect. 

    // If two points are the same, can roll the dice in next round or not.
    if (pt1 == pt2 &&
        player->isLandmarkActivated(CardName::AMUSEMENT_PARK))
        event->set_can_roll_next(true);
    return event;
}