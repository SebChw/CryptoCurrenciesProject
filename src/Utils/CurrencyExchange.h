#pragma once

#include "CurrencyRatesProvider.h"
#include "CurrencyFactory.h"
#include "Trader.h"
#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <thread>
#include <chrono>
#include <math.h>
using namespace std;

class Trader;
///Class imitating some MarketPlace where we can exchange money and gamble
class CurrencyExchange
{
    map<string, map<string, float>> exchangeRates;
    float pSell;
    float pBuy;
    default_random_engine generator;
    bernoulli_distribution bernoulli;
    uniform_real_distribution<float> uniform;
    CurrencyRatesProvider *currencyRatesProvider;

public:
    CurrencyExchange(float, CurrencyRatesProvider *);
    void toString();
    float calculate(float, string, string);
    void exchange(Currency *, Currency *, Wallet<Currency> *);
    void trade(Trader &);
    void simulateRanking();
    void simulateMining();
    void simulateBackedCurrencies();
};