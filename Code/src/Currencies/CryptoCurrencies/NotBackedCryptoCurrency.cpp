#include "NotBackedCryptoCurrency.h"

NotBackedCryptoCurrency::NotBackedCryptoCurrency(int amount, string name, int work, string alg) : CryptoCurrency(amount, name, work)
{
    algorithm = alg;
}

void NotBackedCryptoCurrency::toString()
{
    CryptoCurrency::toString();
    cout << "algorithm keeping rate stable: " << algorithm << endl;
}

void NotBackedCryptoCurrency::mine(int rank)
{
    //We can mine NotBackedCryptoCurrencies only if we are above rank 2
    if (rank > 2)
    {
        //If we finally done enough amount of work
        if (performWork())
        {
            cout << getName() << " has been mined! Well done!" << endl;
            *this += 1;
        }
        else
        {
            cout << howMuchWork() << " more work to be done!" << endl;
        }
    }
    else
        cout << "You must have rank 3 to mine NotBackedCryptoCurrencies!" << endl;
}