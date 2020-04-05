#include "Banka.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

Banka::Banka(int client, int account)
{
	clientCount = client;
	clients = (Client**)::operator new(client * sizeof(Client*));
	for (int i = 0; i < client; i++)
		clients[i] = (Client*)::operator new(sizeof(Client));

	accountsCount = account;
	accounts = (Account**)::operator new(account * sizeof(Account*));
	for (int j = 0; j < account; j++)
		accounts[j] = (Account*)::operator new(sizeof(Account));
}

Banka::~Banka()
{
	/*for (int i = 0; i < (accountsCount/2); i++)
	{
		delete clients[i];
		delete accounts[i];
	}*/
}

Client* Banka::GetClient(int c)
{
	Client* client;
	if (c == clients[c]->GetCode())
		client = clients[c];
	else client = clients[NULL];
	return client;
}

Account* Banka::GetAccount(int a)
{
	Account* account;
	if (a == accounts[a]->GetAccountNumber())
		account = accounts[a];
	else account = accounts[NULL];
	return account;
}

Client* Banka::CreateClient(int c, string n)
{
	Client* client = new Client(c, n);
	clients[c] = client;
	return client;
}

Account* Banka::CreateAccount(int n, Client* c)
{
	Account* account = new Account(n, c);
	accounts[n] = account;
	return account;
}

Account* Banka::CreateAccount(int n, Client* c, double ir)
{
	Account* account = new Account(n, c, ir);
	accounts[n] = account;
	return account;
}

Account* Banka::CreateAccount(int n, Client* c, Client* p)
{
	Account* account = new Account(n, c, p);
	accounts[n] = account;
	return account;
}

Account* Banka::CreateAccount(int n, Client* c, Client* p, double ir)
{
	Account* account = new Account(n, c, p, ir);
	accounts[n] = account;
	return account;
}

void Banka::AddInterest(int accNum)
{
	if (accounts[accNum]->GetInterest() > 0)
		accounts[accNum]->AddInterest();
}