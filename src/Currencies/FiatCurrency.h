#pragma once
#include "Currency.h"

///Leaf class for Fiat currencies
class FiatCurrency : public Currency
{
    bool backedByGold; // Probably nowadays there is no Fiat Currency backedByGold but, there might be.

public:
    FiatCurrency(float, string, bool);
    virtual void toString();
    void generateCurrency(); // We need to define this function so that we can create object of this class
};