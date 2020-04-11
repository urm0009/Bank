#include "Account.h"

Account::Account(int accountNumber, Client* owner)
{
	this->accountNumber = accountNumber;
	this->owner = owner;
}
Account::Account(int accountNumber, Client* owner, double interest)
{
	this->accountNumber = accountNumber;
	this->owner = owner;
	this->interest = interest;
}
Account::Account(int accountNumber, Client* owner, Client* p)
{
	this->accountNumber = accountNumber;
	this->owner = owner;
	this->partner = p;
}
Account::Account(int accountNumber, Client* owner, Client* p, double interest)
{
	this->accountNumber = accountNumber;
	this->owner = owner;
	this->interest = interest;
	this->partner = p;
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
bool Account::CanWithdraw(double amount)
{
	if (balance > 0 && balance >= amount)
		return true;
	else return false;
}
void Account::Deposit(double amount)
{
	if (amount > 0) {
		balance = balance + amount;
		cout << "Your current ballance: $" << balance << endl;
	}
	else cout << "Insufficient amount of money to deposit" << endl;
}
void Account::Withdraw(double amount)
{
	if (balance >= amount)
	{
		balance -= amount;
		cout << "Succesfully withdrew: $" << amount << ".\nYour current balance is $" << balance << ".\n";
	}
	else cout << "Insufficiant funds." << endl;
}
void Account::AddInterest()
{
	if (interest > 0)
	{
		cout << "Added " << interest << "% to your account" << endl;
		balance = (balance + ((balance / 100) * interest));
	}
	else cout << "Your account has no right to claim interest" << endl;
}