#include "CurrencyRatesProvider.h"

void CurrencyRatesProvider::updateRate(string changed, string obtained, float rate)
{
    map<string, map<string, float>>::iterator it = exchangeRates.find(changed); //That's why I love auto keyword
    if (it == exchangeRates.end())
    {
        exchangeRates.emplace(make_pair(changed, map<string, float>()));
        it = exchangeRates.find(changed);
    }
    it->second.emplace(make_pair(obtained, rate));

    it = exchangeRates.find(obtained);
    if (it == exchangeRates.end())
    {
        exchangeRates.emplace(make_pair(obtained, map<string, float>()));
        it = exchangeRates.find(obtained);
    }
    it->second.emplace(make_pair(changed, 1 / rate));
}

void CurrencyRatesProvider::printRatesOfCurrency(string currency_name)
{
    map<string, map<string, float>>::iterator it = exchangeRates.find(currency_name); //That's why I love auto keyword
    if (it != exchangeRates.end())
    {
        cout << currency_name << ":" << endl;
        for (auto &pair : it->second)
        {
            cout << "   " << pair.first << ": " << pair.second << endl;
        }
    }
    else
        cout << "We don't have information about " << currency_name << " currency!" << endl;
}

float CurrencyRatesProvider::getRate(string of_what, string to_what){
    map<string, map<string, float>>::iterator base_curr = exchangeRates.find(of_what);
    if (base_curr != exchangeRates.end())
    {
        auto wanted_curr = base_curr->second.find(to_what);
        if (wanted_curr != base_curr->second.end())
        {
            float rate = wanted_curr->second;
            return rate;
        }
        else
        {
            cout << "You can't obtain " << to_what << " Here!" << endl;
            return -1;
            //raise::
        }
    }
    else
    {
        cout << "You can't exchange " << of_what << " Here!" << endl;
        return -1;
        //raise::
    }
}

void CurrencyRatesProvider::generateRatesRandomly(vector<string> names){
    for (vector<int>::size_type i = 0; i != names.size(); i++)
    {
        for (vector<int>::size_type j = i+1; j != names.size(); j++)
        {
            updateRate(names[i], names[j], (float)(rand()% 10 + 1) / (float)(rand()%2 + 1));
        }
        
    }
}

void CurrencyRatesProvider::toString(){
    for (auto &pair: exchangeRates){
        printRatesOfCurrency(pair.first);
    }
}