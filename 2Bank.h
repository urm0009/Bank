#pragma once
#include "Account.h"
using namespace std;

class Bank
{
private:
	Client** clients;
	int clientCount;

	Account** accounts;
	int accountCount;

public:
	Bank(int clientCount, int accountsCount);
	~Bank();
	Client* GetClient(int c);
	Account* GetAccount(int a);

	Client* CreateClient(int c, string n);
	Account* CreateAccount(int n, Client* c);
	Account* CreateAccount(int n, Client* c, double interest);
	Account* CreateAccount(int n, Client* c, Client* partner);
	Account* CreateAccount(int n, Client* c, Client* partner, double interest);

	void AddInterest();
};

