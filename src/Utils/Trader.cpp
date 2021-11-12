#include "Trader.h"

///@param n name of the trader
Trader::Trader(string n) : name(n)
{
    // these parameters are default for every trader
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
///Print information about trader
///@param is_short whether to print all information about possesed currencies or just their amounts
void Trader::toString(bool is_short)
{
    cout << "Name: " << name << "   Rank:" << rank << "   Next goal: " << goal << endl;
    cout << "Fiat Currencies: " << endl;
    fiatWallet->toString(is_short);
    cout << endl
         << "Crypto Currencies: " << endl;
    cryptoWallet->toString(is_short);
}

///Function adding some currency to the wallet of realMoney
bool Trader::addRealMoney(Currency *money)
{
    *fiatWallet += money;
    return 1;
}
///Function adding some currency to the wallet of cryptoMoney
bool Trader::addCrypto(Currency *money)
{
    *cryptoWallet += money;
    return 1;
}
///Function that checks whether user has enough cryptoCurrencies to be rankedUp
void Trader::rankUp()
{
    if (cryptoWallet->sumOfAll() >= goal)
    {
        cout << "Congratulations you ranked up!" << endl;
        rank += 1;
        goal *= 10;
    }
}
///Functon that check whether user has enough CryptoCurrencies to be ranked down
void Trader::rankDown()
{
    if (rank > 0 && cryptoWallet->sumOfAll() < goal / 10)
    {
        cout << "What a pitty your balance of crypto's is below previous goal. You rank decreases" << endl;
        rank -= 1;
        goal /= 10;
    }
}
///@returns rank rank of the trader
int Trader::getRank()
{
    return rank;
}