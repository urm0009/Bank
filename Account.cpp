#include "Account.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include "Client.h"
using namespace std;

Account::Account(int number, Client* owner)
{
	this->accountNumber = number;
	this->owner = owner;
	balance = 0;
}
Account::Account(int number, Client* owner, double interest)
{
	this->accountNumber = number;
	this->owner = owner;
	this->interest = interest;
	balance = 0;
}
Account::Account(int number, Client* owner, Client* partner)
{
	this->accountNumber = number;
	this->owner = owner;
	this->partner = partner;
	balance = 0;
}
Account::Account(int number, Client* owner, Client* partner, double interest)
{
	this->accountNumber = number;
	this->owner = owner;
	this->partner = partner;
	this->interest = interest;
	balance = 0;
}
Account::~Account()
{

}
int Account::GetAccountNumber()
{
	return accountNumber;
}
double Account::GetBalance()
{
	return balance;
}
double Account::GetInterest()
{
	return interest;
}
Client* Account::GetOwner()
{
	return owner;
}
Client* Account::GetPartner()
{
	return partner;
}
bool Account::CanWithdraw(double sum)
{
	if (balance > sum)
		return true;
	else return false;
}
void Account::Deposit(double sum)
{
	if (sum > 0)
	{
		//printf("Your account gained %.2f €\n", a);
		balance = balance + sum;
		//printf("Your current balance is %2f €", balance);
	}
	else cout << "Negative deposit";
}
void Account::Withdraw(double sum)
{
	if (CanWithdraw(sum) && sum > 0)
	{
		balance = balance - sum;
		printf("Your current bilance is %.2f €", balance);
	}
	else printf("Error: Balance is possibly too low\n");
}
void Account::AddInterest()
{
	balance = balance * (interest + 1);
}