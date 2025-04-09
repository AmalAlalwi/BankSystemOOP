#pragma once
#include<iostream>
#include "clsDate.h"
using namespace std;
class clsUtil
{
public:
    enum enCheckNum { Odd = 1, Even = 2 };
    static void Srand() {
        srand((unsigned)time(NULL));
    }
    static int RandomNum(int From, int To) {
        int random = rand() % (To - From + 1) + From;
        return random;
    }
    static float GetFractionPart(float Num) {
        return Num - (int)Num;

    }
    static int MyRound(float Num) {

        if (abs(GetFractionPart(Num)) >= 0.5) {
            if (Num > 0)
                return (int)Num + 1;
            else return (int)Num - 1;

        }
        else return (int)Num;

    }
    static float MyAbsluteFunction(float Number) {
        if (Number < 0)
            Number = -1 * Number;
        return Number;
    }
    static int MyFloor(float Num) {
        if (Num >= 0) {
            return (int)Num;
        }
        else return (int)Num - 1;

    }
    static int MyCeil(float Num) {
        if (Num > 0)return (int)Num + 1;
        else return (int)Num;
    }
    static float MySqrt(float Num) {
        return pow(Num, 0.5);
    }
    static bool PrimeNumber(int Num) {
        for (int i = 2; i <= Num / 2; i++) {
            if (Num % i == 0)return 0;
        }
        return 1;
    }

    static enCheckNum CheckOddOrEvenNumber(int Number) {
        if (Number % 2 == 1)return enCheckNum::Odd;
        else return enCheckNum::Even;
    }


    static void Fibonacci(int Num) {
        int Prev1 = 0, Prev2 = 1;
        cout << Prev2 << " ";
        for (int i = 2; i <= Num; i++) {
            int Fib = Prev1 + Prev2;
            cout << Fib << " ";
            Prev1 = Prev2;
            Prev2 = Fib;
        }
    }
    static void Fibonacci(int a[], int Num) {
        a[0] = 1;
        a[1] = 1;
        for (int i = 2; i < Num; i++) {
            a[i] = a[i - 1] + a[i - 2];
        }
    }
    static void FibonacciUsingRecursion(int Num, int Prev1, int Prev2) {
        int Fib = 0;
        if (Num > 0) {
            Fib = Prev1 + Prev2;
            cout << Fib << " ";
            Prev1 = Prev2;
            Prev2 = Fib;
            FibonacciUsingRecursion(Num - 1, Prev1, Prev2);
        }
    }
    static int MyPow(int N, int M) {

        if (M == 0) {
            return 1;
        }
        else return N * MyPow(N, M - 1);
    }
    static void Swap(int* p1, int* p2) {
        int temp = *p1;
        *p1 = *p2;
        *p2 = temp;

    }
    static void Swap(string* p1, string* p2) {
        string temp = *p1;
        *p1 = *p2;
        *p2 = temp;

    }
    static void Swap(clsDate * p1, clsDate* p2) {
        clsDate temp = *p1;
        *p1 = *p2;
        *p2 = temp;

    }
    static void printArray(int a[100], int length) {
        for (int i = 0; i < length; i++) {
            printf("%0.2d\t", a[i]);
        }
        cout << endl;
    }
    static bool IsPalindroomArray(int a[100], int length) {

        for (int i = 0; i < length / 2; i++) {
            if (a[i] != a[length - i - 1])return 0;
        }
        return 1;
    }
    static int MaxNum(int a[100], int length) {
        int Max = -1;
        for (int i = 0; i < length; i++)
        {
            if (a[i] > Max)
            {
                Max = a[i];
            }
        }
        return Max;
    }
    static int MinNum(int a[100], int length) {
        int Min = 1e10;
        for (int i = 0; i < length; i++)
        {
            if (a[i] < Min)
            {
                Min = a[i];
            }
        }
        return Min;
    }
    static int SumArray(int a[100], int length) {
        int Sum = 0;
        for (int i = 0; i < length; i++)
        {
            Sum += a[i];
        }
        return Sum;
    }
    static float AverageArray(int a[100], int length) {
        float Sum = (float)SumArray(a, length);
        return Sum / (float)length;

    }
    static void CopyArray(int a[100], int b[100], int length) {
        for (int i = 0; i < length; i++)b[i] = a[i];

    }

