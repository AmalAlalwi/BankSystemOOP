#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
class clsManageUsersScreen :protected clsScreen
{
	enum enManageUSer {
		eListUsers = 1, eAddNewUser = 2,
		eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, MainMenue = 6
	};
	static short _ReadManageUsersOption() {
		cout << setw(35) << left << "" << "\tchoose what do you want to do from 1 to 6:";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6);
		return Choice;
	}
	static void _GoBackToManageUserMenue()
	{
		cout << "\n\nPress any key to go back to Main Menue...";
		system("pause>0");
		ShowManageUsersScreen();

	}
	static void _ShowListUsersScreen() {
		clsUsersListScreen::ShowClientsList();
	}
	static void _ShowAddNewUserScreen() {
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowUpdateUserScreen() {
		clsUpdateUserScreen::ShoeUpdateUserScreen();
	}
	static void _ShowDeleteUserScreen() {
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowFindUserScreen() {
		clsFindUserScreen::ShowFindUserScreen();
	}
	static void _PerformManageUsersOptions(enManageUSer Option) {
		switch (Option)	
		{
		case clsManageUsersScreen::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUserMenue();
			break;
		}
		case clsManageUsersScreen::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUserMenue();
			break;
		}
		case clsManageUsersScreen::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUserMenue();
			break;
		}
		case clsManageUsersScreen::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUserMenue();
			break;
		}
		case clsManageUsersScreen::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUserMenue();
			break;
		}
		case clsManageUsersScreen::MainMenue:
		{
			break;
		}
		default:
			break;
		}
	}
public:
	static void ShowManageUsersScreen() {
		system("cls");
		_DrawScreenHeader("\tManage Users Screen");
		cout << setw(37) << left << "" << "=============================================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue" << endl;
		cout << setw(37) << left << "" << "=============================================================\n";
		cout << setw(37) << left << "" << "\t[1] Show List Users\n";
		cout << setw(37) << left << "" << "\t[2] Add New User\n";
		cout << setw(37) << left << "" << "\t[3] Delete User\n";
		cout << setw(37) << left << "" << "\t[4] Update User\n";
		cout << setw(37) << left << "" << "\t[5] Find User\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue\n";
		_PerformManageUsersOptions((enManageUSer)_ReadManageUsersOption());
	}

};

