#include <iostream>
#include <math.h>
#pragma once
using namespace std;

class Currency
{
    //Root class of the hierarchy of different Currencies

    float amountInWallet; // amount of currency that belongs to some user
    string name;          // name of the currency

public:
    Currency(float, string);
    virtual void toString();
    string getName() const; // I created those getters as in a lot of situations I need either amount or name attributes
    float getAmountInWallet() const;
    Currency &operator+=(float amount); // using  these operators one can increase or decrease amountInWallet attribute
    Currency &operator-=(float amount);

    virtual void generateCurrency() = 0; // This function is not used (of course in generall it could be )
    //it is just created to ensure abstractness
};