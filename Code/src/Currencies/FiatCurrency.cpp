#include "FiatCurrency.h"

FiatCurrency::FiatCurrency(float amount, string name, bool isBacked) : Currency(amount, name), backedByGold(isBacked) {}

void FiatCurrency::toString()
{
    Currency::toString();
    cout << "Backed by gold: " << boolalpha << backedByGold << endl;
}

//To Generate more Currency the main bank can just print it
void FiatCurrency::generateCurrency()
{
    cout << "NBP is printing more " << this->getName();
}