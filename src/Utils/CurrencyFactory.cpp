#include "CurrencyFactory.h"

string CurrencyFactory::memeNames[3] = {"Doge", "SOLID", "Trololo"};
string CurrencyFactory::cryptoNames[5] = {"BitCoin", "Etherum", "Solana", "Cardano", "Tether"};
string CurrencyFactory::fiatNames[5] = {"zloty", "dolar", "kuna", "euro", "yen"};
string CurrencyFactory::algorithmNames[3] = {"GCD", "BubbleSort", "BogoSort"};
string CurrencyFactory::commodityNames[3] = {"Cows", "coal", "aluminium"};

///In here we just set the random seed
CurrencyFactory::CurrencyFactory()
{
    srand(time(NULL));
}

///Function generating random fiat Currency with all attributes set to random values
///and appending its name to the vector of all currencies generated
Currency *CurrencyFactory::generateFiatCurrency()
{
    int selected = rand() % sizeof(fiatNames) / sizeof(fiatNames[0]);
    Currency *fiat = new FiatCurrency(0, fiatNames[selected], rand() % 2);
    createdCurrenciesNames.push_back(fiatNames[selected]);
    fiatNames[selected] += "_"; // To always have unique names

    return &(*fiat += (rand() % 25 + 1)); //! Really sorry for setting amount this way but I had to use this...
}
///Function generating random crypto Currency with all attributes set to random values
///and appending its name to the vector of all currencies generated
Currency *CurrencyFactory::generateCryptoCurrency()
{
    int selected_type = rand() % 5;
    Currency *crypto;
    //At first I used Case statement, but I am so used to Python that I preffered if eventually
    if (selected_type == 0)
    {
        int selected_name = rand() % sizeof(memeNames) / sizeof(memeNames[0]);
        crypto = new MemeCryptoCurrency(0, memeNames[selected_name] + "Coin", rand() % 20, memeNames[selected_name]);
        createdCurrenciesNames.push_back(memeNames[selected_name] + "Coin");
        memeNames[selected_name] += "_";
    }
    else if (selected_type == 1)
    {
        int selected_name = rand() % sizeof(algorithmNames) / sizeof(algorithmNames[0]);
        crypto = new NotBackedCryptoCurrency(0, algorithmNames[selected_name] + "Coin", rand() % 30, algorithmNames[selected_name]);
        createdCurrenciesNames.push_back(algorithmNames[selected_name] + "Coin");
        algorithmNames[selected_name] += "_";
    }
    else if (selected_type == 2)
    {
        int selected_name = rand() % sizeof(commodityNames) / sizeof(commodityNames[0]);
        crypto = new CommodityBackedCryptoCurrency(0, commodityNames[selected_name] + "Coin", rand() % 30, rand() % 10000, commodityNames[selected_name]);
        createdCurrenciesNames.push_back(commodityNames[selected_name] + "Coin");
        commodityNames[selected_name] += "_";
    }
    else if (selected_type == 3)
    {
        int selected_name = rand() % sizeof(cryptoNames) / sizeof(cryptoNames[0]);
        crypto = new CurrencyBackedCryptoCurrency<CryptoCurrency>(0, cryptoNames[selected_name], rand() % 30, rand() % 10000, commodityNames[selected_name]);
        createdCurrenciesNames.push_back(cryptoNames[selected_name]);
        cryptoNames[selected_name] += "_";
    }
    else
    {
        int selected_name = rand() % sizeof(cryptoNames) / sizeof(cryptoNames[0]);
        crypto = new CurrencyBackedCryptoCurrency<FiatCurrency>(0, cryptoNames[selected_name], rand() % 30, rand() % 10000, fiatNames[selected_name]);
        createdCurrenciesNames.push_back(cryptoNames[selected_name]);
        cryptoNames[selected_name] += "_";
    }

    return &(*crypto += (rand() % 25 + 1)); //! Really sorry for setting amount this way but I had to use this...
}
///@returns vector with names of all generated cryptoCurrencies
vector<string> CurrencyFactory::getCreatedCurrenciesNames()
{
    return createdCurrenciesNames;
}