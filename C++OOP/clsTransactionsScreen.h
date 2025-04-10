#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositeScreen.h"
class clsTransactionsScreen :protected clsScreen
{
private:
	enum enTransactionsMenueOptions {
		eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eMainMenue = 4
	};
	static short _ReadTransactionsMenueOption() {
		cout << setw(35) << left << "" << "\tchoose what do you want to do from 1 to 4:";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 4);
		return Choice;
	}
	static void _ShowDepositScreen() {
		clsDepositeScreen::ShowDepositeScreen();

	}
	static void _ShowWithdrawScreen() {

	}
	static void _ShowTotalBalanceScreen() {

	}
	static void _GoBackToTransactionsMenue() {
		cout << "\n\nPress any key to go back to Main Menue...";
		system("pause>0");
		ShowTransactionsScreen();
	}
	static void _PerformTransactionsMenueOptions(enTransactionsMenueOptions Options) {
		switch (Options)	
		{
		case clsTransactionsScreen::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case clsTransactionsScreen::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case clsTransactionsScreen::eTotalBalances:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case clsTransactionsScreen::eMainMenue:
		{
			system("cls");

			break;
		}
		default:
			break;
		}
	}
public:
	static void ShowTransactionsScreen() {
		system("cls");
		_DrawScreenHeader("\t Transactios Menue Screen");
		cout << setw(37) << left << "" << "=============================================================\n";
		cout << setw(37) << left << "" << "\t\t\tTransactions Menue" << endl;
		cout << setw(37) << left << "" << "=============================================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposite\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw\n";
		cout << setw(37) << left << "" << "\t[3] Total Balance\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue\n";
		_PerformTransactionsMenueOptions((enTransactionsMenueOptions)_ReadTransactionsMenueOption());

	}
};

