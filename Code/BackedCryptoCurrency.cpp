#include "BackedCryptoCurrency.h"

BackedCryptoCurrency::BackedCryptoCurrency(float amount, string name, int lim, int ass) : CryptoCurrency(amount, name, lim)
{
    asset = ass;
}

void BackedCryptoCurrency::toString()
{
    CryptoCurrency::toString();
    cout << "Currency is backed by asset equal to: " << asset << "$" << endl;
}

void BackedCryptoCurrency::mine(int rank)
{
    //We can mine Backed CryptoCurrencies only if we have rank higher than 4
    if (rank > 4)
    {
        //If we finally sucedded we increase amount of that currency
        if (performWork())
        {
            cout << getName() << " has been mined! congratulations!" << endl;
            *this += 1;
        }
        else
        {
            cout << "Cmon! still " << howMuchWork() << "work needs to be done!" << endl;
        }
    }
    else
        cout << "You must have rank 5 or higher to mine BackedCryptoCurrencies!" << endl;
}