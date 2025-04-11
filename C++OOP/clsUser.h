#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include <fstream>
string Filename = "Users.txt";
class clsUser :public clsPerson
{
private:
	enum  enMode
	{
		EmptyMode=0,UpdateMode=1,AddNewMode=2
	};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDeleted;
	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#") {
		vector<string>vClient = clsString::SplitString(Line, Seperator);
		return clsUser(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stoi(vClient[6]));
	}
	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#") {
		string stUser = "";
		stUser += User.FirstName + Seperator;
		stUser += User.LastName + Seperator;
		stUser += User.Email + Seperator;
		stUser += User.PhoneNumber + Seperator;
		stUser += User.UserName + Seperator;
		stUser += User.Password + Seperator;
		stUser += to_string(User.Permissions);
		return stUser;
	}
	static clsUser _GetUserEmptyObject() {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	void _SaveUsersDataToFile(vector<clsUser> vUsers) {
		fstream myfile;
		myfile.open(Filename, ios::out);
		if (myfile.is_open()) {
			for (clsUser User : vUsers) {
				if (User.MarkedForDeleted() == false) {
					string line = _ConvertUserObjectToLine(User);
					myfile << line << endl;
				}
			}
			myfile.close();

		}
	}
	void _Update() {
		vector<clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();
		for (clsUser& User : _vUsers)
		{
			if (User.UserName == UserName) {
				User = *this;
				break;
			}

		}
		_SaveUsersDataToFile(_vUsers);
	}
	static vector<clsUser> _LoadUsersDataFromFile() {
		vector<clsUser>vClients;
		fstream myfile;
		myfile.open(Filename, ios::in);
		if (myfile.is_open()) {
			string line;
			while (getline(myfile, line)) {
				vClients.push_back(_ConvertLineToUserObject(line, "#//#"));
			}
			myfile.close();
		}
		return vClients;
	}
	void _AddNew() {
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}
	static void _AddDataLineToFile(string Line) {
		fstream myfile;
		myfile.open(Filename, ios::out | ios::app);
		if (myfile.is_open()) {
			myfile << Line << endl;
		}
		myfile.close();
	}
public:
	clsUser(enMode Mode,string FirstName,string LastName,string Email,string Phone,string UserName,string Password,int Permissions):clsPerson(FirstName,LastName,Email,Phone) {
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}
	void setUserName(string UserName) {
		_UserName = UserName;
	}
	string getUserName() {
		return _UserName;
	}
	__declspec(property(get = getUserName, put = setUserName))string UserName;
	void setPassword(string Password) {
		_Password = Password;
	}
	string getPassword() {
		return _Password;
	}
	__declspec(property(get = getPassword, put = setPassword))string Password;
	void setPermissions(float Permissions) {
		_Permissions = Permissions;
	}
	int getPermissions() {
		return _Permissions;
	}
	__declspec(property(get = getPermissions, put = setPermissions))int Permissions;
	bool MarkedForDeleted() {
		return _MarkedForDeleted;
	}
	static clsUser Find(string UserName) {
		fstream myfile;
		myfile.open(Filename, ios::in);
		if (myfile.is_open()) {
			string Line;
			while (getline(myfile, Line)) {
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName) {
					myfile.close();
					return User;
				}
			}
			myfile.close();
		}
		return _GetUserEmptyObject();
	}
	static clsUser Find(string UserName, string Password) {
		fstream myfile;
		myfile.open(Filename, ios::in);
		if (myfile.is_open()) {
			string Line;
			while (getline(myfile, Line)) {
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName && User.Password==Password) {
					myfile.close();
					return User;
				}
			}
			myfile.close();
		}
		return _GetUserEmptyObject();
	}
	static bool IsUserExist(string UserName) {
		clsUser Client = clsUser::Find(UserName);
		return (!Client.IsEmpty());
	}
	static vector<clsUser> GetUsersList() {
		return _LoadUsersDataFromFile();
	}
	enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountUserExists = 2 };
	enSaveResult Save() {
		switch (_Mode)
		{
		case clsUser::EmptyMode:
		{
			return enSaveResult::svFaildEmptyObject;
		}
		case clsUser::UpdateMode:
		{
			_Update();
			return enSaveResult::svSucceeded;
		}
		case clsUser::AddNewMode:
		{
			if (IsUserExist(UserName)) {
				return enSaveResult::svFaildAccountUserExists;
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
};

