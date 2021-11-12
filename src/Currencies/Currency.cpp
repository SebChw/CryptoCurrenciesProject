#include "Currency.h"

///@param amnt Amount of a currency that user posses
///@param currName Name of the currency
Currency::Currency(float amnt, string currName)
{
    if (amnt < 0)
    {
        throw domain_error("Currency::Currency: Can't create currency with negative amountInWallet!");
    }
    amountInWallet = amnt;
    name = currName;
}
///prints values of all parameters set inside the object
void Currency::toString()
{
    cout << endl
         << "Name: " << name << endl;
    cout << "Amount in wallet: " << round(amountInWallet * 100) / 100 << endl;
}
///Used to increase amount of possesed currency
///@param amount Amount by which we want to increase possesed value
///@returns Object on which performed operation
Currency &Currency::operator+=(float amount)
{
    this->amountInWallet += amount; //Increase the amountInWallet of the class on which we used the += operator
    return *this;                   // We return alias of the class on which we used += operator
}
///Used to decrease amount of possesed currency
///@param amount Amount by which we want to decrease possesed value
///@returns Object on which performed operation
Currency &Currency::operator-=(float amount)
{
    //This part may get trickier when amount is equal to amountInWallet and they could differ by some small amounts.
    //I solved it that way bur probably should be done much better
    if ((this->amountInWallet + 0.000001) < amount)
    {
        throw std::invalid_argument("Currency::operator-=: After this operation amountInWallet would be below zero!");
    }
    this->amountInWallet -= amount;
    return *this;
}

///@returns Name of the considered currency object
string Currency::getName() const
{
    return this->name;
}
///@returns amount of the considered currency object
float Currency::getAmountInWallet() const
{
    return this->amountInWallet;
}