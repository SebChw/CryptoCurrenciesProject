#include "Wallet.h"
#include "CurrencyExchange.h"
#include "CurrencyRatesProvider.h"
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string decision;
    CurrencyFactory currencyFactory;

    string name;
    cout << "What's the name of your trader?: ";
    cin >> name;
    Trader trader(name);

    size_t how_many;
    cout << "How many random fiat currencies you want to generate?: ";
    cin >> how_many;
    for (size_t i = 0; i < how_many; i++)
    {
        trader.addRealMoney(currencyFactory.generateFiatCurrency());
    }
    cout << "How many random crypto currencies you want to generate?: ";
    cin >> how_many;
    for (size_t i = 0; i < how_many; i++)
    {
        trader.addCrypto(currencyFactory.generateCryptoCurrency());
    }

    CurrencyRatesProvider currencyRatesProvider;
    currencyRatesProvider.generateRatesRandomly(currencyFactory.getCreatedCurrenciesNames());

    cout << "Do you want to print all Rates? (y/n): ";
    cin >> decision;
    if (decision == "y"){
        currencyRatesProvider.toString();
    }

    float pSell;
    cout << "Define pSell (0.0-1.0): ";
    cin >> pSell;
    CurrencyExchange MarketPlace(pSell, &currencyRatesProvider);
    MarketPlace.toString();

    cout << "Do you want to print all information about trader? (y/n): ";
    cin >> decision;
    if (decision == "y"){
        trader.toString(false);
    }
    
    cout << "Type anything to start: ";
    cin >> decision;
    MarketPlace.trade(trader);

    cout << "Do you want to see extra features? (y/n): ";
    cin >> decision;
    if (decision == "y"){
        MarketPlace.simulateRanking();
        MarketPlace.simulateMining();  
        MarketPlace.simulateBackedCurrencies();
    } 

    return 0;
}