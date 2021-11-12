#include "CommodityBackedCryptoCurrency.h"
///@param amount Amount of a currency that user posses
///@param name Name of the currency
///@param needed How much work is needed to mine that crypto
///@param ass By how big asset currency is backed
///@param com Comodity backing currency
CommodityBackedCryptoCurrency::CommodityBackedCryptoCurrency(float amount, string name, int needed, int ass, string com) : BackedCryptoCurrency(amount, name, needed, ass)
{
    commodityType = com;
}

void CommodityBackedCryptoCurrency::toString()
{
    BackedCryptoCurrency::toString();
    cout << "Currency is backed by: " << commodityType << endl;
}

void CommodityBackedCryptoCurrency::exchange(int amount)
{
    //User can decide how much of currency he wants to exchange it is assumed that deal is in ratio 1:1
    //If user Want's to exchange more than they actually have by default they exchange all they have
    if (amount > this->getAmountInWallet())
    {
        cout << "Unfortunatelly you, don't have enough money, So we will use all you have instead! " << endl;
        amount = this->getAmountInWallet();
    }
    cout << "Hooray you've exchanged " << amount << " of " << getName() << " on " << commodityType << "!!" << endl;
    *this -= amount; // After this function user loses amount he exchanged, and gains commodity which is not represented here.
}