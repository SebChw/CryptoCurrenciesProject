#pragma once

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class CurrencyRatesProvider {
    map<std::string, map<std::string, float>> exchangeRates;

public:
    void updateRate(string, string, float);
    float getRate(string,string);
    void printRatesOfCurrency(string);
    void generateRatesRandomly(vector<string>);
    void toString();
};