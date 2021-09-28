#include<iostream>
#include<fstream>
using namespace std;
class Bank {
protected:
	string Bank_Name = { "World Bank" };
	string location = { "Washington, D.C." };
	int * AccountType=new int();
public:
	Bank(int x );
	Bank(Bank& x);
	int GetAccType();
	void SetAccType(int x);
	void GetBankName();
	void GetBankLoc();
	void getHelp();
	void Enquiry();
	~Bank();
	
};
int main() {
	Bank* B1 = new Bank(1);
	cout << "\t" << B1->GetAccType() << endl;;
	B1->Enquiry();
	B1->getHelp();
	delete B1;
	return 0;
}
Bank::Bank(int x = -1) {
	*AccountType = x;
}
Bank::Bank(Bank& x) {
	AccountType = x.AccountType;
}
void Bank:: GetBankName() {
	cout << Bank_Name;
}
void Bank::GetBankLoc() {
	cout << location;
}
void Bank:: SetAccType(int x = -1) {
	*AccountType = x;
}
int Bank:: GetAccType() {
	return  *AccountType;
}
void Bank::getHelp() {
	cout << "\tAccount Type :\n ";
	cout << "\t1.Student Account :\n ";
	cout << "\t2.Main Account :\n";
	cout << "\tStudent Acc have limit upto 30K\n\tMain Acc dont Have Ant Limit\n";
}
void Bank::Enquiry() {
	if (*AccountType == -1)
		cout << "\tInvalid Account Type\n";
	else
	{
		cout << "\tYou have Account Type " << GetAccType() << endl;
	}
}
Bank::~Bank() {
	cout << "\tDestroyed\n";
	delete AccountType;
}
