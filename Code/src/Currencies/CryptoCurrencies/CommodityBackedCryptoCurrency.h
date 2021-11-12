#pragma once

#include "BackedCryptoCurrency.h"

class CommodityBackedCryptoCurrency : public BackedCryptoCurrency
{
    string commodityType; // this can be any good different than money (grain, coal, cows etc.)

public:
    CommodityBackedCryptoCurrency(float, string, int, int, string);
    void toString();
    void exchange(int); // we need to implement abstract function, to be able to create that object
    //And to be able exchange our currency to it's backing asset
};