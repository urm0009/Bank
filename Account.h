#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "Client.h"
using namespace std;

class Account
{
private:
	int accountNumber;
	double balance;
	double interest = 0.25;

	Client* owner;
	Client* partner;

public:
	Account(int accountNumber, Client *owner);
	Account(int accountNumber, Client *owner, double interest);
	Account(int accountNumber, Client *owner, Client *p);
	Account(int accountNumber, Client *owner, Client *p, double interest);
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

