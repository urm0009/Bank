#include <iostream>
#include <stdio.h>
#include <string>
#include "Client.h"
#include "Account.h"
#include "Banka.h"
using namespace std;

int MAX_CLIENT = 40, MAX_ACCOUNT = 40;

int main()
{
	int choice, clientCode, accountNum, depositSum, withdrawSum, partnerNumber;
	bool loop = true;
	string name;
	Banka* Fio = new Banka(MAX_CLIENT, MAX_ACCOUNT);


	for (int i = 0; i < 10; i++)
	{
		Fio->CreateClient(i, "Vaclav");
		Fio->CreateAccount(i, Fio->GetClient(i));
	}
	
	

	do 
	{
		cout << "With what action do you wish to proceed?\n1 = Search client\n2 = Search account\n3 = Account balance\n4 = Deposit\n5 = Withdrawal\n6 = Add interest\n7 = Add client\n8 = Add account\n9 = Exit program\nChoose your number: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Enter client code: ";
			cin >> clientCode;
			cout << "Name of the client: " << Fio->GetClient(clientCode)->GetName() << "\n";
			cout << "Code of the client: " << Fio->GetClient(clientCode)->GetCode() << "\n";
			break;
		}
		case 2:
		{
			cout << "Enter the account number: ";
			cin >> accountNum;
			cout << "Owner of the account: " << Fio->GetAccount(accountNum)->GetOwner()->GetName() << endl;
			cout << "Code of account owner " << Fio->GetAccount(accountNum)->GetOwner()->GetCode() << endl;
			if (Fio->GetAccount(accountNum)->GetPartner() == NULL)
				cout << "Currently there is no existing partner of the account." << endl;
			else
				cout << "Partner Of the account is: " << Fio->GetAccount(accountNum)->GetPartner()->GetName() << endl;
			cout << "Account balance: " << Fio->GetAccount(accountNum)->GetBalance() << endl;
			cout << "Account number: " << Fio->GetAccount(accountNum)->GetAccountNumber() << endl;
			break;
		}
		case 3:
		{
			cout << "Enter account number: ";
			cin >> accountNum;
			cout << "Account balance: " << Fio->GetAccount(accountNum)->GetBalance() << endl;
			break;
		}
		case 4:
		{
			cout << "Enter account number: ";
			cin >> accountNum;
			cout << "Enter deposit sum: ";
			cin >> depositSum;
			cout << "You have successfully entered " << depositSum << " to your account!" << endl;
			Fio->GetAccount(accountNum)->Deposit(depositSum);
			cout << "Your new balance is: " << Fio->GetAccount(accountNum)->GetBalance() << endl;
			break;
		}
		case 5:
		{
			cout << "Enter account number: ";
			cin >> accountNum;
			cout << "Enter withdraw sum: ";
			cin >> withdrawSum;
			Fio->GetAccount(accountNum)->Withdraw(withdrawSum);
			break;
		}
		case 6:
		{
			cout << "Enter account number: ";
			cin >> accountNum;
			Fio->GetAccount(accountNum)->AddInterest();
			cout << "Interest added.";
			break;
		}
		case 7:
		{
			cout << "Enter name of client: " << endl;
			cin >> name;
			cout << "Enter number of client: ";
			cin >> clientCode;
			Fio->CreateClient(clientCode, name);
			cout << "Sucesfully created client" << endl;
			break;
		}
		case 8:
		{
			int answer;
			cout << "Enter number of client: " << endl;
			cin >> clientCode;
			cout << "Does the account have a partner? 0-yes, 1-no\n";
			cin >> answer;
			if (answer == 0)
			{
				cout << "Enter partner number: " << endl;
				cin >> partnerNumber;
				Fio->CreateAccount(clientCode, Fio->GetClient(clientCode), Fio->GetClient(partnerNumber));
				cout << "Successfully added account!" << endl;
			}
			else 
			{
				Fio->CreateAccount(clientCode, Fio->GetClient(clientCode));
				cout << "Successfully added account!" << endl;
			}
			break;
		}
		case 9:
		{
			loop = false;
			break;
		}
		default:
			loop = false;
			break;
		}
	}
	while (loop);

	Fio->~Banka();
}