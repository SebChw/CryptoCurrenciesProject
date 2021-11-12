#pragma once
#include "Currency.h"

///Parent class for all CryptoCurrencies
class CryptoCurrency : public Currency
{
    int workNeededToGetCrypto; // How much work is needed to get one coin of that crypto
    int workDone;              // how much work we did to "mine" one coin

public:
    CryptoCurrency(float, string, int);
    void toString();
    void generateCurrency(); //All of functions below could be usefull if we would like to extend functonalities of our system
    bool performWork();      // This basically is used to change workDone  and workNeededToGetCrypto parameters,
    //this function is used by inheriting classes so that workNeededToGetCrypto and workDone still can be private
    // ! This function returns bool as different sub classes my react differently when crypto has been mined
    ///Function that check whether we can mine, if yes it performs unit of work and if we mined increase amount of currency
    ///@param rank integer which rank we need to be able to mine given crypto
    virtual void mine(int rank) = 0; // Each type of cryptoCurrency may have different way of mining.
    //int is rank of the user. In our service you can mine different crypto's depending on your rank.
    int howMuchWork();
};