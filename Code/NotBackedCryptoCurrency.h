#pragma once

#include "CryptoCurrency.h"

class NotBackedCryptoCurrency : public CryptoCurrency
{
    string algorithm; // Algorithm that keeps the currency stable

public:
    NotBackedCryptoCurrency(int, string, int, string);
    void toString();
    void mine(int); // we need to define this to be able to create object of that class
};