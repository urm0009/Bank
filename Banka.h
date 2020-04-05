#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "Account.h"
using namespace std;

class Banka
{
private:
	Client** clients;
	int clientCount;

	Account** accounts;
	int accountsCount;

public:
	Banka(int clientCount, int accountsCount);
	~Banka();
	Client* GetClient(int c);
	Account*GetAccount(int a);

	Client* CreateClient(int c, string n);
	Account* CreateAccount(int n, Client* c);
	Account* CreateAccount(int n, Client* c, double interest);
	Account* CreateAccount(int n, Client* c, Client *partner);
	Account* CreateAccount(int n, Client* c, Client *partner, double interest);

	void AddInterest(int);

};