    static void ShuffleArray(int a[100], int length) {
        for (int i = 0; i < length; i++) {
            swap(a[RandomNum(0, length - 1)], a[RandomNum(0, length - 1)]);
        }
    }
    static void ShuffleArray(string a[100], int length) {
        for (int i = 0; i < length; i++) {
            swap(a[RandomNum(0, length - 1)], a[RandomNum(0, length - 1)]);
        }
    }
    static void ReverseArray(int a[100], int length) {
        for (int i = 0; i < length / 2; i++) {
            swap(a[i], a[length - i - 1]);
        }
    }
    static int NumberIndexInArray(int a[100], int NumberSearch, int len) {
        for (int i = 0; i < len; i++) {
            if (a[i] == NumberSearch)return i;
        }
        return -1;
    }
    static bool CheckNumberInArray(int a[100], int NumberSearch, int len) {

        return NumberIndexInArray(a, NumberSearch, len) != -1;
    }
    static void AddArrayElements(int Number, int a[100], int& length) {
        a[length] = Number;
        length++;

    }
    static void CopyArrayUsingAddArrayElements(int a[100], int b[100], int length, int& length2) {
        for (int i = 0; i < length; i++) {
            AddArrayElements(a[i], b, length2);
        }
    }
    static void CopyOddElementsUsingAddArrayElements(int a[100], int b[100], int length, int& length2) {
        for (int i = 0; i < length; i++) {
            if (CheckOddOrEvenNumber(a[i]) == enCheckNum::Odd)
                AddArrayElements(a[i], b, length2);
        }
    }
    static void CopyPrimeNumber(int a[100], int b[100], int length, int& j) {

        for (int i = 0; i < length; i++) {
            if (PrimeNumber(a[i])) {
                AddArrayElements(a[i], b, j);
            }
        }

    }
    static void CopyDistinctArray(int a[100], int b[100], int length, int& length2) {
        for (int i = 0; i < length; i++) {
            if (!CheckNumberInArray(b, a[i], length2))
                AddArrayElements(a[i], b, length2);
        }
    }
    static int CountEven(int a[100], int len) {
        int Count = 0;
        for (int i = 0; i < len; i++) {
            if (CheckOddOrEvenNumber(a[i]) == enCheckNum::Even)Count++;
        }
        return Count;
    }
    static int CountNegativeNumbers(int a[100], int len) {
        int Count = 0;
        for (int i = 0; i < len; i++) {
            if (a[i] < 0)Count++;
        }
        return Count;
    }
    static int CountPositiveNumbers(int a[100], int len) {
        int Count = 0;
        for (int i = 0; i < len; i++) {
            if (a[i] >= 0)Count++;
        }
        return Count;
    }
    static void SumRowOfArray(int Array[3][3], int arr1[3]) {
        int Sum = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Sum += Array[i][j];
            }
            arr1[i] = Sum;
            Sum = 0;
        }
    }
    static void SumClumOfArray(int Array[3][3], int arr1[3]) {
        int Sum = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Sum += Array[j][i];
            }
            arr1[i] = Sum;
            Sum = 0;
        }
    }
    static void PrintMatrixArray(int arr[3][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%0.2d\t", arr[i][j]);
                //cout<<setw(2)<<arr[i][j]<<"\t";
            }
            cout << endl;
        }
        cout << "-------------------------------" << endl;
    }

    static void TransposedMatrix(int a[3][3], int b[3][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                b[i][j] = a[j][i];
            }
        }
    }
    static void ResultArray(int a[3][3], int b[3][3], int Result[3][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Result[i][j] = a[i][j] * b[i][j];
            }
        }
    }
    static void MiddleRowArray(int a[3][3], int row[3]) {
        int Row = 1;

        for (int j = 0; j < 3; j++) {
            row[j] = a[Row][j];

        }
    }
    static void MiddleColumnArray(int a[3][3], int Col[3]) {
        int Colm = 1;
        for (int i = 0; i < 3; i++) {
            Col[i] = a[i][Colm];
        }
    }
    static int SumMatrixArray(int a[3][3], int Row, int Col) {
        int Sum = 0;
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                Sum += a[i][j];
            }
        }
        return Sum;
    }
    static bool AreEqualArrays(int a[3][3], int b[3][3], int Row, int Col) {
        if (SumMatrixArray(a, Row, Col) == SumMatrixArray(b, Row, Col))
            return 1;
        else return 0;
    }
    static bool AreTypicalArrays(int a[3][3], int b[3][3], int Row, int Col) {
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                if (a[i][j] != b[i][j])
                    return 0;
            }
        }
        return 1;
    }
    static bool IsIdentityMatrix(int a[3][3], int Row, int Col) {
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                if (a[i][j] != 0 && i != j) {
                    return 0;
                }
                else if (a[i][j] != 1 && i == j) {
                    return 0;
                }
            }
        }
        return 1;
    }
    static bool IsScalarMatrix(int a[3][3], int Row, int Col) {
        int Num = a[0][0];
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                if (i == j && a[i][j] != Num)
                    return 0;
                else if (i != j && a[i][j] != 0)return 0;
            }
        }
        return 1;
    }
    static void ReadMatrixArray(int Array[3][3]) {

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Array[i][j] = RandomNum(1, 100);
            }
        }
    }
    static int CountNumInMatrixArray(int a[3][3], int Number, int Row, int Col) {
        int Count = 0;
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                if (a[i][j] == Number)Count++;
            }
        }
        return Count;
    }
    static bool IsSparceMatrix(int a[3][3], int Row, int Col) {
        int CountNum = Row * Col;

        return (CountNumInMatrixArray(a, 0, 3, 3) > CountNum / 2);
    }
    static bool CheckIfNumberInMatrix(int a[3][3], int Num, int Row, int Col) {
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                if (a[i][j] == Num)return 1;
            }
        }
        return 0;

    }
    static void IntersectedNumbersInTwoMatrix(int a[3][3], int b[3][3], int Row, int Col) {
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                if (CheckIfNumberInMatrix(b, a[i][j], 3, 3)) {
                    cout << a[i][j] << endl;
                }
            }
        }
    }
    static int MaxNumInMatrix(int a[3][3], short Row, short Col) {
        int Max = a[0][0];
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                if (a[i][j] > Max) {
                    Max = a[i][j];
                }
            }
        }
        return Max;
    }
    static int MinNumInMatrix(int a[3][3], short Row, short Col) {
        int Min = a[0][0];
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                if (a[i][j] < Min) {
                    Min = a[i][j];
                }
            }
        }
        return Min;
    }
    static bool IsPalindromeMatrix(int a[3][3], short Row, short Col) {
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col / 2; j++) {
                if (a[i][j] != a[i][Col - j - 1]) {
                    return 0;
                }
            }
        }
        return 1;
    }
    enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, DigitNum = 4 ,MixChars=5};


    static  char GetRandomCharacter(enCharType CharType) {

        switch (CharType) {
        case SmallLetter: { return char(RandomNum(97, 122)); break; }
        case CapitalLetter: { return char(RandomNum(65, 90)); break; }

        case SpecialCharacter: { return char(RandomNum(33, 47)); break; }
        case DigitNum: { return char(RandomNum(48, 57)); break; }
        case MixChars: { return char(RandomNum(33, 122)); break;        }
        }
    }
    static string GenerateWord(enCharType charType, short len) {
        string Word = "";
        for (int i = 0; i < len; i++) {
            Word += GetRandomCharacter(charType);
        }
        return Word;

    }
    static string GenerateKey(enCharType Type) {
        string Key = "";
        Key = Key + GenerateWord(Type, 4) + "_";
        Key = Key + GenerateWord(Type, 4) + "_";
        Key = Key + GenerateWord(Type, 4) + "_";
        Key = Key + GenerateWord(Type, 4);
        return Key;

    }
    static void GenerateKeys(short len,enCharType Type) {
        for (short i = 0; i < len; i++) {
            cout << GenerateKey(Type) << endl;
        }
    }
    static void ArrayOfKeys(string a[100], int length, enCharType Type) {
        for (int i = 0; i < length; i++) {
            a[i] = GenerateKey(Type);
        }
    }
    static string EncrypText(string Name, short KeyEncryp) {
        string Encryption = "";
        for (int i = 0; i <= Name.size(); i++) {
            Name[i] = char((int)Name[i] + KeyEncryp);
        }
        return Name;
    }
    static string DecrypText(string Name, short KeyDecryp) {
        string Decryption = "";
        for (int i = 0; i <= Name.size(); i++) {
            Name[i] = char((int)Name[i] - KeyDecryp);
        }
        return Name;
    }
    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNum(From, To);
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);

    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }
    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }

};

