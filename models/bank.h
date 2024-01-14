#pragma once

#include "player.h"

class Bank {
public:
    Bank();
    Bank(const Bank& bank);
    Bank(Bank&& bank);
    ~Bank();

    Bank& operator = (const Bank& rhs);
    Bank& operator = (Bank&& rhs);

    void PayCoin2Player(int coin, std::shared_ptr<Player> player);

    int get_coin() const { return coin_; } 
    
private:
    int coin_ = 282;
};