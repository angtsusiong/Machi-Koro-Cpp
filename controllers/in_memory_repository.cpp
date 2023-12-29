#include "in_memory_repository.h"

#include <ctime>
#include <random>
#include <climits>
#include <algorithm>
#include <iostream>
#include <drogon/utils/Utilities.h>

InMemoryRepository::~InMemoryRepository()
{
}

InMemoryRepository& InMemoryRepository::self()
{
    static InMemoryRepository repo;
    return repo;
}

void InMemoryRepository::AddGame(std::shared_ptr<MachiKoroGame> game)
{
    games_.insert({game->get_game_id(), std::move(game)});
}

void InMemoryRepository::SaveGame(std::shared_ptr<MachiKoroGame> game)
{
    return;
}

std::shared_ptr<MachiKoroGame> InMemoryRepository::FindGameByID(const std::string& id)
{
    if (!this->IsGameExist(id)) return nullptr;
    return games_[id];
}

void InMemoryRepository::ClearAllGames()
{
    games_.clear();
}

bool InMemoryRepository::IsGameExist(const std::string& id)
{
    if (auto gamePtr = games_.find(id); gamePtr != games_.end()) {
        if (gamePtr->second == nullptr) {
            games_.erase(id);
            return false;
        }
        return true;
    }
    return false;
}
