#include "MemeCryptoCurrency.h"

///@param amount Amount of a currency that user posses
///@param name Name of the currency
///@param needed How much work is needed to mine that crypto
///@param memeN - Name of the meme based on which currency emerged
MemeCryptoCurrency::MemeCryptoCurrency(float amount, string name, int work, string memeN) : CryptoCurrency(amount, name, work)
{
    memeName = memeN;
}

void MemeCryptoCurrency::toString()
{
    CryptoCurrency::toString();
    cout << "meme name: " << memeName << endl;
}

void MemeCryptoCurrency::mine(int rank = 0)
{
    //We can mine Meme CryptoCurrencies with no restrictions
    //If we mined a crypto, performWork returns true we can increase amountInWallet and print message
    if (performWork())
    {
        cout << getName() << " has been mined! You probably should find another hobby!" << endl;
        *this += 1;
    }
    else
    {
        cout << "Not yet! must mine " << howMuchWork() << " more" << endl;
    }
}