#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsAddNewUserScreen :protected clsScreen
{
	static void _ReadUserInfo(clsUser& User) {
		cout << "\nEnter First Name:";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name:";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Phone:";
		User.PhoneNumber = clsInputValidate::ReadString();
		cout << "\nEnter Email:";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter Password:";
		User.Password = clsInputValidate::ReadString();
		cout << "\nEnter Permission:";
		User.Permissions = _ReadPermissionToSet();
	}
	static int _ReadPermissionToSet() {
		int Permision = 0;
		char Answer = 'y';
		cout << "\nDo you want to give access to all system [y,n]: \n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			return -1;
		}
		cout << "\nDo you want to give access to list clients [y,n]: \n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Permision += clsUser::enPermissions::pListClients;
		}
		cout << "\nDo you want to give access to add new client [y,n]: \n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Permision += clsUser::pAddNewClient;
		}
		cout << "\nDo you want to give access to delete client [y,n]: \n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Permision += clsUser::pDeleteClient;
		}
		cout << "\nDo you want to give access to update client [y,n]: \n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Permision += clsUser::pUpdateClient;
		}
		cout << "\nDo you want to give access to find client [y,n]: \n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Permision += clsUser::pFindClient;
		}
		cout << "\nDo you want to give access to transactios menu [y,n]: \n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Permision += clsUser::pTransactions;
		}
		cout << "\nDo you want to give access to manage users menu [y,n]: \n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Permision += clsUser::pManageUser;
		}
		return Permision;
		
		
	}
	static 	void _PrintUser(clsUser User) {
		cout << "Info: \n";
		cout << "___________________________________\n";
		cout << "FirstName:   " << User.FirstName << endl;
		cout << "LastName:    " << User.LastName << endl;
		cout << "FullName:    " << User.FullName() << endl;
		cout << "Email:       " << User.Email << endl;
		cout << "PhoneNumber: " << User.PhoneNumber << endl;
		cout << "UserName " << User.UserName << endl;
		cout << "Password " << User.Password << endl;
		cout << "Permissions " << User.Permissions << endl;
		cout << "___________________________________\n";
	}
public:
	static void ShowAddNewUserScreen() {
		_DrawScreenHeader("\tAdd New User");
		string UserName = "";
		cout << "\nPlease Enter Username:";
		UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName)) {
			cout << "\nUser Name is already used,enter another one:";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::GetAddNewUserObject(UserName);
		_ReadUserInfo(User);
		clsUser::enSaveResult SaveResult;
		SaveResult = User.Save();
		switch (SaveResult)
		{
		case clsUser::svFaildEmptyObject:
		{
			cout << "\nError user was not saved because it's empty";
			break;
		}
		case clsUser::svSucceeded:
		{
			cout << "\nUser saved successfuly :-)\n";
			_PrintUser(User);
			break;
		}
		case clsUser::svFaildUserNameExists:
		{
			cout << "\nError user was not saved because it's already exists";
			break;
		}
		default:
			break;
		}
	}

};

