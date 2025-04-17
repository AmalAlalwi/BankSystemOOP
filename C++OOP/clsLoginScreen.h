#pragma once
#include <iostream>
#include"Global.h"
#include "clsUser.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
class clsLoginScreen :protected clsScreen
{
	
	static bool _Login() {
		string Username, Password;
		bool LoginFaild = false;
		short FailedLoginCount = 0;
		do {
			if (LoginFaild) {
				FailedLoginCount++;
				cout << "Invalid Username or Password!." << endl;
				cout << "You have " << 3 - FailedLoginCount << " (trail)s to login\n";
			}
			if (FailedLoginCount >= 3) {
				cout << "You are locked after 3 faild trails!\n";
				return false;
			}
			cout << "Enter UserName?";
			cin >> Username;
			cout << "Enter Password?";
			cin >> Password;
			CurrentUser = clsUser::Find(Username, Password);
			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);
		CurrentUser.RegisterLogins();
		clsMainScreen::ShowMainScreen();
		return true;
	}
public:
	static bool ShowLoginScreen() {
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}


};
