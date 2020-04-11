#include "Bank.h"

using namespace std;

int MAX_CLIENT = 40, MAX_ACCOUNT = 40;

int main()
{
	int choice, clientCode, accountCode, depositSum, withdrawSum, partnerNumber, partner, interest;
	double interestNumber;
	bool loop = true;
	string name;

	Bank* Fio = new Bank(MAX_CLIENT, MAX_ACCOUNT);


	for (int i = 0; i < 10; i++)
	{
		Fio->CreateClient(i, "Jaroslav");
		Fio->CreateAccount(i, Fio->GetClient(i));
	}



	do
	{
		cout << endl <<"With what action do you wish to proceed?\n";
		cout << "1 = Search client\n";
		cout << "2 = Search account\n";
		cout << "3 = Account balance\n";
		cout << "4 = Deposit\n";
		cout << "5 = Withdrawal\n";
		cout << "6 = Add interest\n";
		cout << "7 = Add client\n";
		cout << "8 = Add account\n";
		cout << "9 = Exit program\nChoose your number: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Enter client's code: ";
			cin >> clientCode;
			if (Fio->GetClient(clientCode) == nullptr)
				cout << "Cannot find client";
			else
			{
				cout << "Client number " << clientCode << " is known as: " << Fio->GetClient(clientCode)->GetName() << endl;
			}
		}
		break;
		case 2:
		{
			cout << "Enter account code: ";
			cin >> accountCode;
			cout << "Account owner: " << Fio->GetAccount(accountCode)->GetOwner()->GetName() << endl;
			cout << "Account balance: " << Fio->GetAccount(accountCode)->GetBalance() << endl;
			if(Fio->GetAccount(accountCode)->GetPartner() == nullptr)
			{
				cout << "Currently there is no account partner." << endl;
			}
			else
			{
				cout << "Account partner: " << Fio->GetAccount(accountCode)->GetPartner()->GetName() << "\nAccount partner code: " << Fio->GetAccount(accountCode)->GetPartner()->GetCode() << endl;
			}
			cout << "Account interest: " << Fio->GetAccount(accountCode)->GetInterest() << "%" << endl;
			break;
		}
		case 3:
		{
			cout << "Enter account number: ";
			cin >> accountCode;
			cout << endl << "Account's balance: $" << Fio->GetAccount(accountCode)->GetBalance();
			break;
		}
		case 4:
		{
			cout << "Enter account number: ";
			cin >> accountCode;
			cout << "Enter amount: ";
			cin >> depositSum;
			Fio->GetAccount(accountCode)->Deposit(depositSum);
			break;
		}
		case 5:
		{
			cout << "Enter account number: ";
			cin >> accountCode;
			cout << "Enter amount: ";
			cin >> withdrawSum;
			Fio->GetAccount(accountCode)->Withdraw(withdrawSum);
			break;
		}
		case 6:
		{
			cout << "Enter account number: ";
			cin >> accountCode;
			Fio->GetAccount(accountCode)->AddInterest();
			break;
		}
		case 7:
		{
			cout << "Enter new client number: ";
			cin >> clientCode;
			cout << "Enter new client name: ";
			cin >> name;
			Fio->CreateClient(clientCode, name);
			cout << "Succesfully created client" << endl;
			break;
		}
		case 8:
		{
			cout << "Enter account number: ";
			cin >> accountCode;
			cout << "Enter owner's number: ";
			cin >> clientCode;
			cout << "Does the account have a partner? Yes=1 No=0: ";
			cin >> partner;
			cout << "Does the account ahve interest? Yes=1 No=0: ";
			cin >> interest;
			if (partner == 1 && interest == 1)
			{
				cout << "Enter partner number: ";
				cin >> partnerNumber;
				cout << "Enter interest percentage: ";
				cin >> interestNumber;
				Fio->CreateAccount(accountCode, Fio->GetClient(clientCode), Fio->GetClient(partnerNumber), interestNumber);
			}
			else if (partner == 1 && interest == 0)
			{
				cout << "Enter partner number: ";
				cin >> partnerNumber;
				Fio->CreateAccount(accountCode, Fio->GetClient(clientCode), Fio->GetClient(partnerNumber));
			}
			else if (partner == 0 && interest == 1)
			{
				cout << "Enter interest percentage: ";
				cin >> interestNumber;
				Fio->CreateAccount(accountCode, Fio->GetClient(clientCode), interestNumber);
			}
			else if (partner == 0 && interest == 0)
			{
				Fio->CreateAccount(accountCode, Fio->GetClient(clientCode));
			}
			break;
		}
		case 9:
		{
			loop = false;
			Fio->~Bank();
			break;
		}
		default:
			loop = false;
			Fio->~Bank();
			break;
		}
	} while (loop);
}