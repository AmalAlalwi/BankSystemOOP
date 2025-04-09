#pragma once
#include <iostream>
using namespace std;
#include "clsDate.h"
class clsInputValidate
{
public:
	static bool IsNumberBetween(int Number, int From, int To) {
		return (Number >= From && Number <= To);
	}
	static bool IsNumberBetween(short Number, short From, short To) {
		return (Number >= From && Number <= To);
	}
	static bool IsNumberBetween(float Number, float From, float To) {
		return (Number >= From && Number <= To);
	}
	static bool IsNumberBetween(double Number, double From, double To) {
		return (Number >= From && Number <= To);
	}
	static bool IsDateBetween(clsDate Date,clsDate From,clsDate To) {
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::CheckIfDate1EqualeDate2(Date, From))
			&& (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::CheckIfDate1EqualeDate2(Date, To))) {
			return true;
		}
		else if (((clsDate::IsDate1AfterDate2(Date, To) == clsDate::After) || (clsDate::CheckIfDate1EqualeDate2(Date, To)))
			&& (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::CheckIfDate1EqualeDate2(Date, From))) {
			
		}
		else {
			return false;
		}
		
			
	}
	static int ReadIntNumber(string Message="Invalid Number,Enter again?") {
		int Number;
		while (!(cin >> Number)) {
				cout << Message << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		return Number;
	}
	static double ReadDoubleNumber(string Message = "Invalid Number,Enter again:\n") {
		double Number;
		while (!(cin >> Number)) {
			cout << Message << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		return Number;
	}
	static float ReadFloatNumber(string Message = "Invalid Number,Enter again:\n") {
		float Number;
		while (!(cin >> Number)) {
			cout << Message << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		return Number;
	}
	static int ReadIntNumberBetween(int From, int To, string Message="Number is not within range, Enter again:\n") {
		int Number;
		cin >> Number;
		while (!IsNumberBetween(Number, From, To)) {
			cout << Message << endl;
		Number=ReadIntNumber();
		}
		return Number;
	}
	static double ReadDoubleNumberBetween(double From, double To, string Message) {
		double Number;
		cin >> Number;
		while (!IsNumberBetween(Number, From, To)) {
			cout << Message << endl;
	        Number=ReadDoubleNumber();
		}
		return Number;
	}
	static bool IsValidDate(clsDate date) {
		return clsDate::IsValidDate(date);
	}
	static string ReadString() {
		string s = "";
		getline(cin>>ws, s);
		return s;
	}
};

