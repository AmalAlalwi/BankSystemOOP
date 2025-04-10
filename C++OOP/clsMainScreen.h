#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientsListScreen.h"
#include"clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include <iomanip>
using namespace std;
class clsMainScreen :protected clsScreen
{
	enum enMainMenueOptions {
		enListClient = 1, enAddNewClient = 2, enUpdateClient = 3, enDeleteClient = 4, enFindClient = 5, enTransactions = 6,
		enManageUsers = 7, enExit = 8
	};
	static short _ReadMainMenueOption() {
		cout << setw(35) << left <<""<< "\tchoose what do you want to do from 1 to 8:";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 8);
		return Choice;
	}
	static void _GoBackToMainMenue()
	{
		cout << "\n\nPress any key to go back to Main Menue...";
		system("pause>0");
		ShowMainScreen();

	}
	static void _ShowListClientsScreen() {
		clsClientsListScreen::ShowClientsList();
	}
	static void _ShowAddNewClientsScreen() {
		clsAddNewClientScreen::AddNewClientScreen();
	}
	static void _ShowUpdateClientScreen() {
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	static void _ShowDeleteClientScreen() {
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	static void _ShowFindClientScreen() {
		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _ShowTransactionsClientScreen() {
		cout << "Transactions clients will be here\n";
	}
	static void _ShowManageUsersScreen() {
		cout << "Manage Users will be here\n";
	}
	static void _PerformMainMenueOptions(enMainMenueOptions Option) {
		switch (Option)	
		{
		case clsMainScreen::enListClient:
		{
			system("cls");
			_ShowListClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enAddNewClient:
		{
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enTransactions:
		{
			system("cls");
			_ShowTransactionsClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enManageUsers:
		{
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::enExit:
		{
			system("cls");
			_GoBackToMainMenue();
			break;
		}
		default:
			break;
		}
	}
    public:
	static void ShowMainScreen() {
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		cout << setw(37) << left<<"" << "=============================================================\n";
		cout << setw(37) << left<<"" << "\t\t\tMain Menue"<<endl;
		cout << setw(37) << left<<"" << "=============================================================\n";
		cout << setw(37) << left<<"" << "\t[1] Show List Clients\n";
		cout << setw(37) << left<<"" << "\t[2] Add New Client\n";
		cout << setw(37) << left<<"" << "\t[3] Update Client\n";
		cout << setw(37) << left<<"" << "\t[4] Delete Client\n";
		cout << setw(37) << left<<"" << "\t[5] Find Client\n";
		cout << setw(37) << left<<"" << "\t[6] Transactios\n";
		cout << setw(37) << left<<"" << "\t[7] Mange Users\n";
		cout << setw(37) << left<<"" << "\t[8] Logout\n";
		_PerformMainMenueOptions((enMainMenueOptions)_ReadMainMenueOption());
	}
};

