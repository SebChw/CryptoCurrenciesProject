#pragma once

#include <iostream>
#include <map>
#include <vector>
using namespace std;

///Class that stores rate of currencies to be exchanged in the nested map
class CurrencyRatesProvider
{
    map<std::string, map<std::string, float>> exchangeRates;

public:
    void updateRate(string, string, float);
    float getRate(string, string);
    void printRatesOfCurrency(string);
    void generateRatesRandomly(vector<string>);
    void toString();
};