#include "FiatCurrency.h"
///@param amount Amount of a currency that user posses
///@param name Name of the currency
///@param isBacked whether the currency is backed by gold or not
FiatCurrency::FiatCurrency(float amount, string name, bool isBacked) : Currency(amount, name), backedByGold(isBacked) {}

void FiatCurrency::toString()
{
    Currency::toString();
    cout << "Backed by gold: " << boolalpha << backedByGold << endl;
}

///To Generate more Currency the main bank will just print it
void FiatCurrency::generateCurrency()
{
    cout << "NBP is printing more " << this->getName();
}