#include "in_memory_repository.h"

#include <ctime>
#include <random>
#include <climits>
#include <algorithm>
#include <iostream>

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
    std::string id = this->RandomID();
    while (this->IsGameExist(id)) 
        id = this->RandomID();
    game->set_game_id(id);
    games_.insert({id, std::move(game)});
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

std::string InMemoryRepository::RandomID()
{
    std::uniform_int_distribution<int> u(0, INT_MAX);
    std::default_random_engine e(time(0));
    std::string id = std::to_string(u(e));
    return id;
}