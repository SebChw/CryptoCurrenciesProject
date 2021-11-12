#pragma once
#include "../CryptoCurrency.h"

///Parent class for all backed CryptoCurrencies
class BackedCryptoCurrency : public CryptoCurrency
{
    int asset; // asset is like how strongly currency is Backed

public:
    BackedCryptoCurrency(float, string, int, int);
    void toString();
    void mine(int); // we need to define this to be able to create object of that class
    ///Function that exchanges some amount we have to the same amount of good that is backing the currency
    ///@param amount how much of the currency wa want to exchange
    virtual void exchange(int) = 0; //yet another abstract function needed as Crypto that is backed with dolars will behave differently
    //Than crypto that is backed in cows etc.
};