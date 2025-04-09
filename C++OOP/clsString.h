#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class clsString
{
private:
	string _Value;
public:
	enum enWhatToCount { UpperLetters = 0, LowerLetters = 1, AllLetters = 2 };
	clsString() {
		_Value = "";
	}
	clsString(string Value) {
		_Value = Value;
	}
	void setValue(string Value) {
		_Value = Value;
	}
	string getValue() {
		return _Value;
	}
	__declspec(property(get = getValue, put = setValue))string Value;
	static void PrintFirstCharacterFromString(string s)
	{
		cout << s[0] << endl;
		bool IsFirstLetter = true;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ' && IsFirstLetter) {
				cout << s[i] << endl;
			}
			IsFirstLetter = (s[i] == ' ' ? true : false);

		}
	}
	void PrintFirstCharacterFromString() {
		PrintFirstCharacterFromString(_Value);
	}
	static void UpperFirstLetterOfEachWord(string& s)
	{

		bool IsFirstLetter = true;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ' && IsFirstLetter && islower(s[i])) {
				s[i] = toupper(s[i]);
			}
			IsFirstLetter = (s[i] == ' ' ? true : false);

		}

	}
	void UpperFirstLetterOfEachWord() {
		UpperFirstLetterOfEachWord(_Value);
	}
	static void LowerFirstLetterOfEachWord(string& s)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ' && IsFirstLetter && isupper(s[i])) {
				s[i] = tolower(s[i]);
			}
			IsFirstLetter = (s[i] == ' ' ? true : false);

		}

	}
	void LowerFirstLetterOfEachWord()
	{
		LowerFirstLetterOfEachWord(_Value);
	}
	static string UpperLetterForAllString(string s) {
		for (int i = 0; i < s.size(); i++) {
			s[i] = toupper(s[i]);
		}
		return s;
	}
	static string LowerLetterForAllString(string s) {
		for (int i = 0; i < s.size(); i++) {
			s[i] = tolower(s[i]);
		}
		return s;
	}
	void UpperLetterForAllString() {
		_Value = UpperLetterForAllString(_Value);
	}
	void LowerLetterForAllString() {
		_Value = LowerLetterForAllString(_Value);
	}
	static short CountLetters(string s, enWhatToCount TypeCount = enWhatToCount::AllLetters) {
		short Count = 0;
		if (TypeCount == AllLetters) {
			return s.length();
		}
		for (int i = 0; i < s.size(); i++) {
			if (islower(s[i]) && TypeCount == enWhatToCount::LowerLetters)Count++;
			if (isupper(s[i]) && TypeCount == enWhatToCount::UpperLetters)Count++;
		}
		return Count;
	}
	static int CountCapitalLetters(string s) {
		int Count = 0;
		for (int i = 0; i < s.size(); i++) {
			if (isupper(s[i]))
				Count++;
		}
		return Count;
	}
	static int CountSmallLetters(string s) {
		int Count = 0;
		for (int i = 0; i < s.size(); i++) {
			if (islower(s[i]))
				Count++;
		}
		return Count;
	}
	int CountCapitalLetters() {
		return CountCapitalLetters(_Value);
	}
	int CountSmallLetters() {
		return CountSmallLetters(_Value);
	}
	static short  CountSpecialLetterInString(string s, char c) {
		short Count = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == c)Count++;
		}
		return Count;
	}
	static short  CountSpecialLetterInStringMatchCase(string s, char c, bool MatchCase = true) {
		short Count = 0;
		for (int i = 0; i < s.size(); i++) {
			if (MatchCase) {
				if (s[i] == c)
					Count++;
			}
			else if (tolower(s[i]) == tolower(c))Count++;
		}
		return Count;
	}
	static bool IsVowel(char c) {
		c = tolower(c);
		return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? true : false;
	}
	static char InvertLetter(char c) {
		return (islower(c) ? toupper(c) : tolower(c));

	}
	static string InvertAllString(string s) {
		for (int i = 0; i < s.length(); i++) {
			s[i] = InvertLetter(s[i]);
		}
		return s;
	}
	void InvertAllString() {
		_Value = InvertAllString(_Value);
	}
	static short CountLetterMatchCase(string s, char c, bool MatchCase = true) {
		short Count = 0;
		for (int i = 0; i < s.size(); i++) {
			if (MatchCase) {
				if (s[i] == c)
					Count++;
			}
			else if (tolower(s[i]) == tolower(c))Count++;
		}
		return Count;
	}
	short CountLetterMatchCase(char c, bool MatchCase = true) {
		return CountLetterMatchCase(c, MatchCase);
	}
	static short CountVowel(string s) {
		short Count = 0;
		for (int i = 0; i < s.size(); i++) {
			if (IsVowel(s[i]))Count++;
		}
		return Count;
	}
	short CountVowel() {
		return CountVowel(_Value);
	}
	static void PrintAllVowelsInString(string s) {
		for (int i = 0; i < s.size(); i++) {
			if (IsVowel(s[i]))cout << s[i] << "  ";
		}
	}
	void PrintAllVowelsInString() {
		PrintAllVowelsInString(_Value);
	}
	static void PrintWordInString(string s) {
		string delim = " ", sWord;
		short pos = 0;
		while ((pos = s.find(delim)) != std::string::npos) {
			sWord = s.substr(0, pos);
			if (sWord != "") { cout << sWord << endl; }
			s.erase(0, pos + delim.length());
		}
		if (s != "")cout << s << endl;
	}
	void PrintWordInString() {
		PrintWordInString(_Value);
	}
	static short CountWordsInString(string s) {
		string delim = " ", sWord;
		short pos = 0;
		int Counter = 0;
		while ((pos = s.find(delim)) != std::string::npos) {
			sWord = s.substr(0, pos);
			if (sWord != "") { Counter++; }
			s.erase(0, pos + delim.length());
		}
		if (s != "")Counter++;
		return Counter;
	}
	short CountWordsInString() {
		return CountWordsInString(_Value);
	}
	static vector<string> SplitString(string s, string delim = " ") {
		vector<string>vSplite;
		string  sWord;
		short pos = 0;
		while ((pos = s.find(delim)) != std::string::npos) {
			sWord = s.substr(0, pos);
			if (sWord != "") { vSplite.push_back(sWord); }
			s.erase(0, pos + delim.length());
		}
		if (s != "")vSplite.push_back(s);
		return vSplite;
	}
	vector<string> SplitString(string delim = " ") {
		return SplitString(_Value, delim);
	}
	static void PrintStringVector(vector<string>Word) {
		for (string& w : Word) {
			cout << w << endl;
		}
	}
	static string TrimLeft(string s) {

		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ')
				return (s.substr(i, s.size() - i));
		}

	}
	void TrimLeft() {
		_Value = TrimLeft(_Value);
	}
	static string TrimRight(string s) {
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] != ' ')
			{
				return (s.substr(0, i + 1));

			}
		}

	}
	void TrimRight() {
		_Value = TrimRight(_Value);
	}
	static string Trim(string s) {

		return (TrimLeft(TrimRight(s)));
	}
	void Trim() {
		_Value = Trim(_Value);
	}
	static string JoinString(vector<string>vWord, string delim) {
		string s = "";
		for (string i : vWord)
		{
			s += i;
			s += " ";
			s += delim;
		}

		return s.substr(0, s.size() - delim.size());
	}
	static string JoinString(string arr[], short Length, string delim) {
		string s = "";
		for (int i = 0; i < Length; i++)
		{
			s += arr[i];
			s += delim;
		}

		return s.substr(0, s.length() - delim.length());
	}
	static string ReverseWordInString1(string s) {
		string s1 = "";

		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == ' ') {
				s1 += s.substr(i, s.length());
				s.erase(i, s.length());
			}
		}
		s1 += " " + s;
		return s1.substr(1, s1.length());
	}
	static string ReverseWordInString(string s) {
		string s1 = "";
		vector<string>vW = SplitString(s, " ");
		vector<string>::iterator iter = vW.end();
		while (iter != vW.begin()) {
			--iter;
			s1 += *iter + " ";
		}
		return s1.substr(0, s1.length() - 1);

	}
	string ReverseWordInString() {
		_Value = ReverseWordInString(_Value);
	}
	static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{

		vector<string> vString = SplitString(S1, " ");

		for (string& s : vString)
		{

			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}

			}
			else
			{
				if (LowerLetterForAllString(s) == LowerLetterForAllString(StringToReplace))
				{
					s = sRepalceTo;
				}

			}

		}

		return JoinString(vString, " ");
	}
	static string ReplaceWordInStringUsingBuildInFunction(string s, string Word, string NewWord) {
		int pos = s.find(Word);
		while (pos != std::string::npos) {
			s = s.replace(pos, Word.length(), NewWord);
			pos = s.find(Word);
		}
		return s;
	}
	void ReplaceWord(string Word, string NewWord) {
		_Value = ReplaceWord(_Value, Word, NewWord);
	}
	static string RemovePunctFromStrig(string s) {
		string S1 = "";
		for (int i = 0; i < s.length(); i++) {
			if (!ispunct(s[i])) {
				S1 += s[i];
			}
		}
		return S1;

	}
	void RemovePunctFromStrig() {
		_Value = RemovePunctFromStrig(_Value);
	}
};