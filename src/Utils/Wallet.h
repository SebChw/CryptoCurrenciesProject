#pragma once

#include <iostream>
#include <map>
#include <stdlib.h>
#include <time.h>

using namespace std;
///Class that represents container for currenciess
template <class T>
class Wallet
{
    map<string, T *> currencies; // I was wondering whether to use Vector, map or unordered map.
    string owner;                // name of the Owner of the wallet

public:
    ///@param a owner of the wallet
    Wallet(string a) : owner(a)
    {
        //At the moment of creating Wallet map currencies will be empty
        srand(time(NULL));
    };
    ~Wallet()
    {
        //Since map contains pointers on the object we need to delete them one by one as we delete Wallet
        for (auto x : currencies)
        {
            delete x.second;
        }
    }
    ///Function printing content of the wallet
    ///@param is_short whether to print all info or only amount
    void toString(bool is_short)
    {
        //We printing either everything about every currency we have in a wallet or just name of currency and it's amount we posses
        for (auto x : currencies)
        {
            if (is_short)
            {
                cout << x.second->getName() << ": " << x.second->getAmountInWallet() << endl;
            }
            else
            {
                x.second->toString();
            }
        }
    };
    ///Function that increases amount of given currency in the wallet
    ///@param currency_name currency available in the wallet for which we want to increase amount
    ///@param amount how much to add to the wallet
    bool addMoney(string currency_name, float amount)
    {
        //I perceive adding money as adding(subtracting) amount of particular chosen currency to our wallet.
        auto it = currencies.find(currency_name);
        if (it != currencies.end())
        {
            *(it->second) += amount;
            return true;
        }
        //!raise exception here instead
        return false; // if adding was unsuccessful, due to missing currency we return false
    }
    ///Function that adds currency object to the wallet, so that wallet contains this currency now
    Wallet &operator+=(T *currency)
    {
        //I assumed that adding coin is just placing our currency in the wallet for the first time
        currencies.emplace(currency->getName(), currency);
        return *this;
    }

    ///Function that removes currency object from the wallet
    Wallet &operator-=(string currency_name)
    {
        //! Again raise exception here if currency is missing
        auto it = currencies.find(currency_name);
        if (it != currencies.end())
        {
            delete it->second;
            currencies.erase(it);
        }
        else
        {
            cout << "You don't have " << currency_name << " in the wallet so you can't remove it!" << endl;
        }
        return *this;
    }
    /// To check whether wallet contains any currencies
    bool isEmpty()
    {
        // To know how many differeny currencies we have in the wallet. It is needed to know when to stop simulation.
        return currencies.size() == 0;
    }

    /// choosing random currency from the wallet
    ///@returns object of the template type
    T *getRandom()
    {
        // Just selecting random currency from the wallet for the simulation
        auto item = currencies.begin();
        advance(item, rand() % (currencies.size()));

        return item->second;
    }

    ///@returns sum of amount of currencies in the wallet
    float sumOfAll()
    {
        // Getting the sum of all currencies we have in wallet used to rankUp users
        float sum = 0;
        for (auto x : currencies)
        {
            sum += x.second->getAmountInWallet();
        }
        return sum;
    }

    T *getCurrency(string name)
    {
        return currencies[name]; // Why I figured this out when I was finishing the project :(
    }
};
