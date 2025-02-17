#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../../models/machikoro_game.h"

class GameTest : public testing::Test {
protected:
    std::shared_ptr<MachiKoroGame> game_;

    void SetUp() override {
        std::vector<std::string> names = {"Alice", "Bob", "Cindy", "David"};
        game_ = std::make_shared<MachiKoroGame>(names);
    }
    
    void TearDown() override {
        game_.reset();
    }
};

TEST_F(GameTest, GameInit) {
    ASSERT_TRUE(game_ != nullptr);
    ASSERT_EQ(game_->get_players().size(), 4);
    EXPECT_EQ(game_->get_bank_coin(), 282 - 3 * 4);
    for (auto& player : game_->get_players()) {
        EXPECT_EQ(player->get_hand()->get_buildings().size(), 2);
        EXPECT_EQ(player->get_hand()->get_landmarks().size(), 4);
        EXPECT_EQ(player->get_coin(), 3);
        EXPECT_EQ(player->get_hand()->get_buildings_count()[static_cast<size_t>(CardName::WHEAT_FIELD)], 1);
    }
    // 19 types of cards
}