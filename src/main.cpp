#include "Utils/Wallet.h"
#include "Utils/CurrencyExchange.h"
#include "Utils/CurrencyRatesProvider.h"
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
        //I wondered whether to catch that error here or in generatingCryptoCurrency function
        //But if I did it there then program will break, and we basically can just omit one currency in simulation
        //I do not catch other errors here as I'm sure that all values are generated from some predefined values that
        //are for sure valid, so only allocation can go wrong.
        try
        {
            trader.addRealMoney(currencyFactory.generateFiatCurrency());
        }
        catch (bad_alloc &e)
        {
            cout << "Allocation error during creating Currency! We will add one currency less" << endl;
            continue;
        }
    }
    cout << "How many random crypto currencies you want to generate?: ";
    cin >> how_many;
    for (size_t i = 0; i < how_many; i++)
    {
        try
        {
            trader.addCrypto(currencyFactory.generateCryptoCurrency());
        }
        catch (bad_alloc &e)
        {
            cout << "Allocation error during creating Currency! We will add one currency less" << endl;
            continue;
        }
    }

    CurrencyRatesProvider currencyRatesProvider;
    currencyRatesProvider.generateRatesRandomly(currencyFactory.getCreatedCurrenciesNames());

    cout << "Do you want to print all Rates? (y/n): ";
    cin >> decision;
    if (decision == "y")
    {
        currencyRatesProvider.toString();
    }

    float pSell;
    cout << "Define pSell (0.0-1.0): ";
    cin >> pSell;
    CurrencyExchange MarketPlace(pSell, &currencyRatesProvider);
    MarketPlace.toString();

    cout << "Do you want to print all information about trader? (y/n): ";
    cin >> decision;
    if (decision == "y")
    {
        trader.toString(false);
    }

    cout << "Type anything to start: ";
    cin >> decision;
    MarketPlace.trade(trader);

    cout << "Do you want to see extra features? (y/n): ";
    cin >> decision;
    if (decision == "y")
    {
        MarketPlace.simulateRanking();
        MarketPlace.simulateMining();
        MarketPlace.simulateBackedCurrencies();
    }
    cout << "Do you want to see exceptions that are trown? (y/n): ";
    cin >> decision;
    if (decision == "y")
    {
        // As The program is mainly about exchanging money I decided to create exceptions in places
        // where if we do not throw exception program will be working but logic will be wrong.
        cout << "As we want to get Rate of currency that is not define exception is thrown" << endl;
        try
        {
            currencyRatesProvider.getRate("NotExistingCurr1", "NotExistingCurr2");
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl
                 << endl;
        }
        cout << "Exchange rate can not be negative!" << endl;
        try
        {
            currencyRatesProvider.updateRate("curr1", "curr2", -0.5);
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl
                 << endl;
        }
        cout << "If one tries to subtract from Currency more than we have, exception is thrown" << endl;
        try
        {
            FiatCurrency curr1(5, "zloty", true);
            curr1 -= 20;
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl
                 << endl;
        }
        cout << "If one tries to Create Currency with negative amount, exception is thrown" << endl;
        try
        {
            FiatCurrency curr1(-20, "zloty", true);
        }
        catch (domain_error &e)
        {
            cout << e.what() << endl
                 << endl;
        }
    }

    return 0;
}