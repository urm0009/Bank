#include "Bank.h"

Bank::Bank(int maxClients, int maxAccounts)
{
	/*clientCount = maxClients;
	clients = (Client**)::operator new(maxClients * sizeof(Client*));
	for (int i = 0; i < maxClients; i++)
		clients[i] = (Client*)::operator new(sizeof(Client));

	accountCount = maxAccounts;
	accounts = (Account**)::operator new(maxAccounts * sizeof(Account*));
	for (int j = 0; j < maxAccounts; j++)
		accounts[j] = (Account*)::operator new(sizeof(Account));*/
	this->clients = new Client * [maxClients];
	clientCount = 0;
	this->accounts = new Account * [maxAccounts];
	accountCount = 0;
}
Bank::~Bank()
{
	for (int i = 0; i < this->clientCount; i++)
	{
		delete this->clients[i];
	}
	for (int j = 0; j < this->accountCount; j++)
	{
		delete this->accounts[j];
	}
}
Client* Bank::GetClient(int c)
{
	/*for (int i = 0; i < this->clientCount; i++)
	{*/
		if (clients[c]->GetCode() == c)
		{
			return this->clients[c];
		}
	
	return nullptr;
}
Account* Bank::GetAccount(int a)
{
	/*for (int i = 0; i < this->accountCount; i++)
	{*/
		if (accounts[a]->GetAccountNumber() == a)
		{
			return this->accounts[a];
		}
	
	return nullptr;
}
Client* Bank::CreateClient(int c, string n)
{
	Client* newClient = new Client(c, n);
	clients[c] = newClient;
	clientCount = clientCount + 1;

	return newClient;
}
Account* Bank::CreateAccount(int n, Client* c)
{
	Account* newAccount = new Account(n, c);
	accounts[n] = newAccount;
	accountCount = accountCount + 1;

	return newAccount;
}
Account* Bank::CreateAccount(int n, Client* c, double interest)
{
	Account* newAccount = new Account(n, c, interest);
	accounts[n] = newAccount;
	accountCount += 1;

	return newAccount;
}
Account* Bank::CreateAccount(int n, Client* c, Client* partner)
{
	Account* newAccount = new Account(n, c, partner);
	accounts[n] = newAccount;
	accountCount += 1;

	return newAccount;
}
Account* Bank::CreateAccount(int n, Client* c, Client* partner, double interest)
{
	Account* newAccount = new Account(n, c, partner, interest);
	accounts[n] = newAccount;
	accountCount += 1;

	return newAccount;
}

void Bank::AddInterest()
{

}