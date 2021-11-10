#pragma once

#include "MemeCryptoCurrency.h" //! <> then compiler will search in predefined folders with "" it search in the same directory at first!!
#include "NotBackedCryptoCurrency.h"
#include "CurrencyBackedCryptoCurrency.h"
#include "CommodityBackedCryptoCurrency.h"
#include "FiatCurrency.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
class CurrencyFactory
{
    static string memeNames[3];
    static string cryptoNames[5];
    static string fiatNames[5];
    static string algorithmNames[3];
    static string commodityNames[3];
    vector<string> createdCurrenciesNames;

public:
    CurrencyFactory();
    Currency *generateFiatCurrency();
    Currency *generateCryptoCurrency();
    vector<string> getCreatedCurrenciesNames();
};