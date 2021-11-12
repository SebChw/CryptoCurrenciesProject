#pragma once

#include "../Currencies/CryptoCurrencies/MemeCryptoCurrency.h" //! <> then compiler will search in predefined folders with "" it search in the same directory at first!!
#include "../Currencies/CryptoCurrencies/NotBackedCryptoCurrency.h"
#include "../Currencies/CryptoCurrencies/CurrencyBackedCryptoCurrency.h"
#include "../Currencies/CryptoCurrencies/CommodityBackedCryptoCurrency.h"
#include "../Currencies/FiatCurrency.h"
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