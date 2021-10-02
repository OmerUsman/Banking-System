#include<iostream>
#include<fstream>
using namespace std;
void menu() {
	cout << "\tSelect one option below\n\t1 open an Account\n\t2 Balance Enquiry\n\t3 Deposit\n\t4 Withdrawal\n\t5 Close an Account\n\t6 Show All Accounts\n\t7 Quit\n";
}
class Bank {
protected:
	string Bank_Name = { "World Bank" };
	string location = { "Washington, D.C." };
	int * AccountType=new int();
public:
	Bank();
	Bank(Bank& x);
	int GetAccType();
	void SetAccType(int x);
	void GetBankName();
	void GetBankLoc();
	void getHelp();
	void Enquiry();
	~Bank();
};
class Account :public Bank {
private:
	string First_Name, Last_Name;
	double Balance=0.0;
public:
	Account();
	static int Acc_Num;
	Account Copy(Account &x) {
		First_Name = x.First_Name; Last_Name = x.Last_Name; Balance = x.Balance;
	}
	void SetName(string F, string L) {
		First_Name = F; Last_Name = L;
	}
	void Set_Balance(double x) {
		Balance = x;
	}
	string Get_Name() {
		string a = First_Name + ' ' +Last_Name;
		return a;
	}
	double Get_Balance() {
		return Balance;
	}
	friend ostream& operator<<(ostream &o, Account& x);
	~Account();
};
ostream& operator<<(ostream &o, Account& x) {
	o << "\t Name :" << x.Get_Name() << endl;
	o << "\t Balance :" << x.Get_Balance() << endl;
	return o;
}
int Account::Acc_Num = 0;
Account::Account() {
	First_Name = '\0'; Last_Name = '\0'; Balance = 0.0;
	Acc_Num++;
}
Account::~Account() {
}

Account* Regrow(Account* x,int& Size) {
	Account* temp = nullptr;
	if (Size == 0) {
		Size++;
		x = new Account[Size];
	}
	else
	{
		Size++;
		temp= new Account[Size];
		for (int i = 0; i < Size - 1; i++) {
			temp[i]=(x[i]);
		}
		delete[]x;
		x = temp;
		temp = nullptr;
	}
	return x;
}
Account* Shrink(Account* x, int& Size,int iterator) {
	Account* temp = nullptr;
	if (Size == 0) {
		cout << "\t\nNo Bank Account Yet\n";
	}
	else
	{
		Size--;
		temp=new Account[Size];
		for (int i = 0,j=0; i < Size+1;i++) {
			if (i != iterator) {
				temp[j] = (x[i]);
				j++;
			}
		}
		delete[]x;
		x = temp;
		temp = nullptr;
	}
	return x;
}
int main() {
	Account* A = nullptr;
	string F, L; double Balance;
	int Choice, temp, Size = 0; double Deposit,Withdrawal = 0.0;
	while (1)
	{
		menu();
		cout << "\tEnter no. :"; cin >> Choice;
		if (Choice == 7)break;
		switch (Choice) 
		case 1: {
			A = Regrow(A, Size);
			cout << "\tEnter First Name :"; cin >> F;
			cout << "\tEnter Last Name :"; cin >> L;
			cout << "\tEnter initil Balance:"; cin >> Balance;
			A[Size-1].SetName(F, L); A[Size-1].Set_Balance(Balance);
			cout <<A[Size-1] << endl;
			cout << "\tYour Account no. " << A[Size-1].Acc_Num << endl;
			cout << "\tCongradulation Account is Created\n";
			break;
		
		case 2: 
			cout << "\tEnter Account No. :"; cin >> temp; temp = temp;
			cout << A[temp-1];
			break;
		case 3:
			cout << "\tEnter Account No. :"; cin >> temp; temp = temp - 1;
			cout << "\tEnter Amount to Deposit :"; cin >> Deposit;
			Deposit = Deposit + A[temp].Get_Balance();
			A[temp].Set_Balance(Deposit);
			cout << A[temp];
			break;
		case 4:
			cout << "\tEnter Account No. :"; cin >> temp; temp = temp - 1;
			cout << "\tEnter Amount to Withdrawal :"; cin >> Withdrawal;
			Withdrawal = A[temp].Get_Balance() - Withdrawal;
			A[temp].Set_Balance(Withdrawal);
			cout << A[temp];
			break;
		case 5:
			cout << "\tEnter Account No. :"; cin >> temp; temp = temp - 1;
			A = Shrink(A, Size, temp);
			break;
		case 6:
			for (int i = 0; i < Size; i++) {
				cout << A[i] << endl;
			}
			break;
		}
		
	}
	delete[]A;
	return 0;
}
Bank::Bank() {
	*AccountType = -1;
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
	delete AccountType;
}
