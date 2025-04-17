#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositeScreen.h"
#include "clsWithdrawScreen.h"
#include"clsTotalBalanceScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
class clsTransactionsScreen :protected clsScreen
{
private:
	enum enTransactionsMenueOptions {
		eDeposit = 1, eWithdraw = 2, eTotalBalances = 3,eTransfare=4 ,eTransfarLog=5,eMainMenue = 6
	};
	static short _ReadTransactionsMenueOption() {
		cout << setw(35) << left << "" << "\tchoose what do you want to do from 1 to 6:";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6);
		return Choice;
	}
	static void _ShowDepositScreen() {
		clsDepositeScreen::ShowDepositeScreen();

	}
	static void _ShowWithdrawScreen() {
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalanceScreen() {
		clsTotalBalanceScreen::ShowTotalBalancesScreen();
	}
	static void _GoBackToTransactionsMenue() {
		cout << "\n\nPress any key to go back to Main Menue...";
		system("pause>0");
		ShowTransactionsScreen();
	}
	static void _ShowTransferScreen() {
		clsTransferScreen::ShowTransferScreen();
	}
	static void _ShowTransfersLogScreen() {
		clsTransferLogScreen::ShoeTransferLogScreen();
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
		case clsTransactionsScreen::eTransfare: {
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
		}
		case clsTransactionsScreen::eTransfarLog: {
			system("cls");
			_ShowTransfersLogScreen();
			_GoBackToTransactionsMenue();
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
		if (!CheckAccessRights(CurrentUser.pTransactions)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("\t Transactios Menue Screen");
		cout << setw(37) << left << "" << "=============================================================\n";
		cout << setw(37) << left << "" << "\t\t\tTransactions Menue" << endl;
		cout << setw(37) << left << "" << "=============================================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposite\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw\n";
		cout << setw(37) << left << "" << "\t[3] Total Balance\n";
		cout << setw(37) << left << "" << "\t[4] Transfer\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue\n";
		_PerformTransactionsMenueOptions((enTransactionsMenueOptions)_ReadTransactionsMenueOption());

	}
};

