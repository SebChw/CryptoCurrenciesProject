#pragma once

#include "Wallet.h"
#include "../Currencies/CryptoCurrency.h"
#include "../Currencies/FiatCurrency.h"
#include "CurrencyExchange.h"

///Class representing user of our crypto currency system
class Trader
{
    string name;
    int rank;                     // this indicates our rank based on which we are able to do different stuff
    int goal;                     //This indicate the goal to be ranked up!
    Wallet<Currency> *fiatWallet; // I decided that trader basically has one wallet of crypto and another of Fiat Currencies
    Wallet<Currency> *cryptoWallet;

    void rankUp();   // This function is used internally only so no need to make it public
    void rankDown(); //! For security reasons I think this should be private
public:
    Trader(string);
    ~Trader();
    void toString(bool);
    bool addRealMoney(Currency *); // We can't access wallet outside of trader so we need function to add some currencies
    bool addCrypto(Currency *);    //buy using what, buy what, buy how much?
    friend class CurrencyExchange;
    int getRank();
    //friend void CurrencyExchange::trade(Trader &trader);
};