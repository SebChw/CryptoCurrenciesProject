#pragma once
#include "../CryptoCurrency.h"

class BackedCryptoCurrency : public CryptoCurrency
{
    int asset; // asset is like how strongly currency is Backed

public:
    BackedCryptoCurrency(float, string, int, int);
    void toString();
    void mine(int);                 // we need to define this to be able to create object of that class
    virtual void exchange(int) = 0; //yet another abstract function needed as Crypto that is backed with dolars will behave differently
    //Than crypto that is backed in cows etc.
};