#pragma once
#include "Client.h"
using namespace std;

class Account
{
private:
	int accountNumber;
	double balance = 0;
	double interest;

	Client* owner;
	Client* partner;

public:
	Account(int accountNumber, Client* owner);
	Account(int accountNumber, Client* owner, double interest);
	Account(int accountNumber, Client* owner, Client* p);
	Account(int accountNumber, Client* owner, Client* p, double interest);
	~Account();

	int GetAccountNumber();
	double GetBalance();
	double GetInterest();
	Client* GetOwner();
	Client* GetPartner();
	bool CanWithdraw(double);

	void Deposit(double);
	void Withdraw(double);
	void AddInterest();
};

