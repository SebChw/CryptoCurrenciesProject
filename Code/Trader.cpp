#include "Trader.h"

Trader::Trader(string n) : name(n)
{
    fiatWallet = new Wallet<Currency>(n);
    cryptoWallet = new Wallet<Currency>(n);
    rank = 0;
    goal = 100;
}
Trader::~Trader()
{
    delete fiatWallet;
    delete cryptoWallet;
}
void Trader::toString(bool is_short)
{
    cout << "Name: " << name << "   Rank:" << rank << "   Next goal: " << goal << endl;
    cout << "Fiat Currencies: " << endl;
    fiatWallet->toString(is_short);
    cout << endl
         << "Crypto Currencies: " << endl;
    cryptoWallet->toString(is_short);
}

bool Trader::addRealMoney(Currency *money)
{
    *fiatWallet += money;
    return 1;
}

bool Trader::addCrypto(Currency *money)
{
    *cryptoWallet += money;
    return 1;
}

void Trader::rankUp()
{
    if (cryptoWallet->sumOfAll() >= goal)
    {
        cout << "Congratulations you ranked up!" << endl;
        rank += 1;
        goal *= 10;
    }
}

void Trader::rankDown(){
    if (rank > 0 && cryptoWallet->sumOfAll() < goal/10)
    {
        cout << "What a pitty your balance of crypto's is below previous goal. You rank decreases" << endl;
        rank -= 1;
        goal /= 10;
    }
}

int Trader::getRank(){
    return rank;
}