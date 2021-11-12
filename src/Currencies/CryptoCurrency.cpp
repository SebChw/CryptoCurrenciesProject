#include "CryptoCurrency.h"

///@param amount Amount of a currency that user posses
///@param name Name of the currency
///@param needed How much work is needed to mine that crypto
CryptoCurrency::CryptoCurrency(float amount, string name, int needed) : Currency(amount, name)
{
    workNeededToGetCrypto = needed;
    workDone = 0;
}

void CryptoCurrency::toString()
{
    Currency::toString();
    cout << "Work left to get one coin: " << workNeededToGetCrypto - workDone << endl; // So that user knows how much he needs to do more
}
/// Performs one unit of work and check if we already mined crypto
///@returns boolean whether the crypto was mined or not
bool CryptoCurrency::performWork()
{
    // We use this method in mine() method of inherithing classes. Here we can withouth a problem change values of private variables
    workDone += 1;
    if (workNeededToGetCrypto == workDone)
    {
        workDone = 0; // if we do enough work we start from the beginning
        return true;  // we return boolean so class that called this method can react appropriately
    }
    return false;
}

/// calculate how much work needs to be done to mine cryptoCurrency
///@returns how much more work is needed to mine given cryptocurrency
int CryptoCurrency::howMuchWork()
{
    return workNeededToGetCrypto - workDone;
}

//Definition of the abstract function from Currency class.
///Prints information that it is not possible to generate CryptoCurrencies
void CryptoCurrency::generateCurrency()
{
    cout << "Not possible to generate more CryptoCurrency!" << endl;
}