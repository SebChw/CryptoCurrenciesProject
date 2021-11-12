#pragma once
#include "BackedCryptoCurrency.h"
#include "../../Utils/Wallet.h"

//As I wanted to kill two birds with one stone I created template so this Currency can be backed by MameCurrency, FiatCurrency or any other.
template <class T>
class CurrencyBackedCryptoCurrency : public BackedCryptoCurrency
{
    string backingCurrency; // name of backing currency

public:
    CurrencyBackedCryptoCurrency(float amount, string name, int lim, int ass, string curr) : BackedCryptoCurrency(amount, name, lim, ass)
    {
        backingCurrency = curr;
    }

    void toString()
    {
        BackedCryptoCurrency::toString();
        cout << "Currency is backed by: " << backingCurrency << endl;
    }
    void exchange(int){}; // now the deal is that In case of CurrencyBacked I can imitate real exchange in ratio 1:1
    // So I overwritten the abstract class in a dummy way and created yet another function that takes Wallet of the user.
    //And after exchange we decrease amount of the currency on which we used the function and increase the amount of backing currency
    void exchange(int amount, Wallet<T> &w)
    {
        //User can decide how much of currency he wants to exchange it is assumed that deal is in ratio 1:1
        //If user Want's to exchange more than they actually have by default they exchange all they have
        if (amount < this->getAmountInWallet())
        {
            cout << "Unfortunatelly you, don't have enough money, So we will use all you have instead! " << endl;
            amount = this->getAmountInWallet();
        }
        cout << "Hooray you've exchanged " << amount << " of " << getName() << " on " << backingCurrency << "!!" << endl;
        *this -= amount;
        w.addMoney(backingCurrency, amount); // as wallet is a map we can't as easily add to it withouth checking whether such currency
        //exists in it.
    }
};