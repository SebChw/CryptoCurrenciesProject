#include "Currency.h"

Currency::Currency(float a, string b)
{
    amountInWallet = a;
    name = b;
}
void Currency::toString()
{
    cout << endl
         << "Name: " << name << endl;
    cout << "Amount in wallet: " << round(amountInWallet * 100) / 100 << endl;
}

Currency &Currency::operator+=(float amount)
{
    this->amountInWallet += amount; //Increase the amountInWallet of the class on which we used the += operator
    return *this;                   // We return alias of the class on which we used += operator
}

Currency &Currency::operator-=(float amount)
{
    this->amountInWallet -= amount;
    return *this;
}

string Currency::getName() const
{
    return this->name;
}

float Currency::getAmountInWallet() const
{
    return this->amountInWallet;
}