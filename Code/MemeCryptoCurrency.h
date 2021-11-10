#pragma once
#include "CryptoCurrency.h"

class MemeCryptoCurrency : public CryptoCurrency
{
    string memeName; // name of the meme in whose honor the Crypto was named

public:
    MemeCryptoCurrency(float, string, int, string);
    void toString();
    void mine(int); // we need to define this to be able to create object of that class
};