#pragma once
#include <iostream>
#include "clsString.h"
#include "clsPerson.h"
#include <vector>
#include <fstream>
#include <string>
using namespace std;
string FileName = "Clients.txt";
class clsBankClient :public clsPerson
{
private:
	enum enMode {EmptyMode=1,UpdateMode=2,AddNewMode=3};
    enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	bool _MarkedForDeleted = false;
	float _AccountBalance;
	static clsBankClient _ConvertLineToClientObject(string Line,string Seperator= "#//#") {
		vector<string>vClient = clsString::SplitString(Line,Seperator);
		return clsBankClient(enMode::UpdateMode,vClient[0],vClient[1],vClient[2],vClient[3],vClient[4],vClient[5],stod(vClient[6]));

	}
	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#") {
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.PhoneNumber + Seperator;
		stClientRecord += Client._AccountNumber + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance) ;
		return stClientRecord;
	}
	static clsBankClient _GetClientEmptyObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	void _SaveClientsDataToFile(vector<clsBankClient> vClients) {
		fstream myfile;
		myfile.open(FileName, ios::out);
		if (myfile.is_open()) {
			for (clsBankClient C : vClients) {
				if (C.MarkedForDeleted() == false) {
					string line = _ConvertClientObjectToLine(C);
					myfile << line << endl;
				}
			}
			myfile.close();

		}
	}
    void _Update() {
		vector<clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();
		for(clsBankClient& C:_vClients)
		{
			if (C.AccountNumber() == AccountNumber()) {
				C = *this;
				break;
			}

		}
		_SaveClientsDataToFile(_vClients);
	}
	static vector<clsBankClient> _LoadClientsDataFromFile() {
		vector<clsBankClient>vClients;
		fstream myfile;
		myfile.open(FileName, ios::in);
		if (myfile.is_open()) {
			string line;
			while (getline(myfile, line)) {
				vClients.push_back(_ConvertLineToClientObject(line, "#//#"));
			}
			myfile.close();
		}
		return vClients;
	}
	void _AddNew() {
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}
	static void _AddDataLineToFile(string Line) {
		fstream myfile;
		myfile.open(FileName, ios::out|ios::app);
		if (myfile.is_open()) {
			myfile << Line << endl;
		}
		myfile.close();
	}
public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string PhoneNumber, string AccountNumber, string PinCode, float AccountBalance):clsPerson(FirstName,LastName,Email,PhoneNumber) {
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_AccountBalance = AccountBalance;
		_PinCode = PinCode;
	}
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}
	string AccountNumber() {
		return _AccountNumber;
	}
	void setPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string getPinCode() {
		return _PinCode;
	}
	__declspec(property(get=getPinCode,put=setPinCode))string PinCode;
	void setAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}
	float getAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = getAccountBalance, put = setAccountBalance))float AccountBalance;
	bool MarkedForDeleted() {
		return _MarkedForDeleted;
	}
	//No UI Related Code Inside Object
	//void Print() {
	//	cout << "Info: \n";
	//	cout << "___________________________________\n";
	//	cout << "AccountNumber " << AccountNumber()<<endl;
	//	cout << "FirstName:   " << FirstName << endl;
	//	cout << "LastName:    " << LastName << endl;
	//	cout << "FullName:    " << FullName() << endl;
	//	cout << "Email:       " << Email << endl;
	//	cout << "PhoneNumber: " << PhoneNumber << endl;
	//	cout << "PinCode:     " << PinCode << endl;
	//	cout << "AccountBalance " << AccountBalance << endl;
	//	cout << "___________________________________\n";
	//}
	static clsBankClient Find(string AccountNumber) {
		fstream myfile;
		myfile.open("Clients.txt", ios::in);
		if (myfile.is_open()) {
			string Line;
			while (getline(myfile,Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber) {
					myfile.close();
					return Client;
				}
			}
		}
		return _GetClientEmptyObject();
	}
	static clsBankClient Find(string AccountNumber,string PinCode) {
		fstream myfile;
		myfile.open("Clients.txt", ios::in);
		if (myfile.is_open()) {
			string Line;
			while (getline(myfile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber&&Client.PinCode ==PinCode ) {
					myfile.close();
					return Client;
				}
			}
		}
		return _GetClientEmptyObject();
	}
	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}
	enum enSaveResult{svFaildEmptyObject=0,svSucceeded=1,svFaildAccountNumberExists=2};
	enSaveResult Save() {
		switch (_Mode)	
		{
		case clsBankClient::EmptyMode:
		{
			return enSaveResult::svFaildEmptyObject;
		}
		case clsBankClient::UpdateMode:
		{
			_Update();
			return enSaveResult::svSucceeded;
		}
		case clsBankClient::AddNewMode:
		{
			if (IsClientExist(AccountNumber())) {
				return enSaveResult::svFaildAccountNumberExists;
			}
			else {

			_AddNew();
			_Mode = enMode::UpdateMode;
			return enSaveResult::svSucceeded;
					
			}

		}
		default:
			break;
		}
	}
	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode,"","","","",AccountNumber,"",0);
	}
	bool Delete() {
		vector<clsBankClient>vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : vClients) {
			if (C.AccountNumber() == _AccountNumber) {
				C._MarkedForDeleted = true;
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
		*this = _GetClientEmptyObject();
		return 1;
	}
	static vector<clsBankClient> GetClientList() {
		return _LoadClientsDataFromFile();
	}
	static float GetTotalBalance() {
		float TotalBalance = 0;
		vector<clsBankClient>vClients = _LoadClientsDataFromFile();
		for (clsBankClient C : vClients) {
			TotalBalance += C.AccountBalance;
		}
		return TotalBalance;
	}
	
};

