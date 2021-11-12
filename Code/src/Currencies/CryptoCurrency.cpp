#include "CryptoCurrency.h"

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

int CryptoCurrency::howMuchWork()
{
    return workNeededToGetCrypto - workDone;
}

//Definition of the abstract function from Currency class.
//Basically all CryptoCurenncies has limit so it is not possible to just generate them
void CryptoCurrency::generateCurrency()
{
    cout << "Not possible to generate more CryptoCurrency!" << endl;
}