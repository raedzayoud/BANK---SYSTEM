#include <iostream>
#include <string>
#include<fstream>
#include<vector>
#include<random>
#include <iomanip>
#include <ctime>



using namespace std;

/* Before the start in the code this is a simple overview of the class and his functionality */


/*
    Core of the program : clsBankClient
                          clsPerson
                          clsUser
    Library i used to support me in this project: clsDate
                                                  clsInputValidate
                                                  clsString
                                                  clsUtil
    Screen: 1.Client:  ---------------------
                       clsClientScreen
                       clsAddNewClientsScreen
                       clsDeleteClientScreen
                       clsUpdateClientScre
                       clsFindClientScreen
                       clsDepositScreen
                       clsWithdrawScreen
                       clsTotalBalanceScreen
                       clsTransfer
                       clsShowTranferLog
                       clsTransactionsScreen
                       ---------------------

            2.User:     ---------------------
                        clsListUsersScreen
                        clsAddNewUserScreen
                        clsDeleteUserScreen
                        clsUpdateUserScreen
                        clsFindUserScreen
                        clsManageUsersScreen
                        -------------------
*/

//This Class String contains many function of Manipulation of string that i need in the project
class clsString
{

private:
    string _Value;

public:

    clsString()
    {
        _Value = "";
    }

    clsString(string Value)
    {
        _Value = Value;
    }

    void SetValue(string Value) {
        _Value = Value;
    }

    string GetValue() {
        return _Value;
    }

    // __declspec(property(get = GetValue, put = SetValue)) string Value;


    static short Length(string S1)
    {
        return S1.length();
    };

    short Length()
    {
        return _Value.length();
    };

    static short CountWords(string S1)
    {

        string delim = " "; // delimiter
        short Counter = 0;
        short pos = 0;
        string sWord; // define a string variable

        // use find() function to get the position of the delimiters
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word
            if (sWord != "")
            {
                Counter++;
            }

            //erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }

        return Counter;

    }

    short CountWords()
    {
        return CountWords(_Value);
    };

    static string  UpperFirstLetterOfEachWord(string S1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {

            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = toupper(S1[i]);

            }

            isFirstLetter = (S1[i] == ' ' ? true : false);

        }

        return S1;
    }

    void  UpperFirstLetterOfEachWord()
    {
        // no need to return value , this function will directly update the object value
        _Value = UpperFirstLetterOfEachWord(_Value);
    }

    static string  LowerFirstLetterOfEachWord(string S1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {

            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = tolower(S1[i]);

            }

            isFirstLetter = (S1[i] == ' ' ? true : false);

        }

        return S1;
    }

    void  LowerFirstLetterOfEachWord()
    {


        // no need to return value , this function will directly update the object value
        _Value = LowerFirstLetterOfEachWord(_Value);
    }

    static string  UpperAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }

    void  UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }

    static string  LowerAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }

    void  LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

    static char  InvertLetterCase(char char1)
    {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }

    static string  InvertAllLettersCase(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertLetterCase(S1[i]);
        }
        return S1;
    }

    void  InvertAllLettersCase()
    {
        _Value = InvertAllLettersCase(_Value);
    }

    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

    static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {


        if (WhatToCount == enWhatToCount::All)
        {
            return S1.length();
        }

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                Counter++;


            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                Counter++;


        }

        return Counter;

    }

    static short  CountCapitalLetters(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (isupper(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

    static short  CountSmallLetters(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (islower(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (MatchCase)
            {
                if (S1[i] == Letter)
                    Counter++;
            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                    Counter++;
            }

        }

        return Counter;
    }

    short  CountSpecificLetter(char Letter, bool MatchCase = true)
    {
        return CountSpecificLetter(_Value, Letter, MatchCase);
    }

    static bool IsVowel(char Ch1)
    {
        Ch1 = tolower(Ch1);

        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

    }

    static short  CountVowels(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (IsVowel(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  CountVowels()
    {
        return CountVowels(_Value);
    }

    static vector<string> Split(string S1, string Delim)
    {

        vector<string> vString;

        short pos = 0;
        string sWord; // define a string variable

        // use find() function to get the position of the delimiters
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word
            /* if (sWord != "")
             {*/
            vString.push_back(sWord);
            //}

            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;

    }

    vector<string> Split(string Delim)
    {
        return Split(_Value, Delim);
    }

    static string TrimLeft(string S1)
    {


        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }

    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }

    static string TrimRight(string S1)
    {


        for (short i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }

    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }

    static string Trim(string S1)
    {
        return (TrimLeft(TrimRight(S1)));

    }

    void Trim()
    {
        _Value = Trim(_Value);
    }

    static string JoinString(vector<string> vString, string Delim)
    {

        string S1 = "";

        for (string& s : vString)
        {
            S1 = S1 + s + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());


    }

    static string JoinString(string arrString[], short Length, string Delim)
    {

        string S1 = "";

        for (short i = 0; i < Length; i++)
        {
            S1 = S1 + arrString[i] + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());

    }

    static string ReverseWordsInString(string S1)
    {

        vector<string> vString;
        string S2 = "";

        vString = Split(S1, " ");

        // declare iterator
        vector<string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {

            --iter;

            S2 += *iter + " ";

        }

        S2 = S2.substr(0, S2.length() - 1); //remove last space.

        return S2;
    }

    void ReverseWordsInString()
    {
        _Value = ReverseWordsInString(_Value);
    }

    static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
    {

        vector<string> vString = Split(S1, " ");

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
                if (LowerAllString(s) == LowerAllString(StringToReplace))
                {
                    s = sRepalceTo;
                }

            }

        }

        return JoinString(vString, " ");
    }

    string ReplaceWord(string StringToReplace, string sRepalceTo)
    {
        return ReplaceWord(_Value, StringToReplace, sRepalceTo);
    }

    static string RemovePunctuations(string S1)
    {

        string S2 = "";

        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }

        return S2;

    }

    void RemovePunctuations()
    {
        _Value = RemovePunctuations(_Value);
    }


};

/*

Models a person's basic information: It encapsulates details like first name, last name, email, and phone number within a single unit.
Provides structure his class is designed and organization: It promotes code clarity, reusability, and maintainability by defining a clear structure for handling person-related data.

*/
class clsPerson
{
private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;
public:
    clsPerson(string FirstName, string LastName, string Email, string Phone) {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }
    void setFirstName(string s) {
        _FirstName = s;
    }
    string getFirstName() {
        return  _FirstName;
    }


    //	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;

    void setLastName(string s) {
        _LastName = s;
    }
    string getLastName() {
        return  _LastName;
    }
    //	__declspec(property(get = getLastName, put = setLastName)) string LastName;

    void setEmail(string s) {
        _Email = s;
    }
    string getEmail() {
        return  _Email;
    }

    //	__declspec(property(get = getEmail, put = setLastName)) string Email;

    void setPhone(string s) {
        _Phone = s;
    }
    string getPhone() {
        return  _Phone;
    }

    //	__declspec(property(get = getPhone, put = setPhone)) string Phone;


    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nFirstName: " << _FirstName;
        cout << "\nLastName : " << _LastName;
        cout << "\nFull Name: " << FullName();
        cout << "\nEmail    : " << _Email;
        cout << "\nPhone    : " << _Phone;
        cout << "\n___________________\n";

    }






};

/*

   This Class Date contains many function of Date that i used in this project

*/

class clsDate
{

private:
    vector<string>vec;
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

public:


    static string DateOfTodayAndHourMinuteSecond() {

        std::time_t currentTime = std::time(nullptr);

        // Convert the time to a string using std::strftime
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y/%m/%d-%H:%M:%S", std::localtime(&currentTime));

        // Create a string object from the buffer
        std::string dateString(buffer);

        return dateString;


    }


    clsDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;
    }

    clsDate(string sDate)
    {

        vector <string> vDate;
        vDate = split(sDate);

        _Day = stoi(vDate[0]);
        _Month = stoi(vDate[1]);
        _Year = stoi(vDate[2]);

    }

    clsDate(short Day, short Month, short Year)
    {

        _Day = Day;
        _Month = Month;
        _Year = Year;

    }

    clsDate(short DateOrderInYear, short Year)
    {
        //This will construct a date by date order in year
        clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
        _Day = Date1._Day;
        _Month = Date1._Month;
        _Year = Date1._Year;
    }


    vector<string> split(string S1) {
        string delim = "/"; // délimiteur
        vector<string>vec;
        int pos = 0;
        string sWord; // définir une variable de type string pour stocker le mot

        // Utiliser la fonction find() pour obtenir la position des délimiteurs
        while ((pos = S1.find(delim)) != std::string::npos) {
            sWord = S1.substr(0, pos); // stocker le mot

            if (!sWord.empty()) {
                vec.push_back(sWord);
            }

            S1.erase(0, pos + delim.length()); // effacer jusqu'à la position du délimiteur et passer au mot suivant
        }

        if (!S1.empty()) {
            vec.push_back(S1); // imprimer le dernier mot de la chaîne
        }
        return vec;

    }





    void SetDay(short Day) {
        _Day = Day;
    }

    short GetDay() {
        return _Day;
    }
    //	_declspec(property(get = GetDay, put = SetDay)) short Day;

    void SetMonth(short Month) {
        _Month = Month;
    }

    short GetMonth() {
        return _Month;
    }
    //	__declspec(property(get = GetMonth, put = SetMonth)) short Month;


    void SetYear(short Year) {
        _Year = Year;
    }

    short GetYear() {
        return _Year;
    }
    //	__declspec(property(get = GetYear, put = SetYear)) short Year;

    void Print()
    {
        cout << "\t\t\t\t\t" << "Date: " << DateToString() << endl;
    }

    static clsDate GetSystemDate()
    {
        //system date
        time_t t = time(0);
        tm* now = localtime(&t);

        short Day, Month, Year;

        Year = now->tm_year + 1900;
        Month = now->tm_mon + 1;
        Day = now->tm_mday;

        return clsDate(Day, Month, Year);
    }

    static	bool IsValidDate(clsDate Date)
    {

        if (Date._Day < 1 || Date._Day>31)
            return false;

        if (Date._Month < 1 || Date._Month>12)
            return false;

        if (Date._Month == 2)
        {
            if (isLeapYear(Date._Year))
            {
                if (Date._Day > 29)
                    return false;
            }
            else
            {
                if (Date._Day > 28)
                    return false;
            }
        }

        short DaysInMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);

        if (Date._Day > DaysInMonth)
            return false;

        return true;

    }

    bool IsValid()
    {
        return IsValidDate(*this);
    }

    static string DateToString(clsDate Date)
    {
        return  to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
    }

    string DateToString()
    {
        return  DateToString(*this);
    }

    static bool isLeapYear(short Year)
    {

        // if year is divisible by 4 AND not divisible by 100
      // OR if year is divisible by 400
      // then it is a leap year
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    bool isLeapYear()
    {
        return isLeapYear(_Year);
    }

    static short NumberOfDaysInAYear(short Year)
    {
        return  isLeapYear(Year) ? 365 : 364;
    }

    short NumberOfDaysInAYear()
    {
        return  NumberOfDaysInAYear(_Year);
    }

    static short NumberOfHoursInAYear(short Year)
    {
        return  NumberOfDaysInAYear(Year) * 24;
    }

    short NumberOfHoursInAYear()
    {
        return  NumberOfHoursInAYear(_Year);
    }

    static int NumberOfMinutesInAYear(short Year)
    {
        return  NumberOfHoursInAYear(Year) * 60;
    }

    int NumberOfMinutesInAYear()
    {
        return  NumberOfMinutesInAYear(_Year);
    }

    static int NumberOfSecondsInAYear(short Year)
    {
        return  NumberOfMinutesInAYear(Year) * 60;
    }

    int NumberOfSecondsInAYear()
    {
        return  NumberOfSecondsInAYear();
    }

    static short NumberOfDaysInAMonth(short Month, short Year)
    {

        if (Month < 1 || Month>12)
            return  0;

        int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];

    }

    short NumberOfDaysInAMonth()
    {
        return NumberOfDaysInAMonth(_Month, _Year);
    }

    static short NumberOfHoursInAMonth(short Month, short Year)
    {
        return  NumberOfDaysInAMonth(Month, Year) * 24;
    }

    short NumberOfHoursInAMonth()
    {
        return  NumberOfDaysInAMonth(_Month, _Year) * 24;
    }

    static int NumberOfMinutesInAMonth(short Month, short Year)
    {
        return  NumberOfHoursInAMonth(Month, Year) * 60;
    }

    int NumberOfMinutesInAMonth()
    {
        return  NumberOfHoursInAMonth(_Month, _Year) * 60;
    }

    static int NumberOfSecondsInAMonth(short Month, short Year)
    {
        return  NumberOfMinutesInAMonth(Month, Year) * 60;
    }

    int NumberOfSecondsInAMonth()
    {
        return  NumberOfMinutesInAMonth(_Month, _Year) * 60;
    }

    static short DayOfWeekOrder(short Day, short Month, short Year)
    {
        short a, y, m;
        a = (14 - Month) / 12;
        y = Year - a;
        m = Month + (12 * a) - 2;
        // Gregorian:
        //0:sun, 1:Mon, 2:Tue...etc
        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    short DayOfWeekOrder()
    {
        return DayOfWeekOrder(_Day, _Month, _Year);
    }

    static string DayShortName(short DayOfWeekOrder)
    {
        string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

        return arrDayNames[DayOfWeekOrder];

    }

    static string DayShortName(short Day, short Month, short Year)
    {

        string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

        return arrDayNames[DayOfWeekOrder(Day, Month, Year)];

    }

    string DayShortName()
    {

        string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

        return arrDayNames[DayOfWeekOrder(_Day, _Month, _Year)];

    }

    static string MonthShortName(short MonthNumber)
    {
        string Months[12] = { "Jan", "Feb", "Mar",
                           "Apr", "May", "Jun",
                           "Jul", "Aug", "Sep",
                           "Oct", "Nov", "Dec"
        };

        return (Months[MonthNumber - 1]);
    }

    string MonthShortName()
    {

        return MonthShortName(_Month);
    }

    static void PrintMonthCalendar(short Month, short Year)
    {
        int NumberOfDays;

        // Index of the day from 0 to 6
        int current = DayOfWeekOrder(1, Month, Year);

        NumberOfDays = NumberOfDaysInAMonth(Month, Year);

        // Print the current month name
        printf("\n  _______________%s_______________\n\n",
            MonthShortName(Month).c_str());

        // Print the columns
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print appropriate spaces
        int i;
        for (i = 0; i < current; i++)
            printf("     ");

        for (int j = 1; j <= NumberOfDays; j++)
        {
            printf("%5d", j);


            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }

        printf("\n  _________________________________\n");

    }

    void PrintMonthCalendar()
    {
        PrintMonthCalendar(_Month, _Year);
    }

    static void PrintYearCalendar(int Year)
    {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", Year);
        printf("  _________________________________\n");


        for (int i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(i, Year);
        }

        return;
    }

    void PrintYearCalendar()
    {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", _Year);
        printf("  _________________________________\n");


        for (int i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(i, _Year);
        }

        return;
    }

    static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
    {


        short TotalDays = 0;

        for (int i = 1; i <= Month - 1; i++)
        {
            TotalDays += NumberOfDaysInAMonth(i, Year);
        }

        TotalDays += Day;

        return TotalDays;
    }

    short DaysFromTheBeginingOfTheYear()
    {


        short TotalDays = 0;

        for (int i = 1; i <= _Month - 1; i++)
        {
            TotalDays += NumberOfDaysInAMonth(i, _Year);
        }

        TotalDays += _Day;

        return TotalDays;
    }

    static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
    {

        clsDate Date;
        short RemainingDays = DateOrderInYear;
        short MonthDays = 0;

        Date._Year = Year;
        Date._Month = 1;

        while (true)
        {
            MonthDays = NumberOfDaysInAMonth(Date._Month, Year);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date._Month++;
            }
            else
            {
                Date._Day = RemainingDays;
                break;
            }

        }

        return Date;
    }

    void AddDays(short Days)
    {


        short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
        short MonthDays = 0;

        _Month = 1;

        while (true)
        {
            MonthDays = NumberOfDaysInAMonth(_Month, _Year);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                _Month++;

                if (_Month > 12)
                {
                    _Month = 1;
                    _Year++;

                }
            }
            else
            {
                _Day = RemainingDays;
                break;
            }

        }


    }

    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        return  (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
    }

    bool IsDateBeforeDate2(clsDate Date2)
    {
        //note: *this sends the current object :-)
        return  IsDate1BeforeDate2(*this, Date2);

    }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return  (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
    }

    bool IsDateEqualDate2(clsDate Date2)
    {
        return  IsDate1EqualDate2(*this, Date2);
    }

    static bool IsLastDayInMonth(clsDate Date)
    {

        return (Date._Day == NumberOfDaysInAMonth(Date._Month, Date._Year));

    }

    bool IsLastDayInMonth()
    {

        return IsLastDayInMonth(*this);

    }

    static bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }

    static clsDate AddOneDay(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date._Month))
            {
                Date._Month = 1;
                Date._Day = 1;
                Date._Year++;
            }
            else
            {
                Date._Day = 1;
                Date._Month++;
            }
        }
        else
        {
            Date._Day++;
        }

        return Date;
    }

    void AddOneDay()

    {
        *this = AddOneDay(*this);
    }

    static void  SwapDates(clsDate& Date1, clsDate& Date2)
    {

        clsDate aux;
        aux = Date1;
        Date1 = Date2;
        Date2 = aux;
    }

    static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        //this will take care of negative diff
        int Days = 0;
        short SawpFlagValue = 1;

        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            //Swap Dates
            SwapDates(Date1, Date2);
            SawpFlagValue = -1;

        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = AddOneDay(Date1);
        }

        return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
    }

    int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
    {
        return GetDifferenceInDays(*this, Date2, IncludeEndDay);
    }

    static short CalculateMyAgeInDays(clsDate DateOfBirth)
    {
        return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
    }
    //above no need to have nonstatic function for the object because it does not depend on any data from it.

    static clsDate IncreaseDateByOneWeek(clsDate& Date)
    {

        for (int i = 1; i <= 7; i++)
        {
            Date = AddOneDay(Date);
        }

        return Date;
    }

    void IncreaseDateByOneWeek()
    {
        IncreaseDateByOneWeek(*this);
    }

    clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
    {

        for (short i = 1; i <= Weeks; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }

    void IncreaseDateByXWeeks(short Weeks)
    {
        IncreaseDateByXWeeks(Weeks, *this);
    }

    clsDate IncreaseDateByOneMonth(clsDate& Date)
    {

        if (Date._Month == 12)
        {
            Date._Month = 1;
            Date._Year++;
        }
        else
        {
            Date._Month++;
        }

        //last check day in date should not exceed max days in the current month
        // example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
        // be 28/2/2022
        short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
        if (Date._Day > NumberOfDaysInCurrentMonth)
        {
            Date._Day = NumberOfDaysInCurrentMonth;
        }

        return Date;
    }

    void IncreaseDateByOneMonth()
    {

        IncreaseDateByOneMonth(*this);

    }

    clsDate IncreaseDateByXDays(short Days, clsDate& Date)
    {

        for (short i = 1; i <= Days; i++)
        {
            Date = AddOneDay(Date);
        }
        return Date;
    }

    void IncreaseDateByXDays(short Days)
    {

        IncreaseDateByXDays(Days, *this);
    }

    clsDate IncreaseDateByXMonths(short Months, clsDate& Date)
    {

        for (short i = 1; i <= Months; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }

    void IncreaseDateByXMonths(short Months)
    {
        IncreaseDateByXMonths(Months, *this);
    }

    static clsDate IncreaseDateByOneYear(clsDate& Date)
    {
        Date._Year++;
        return Date;
    }

    void IncreaseDateByOneYear()
    {
        IncreaseDateByOneYear(*this);
    }

    clsDate IncreaseDateByXYears(short Years, clsDate& Date)
    {
        Date._Year += Years;
        return Date;

    }

    void IncreaseDateByXYears(short Years)
    {
        IncreaseDateByXYears(Years);
    }

    clsDate IncreaseDateByOneDecade(clsDate& Date)
    {
        //Period of 10 years
        Date._Year += 10;
        return Date;
    }

    void IncreaseDateByOneDecade()
    {
        IncreaseDateByOneDecade(*this);
    }

    clsDate IncreaseDateByXDecades(short Decade, clsDate& Date)
    {
        Date._Year += Decade * 10;
        return Date;
    }

    void IncreaseDateByXDecades(short Decade)
    {
        IncreaseDateByXDecades(Decade, *this);
    }

    clsDate IncreaseDateByOneCentury(clsDate& Date)
    {
        //Period of 100 years
        Date._Year += 100;
        return Date;
    }

    void IncreaseDateByOneCentury()
    {
        IncreaseDateByOneCentury(*this);
    }

    clsDate IncreaseDateByOneMillennium(clsDate& Date)
    {
        //Period of 1000 years
        Date._Year += 1000;
        return Date;
    }

    clsDate IncreaseDateByOneMillennium()
    {
        IncreaseDateByOneMillennium(*this);
    }

    static clsDate DecreaseDateByOneDay(clsDate Date)
    {
        if (Date._Day == 1)
        {
            if (Date._Month == 1)
            {
                Date._Month = 12;
                Date._Day = 31;
                Date._Year--;
            }
            else
            {

                Date._Month--;
                Date._Day = NumberOfDaysInAMonth(Date._Month, Date._Year);
            }
        }
        else
        {
            Date._Day--;
        }

        return Date;
    }

    void DecreaseDateByOneDay()
    {
        DecreaseDateByOneDay(*this);
    }

    static clsDate DecreaseDateByOneWeek(clsDate& Date)
    {

        for (int i = 1; i <= 7; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }

        return Date;
    }

    void DecreaseDateByOneWeek()
    {
        DecreaseDateByOneWeek(*this);
    }

    static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date)
    {

        for (short i = 1; i <= Weeks; i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }

    void DecreaseDateByXWeeks(short Weeks)
    {
        DecreaseDateByXWeeks(Weeks, *this);
    }

    static clsDate DecreaseDateByOneMonth(clsDate& Date)
    {

        if (Date._Month == 1)
        {
            Date._Month = 12;
            Date._Year--;
        }
        else
            Date._Month--;


        //last check day in date should not exceed max days in the current month
       // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
       // be 28/2/2022
        short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
        if (Date._Day > NumberOfDaysInCurrentMonth)
        {
            Date._Day = NumberOfDaysInCurrentMonth;
        }


        return Date;
    }

    void DecreaseDateByOneMonth()
    {
        DecreaseDateByOneMonth(*this);
    }

    static clsDate DecreaseDateByXDays(short Days, clsDate& Date)
    {

        for (short i = 1; i <= Days; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }

    void DecreaseDateByXDays(short Days)
    {
        DecreaseDateByXDays(Days, *this);
    }

    static clsDate DecreaseDateByXMonths(short Months, clsDate& Date)
    {

        for (short i = 1; i <= Months; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }

    void DecreaseDateByXMonths(short Months)
    {
        DecreaseDateByXMonths(Months, *this);
    }

    static clsDate DecreaseDateByOneYear(clsDate& Date)
    {

        Date._Year--;
        return Date;
    }

    void DecreaseDateByOneYear()
    {
        DecreaseDateByOneYear(*this);
    }

    static clsDate DecreaseDateByXYears(short Years, clsDate& Date)
    {

        Date._Year -= Years;
        return Date;
    }

    void DecreaseDateByXYears(short Years)
    {
        DecreaseDateByXYears(Years, *this);
    }

    static clsDate DecreaseDateByOneDecade(clsDate& Date)
    {
        //Period of 10 years
        Date._Year -= 10;
        return Date;
    }

    void DecreaseDateByOneDecade()
    {
        DecreaseDateByOneDecade(*this);
    }

    static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date)
    {

        Date._Year -= Decades * 10;
        return Date;
    }

    void DecreaseDateByXDecades(short Decades)
    {
        DecreaseDateByXDecades(Decades, *this);
    }

    static clsDate DecreaseDateByOneCentury(clsDate& Date)
    {
        //Period of 100 years
        Date._Year -= 100;
        return Date;
    }

    void DecreaseDateByOneCentury()
    {
        DecreaseDateByOneCentury(*this);
    }

    static clsDate DecreaseDateByOneMillennium(clsDate& Date)
    {
        //Period of 1000 years
        Date._Year -= 1000;
        return Date;
    }

    void DecreaseDateByOneMillennium()
    {
        DecreaseDateByOneMillennium(*this);
    }


    static short IsEndOfWeek(clsDate Date)
    {
        return  DayOfWeekOrder(Date._Day, Date._Month, Date._Year) == 6;
    }

    short IsEndOfWeek()
    {
        return IsEndOfWeek(*this);
    }

    static bool IsWeekEnd(clsDate Date)
    {
        //Weekends are Fri and Sat
        short DayIndex = DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
        return  (DayIndex == 5 || DayIndex == 6);
    }

    bool IsWeekEnd()
    {
        return  IsWeekEnd(*this);
    }

    static bool IsBusinessDay(clsDate Date)
    {
        //Weekends are Sun,Mon,Tue,Wed and Thur

       /*
        short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
        return  (DayIndex >= 5 && DayIndex <= 4);
       */

       //shorter method is to invert the IsWeekEnd: this will save updating code.
        return !IsWeekEnd(Date);

    }

    bool IsBusinessDay()
    {
        return  IsBusinessDay(*this);
    }

    static short DaysUntilTheEndOfWeek(clsDate Date)
    {
        return 6 - DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
    }

    short DaysUntilTheEndOfWeek()
    {
        return  DaysUntilTheEndOfWeek(*this);
    }

    static short DaysUntilTheEndOfMonth(clsDate Date1)
    {

        clsDate EndOfMontDate;
        EndOfMontDate._Day = NumberOfDaysInAMonth(Date1._Month, Date1._Year);
        EndOfMontDate._Month = Date1._Month;
        EndOfMontDate._Year = Date1._Year;

        return GetDifferenceInDays(Date1, EndOfMontDate, true);

    }

    short DaysUntilTheEndOfMonth()
    {
        return DaysUntilTheEndOfMonth(*this);
    }

    static short DaysUntilTheEndOfYear(clsDate Date1)
    {

        clsDate EndOfYearDate;
        EndOfYearDate._Day = 31;
        EndOfYearDate._Month = 12;
        EndOfYearDate._Year = Date1._Year;

        return GetDifferenceInDays(Date1, EndOfYearDate, true);

    }

    short DaysUntilTheEndOfYear()
    {
        return  DaysUntilTheEndOfYear(*this);
    }

    //i added this method to calculate business days between 2 days
    static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
    {

        short Days = 0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                Days++;

            DateFrom = AddOneDay(DateFrom);
        }

        return Days;

    }

    static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
    {
        /*short Days = 0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                Days++;

            DateFrom = AddOneDay(DateFrom);
        }*/

        return CalculateBusinessDays(DateFrom, DateTo);

    }
    //above method is eough , no need to have method for the object

    static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
    {

        short WeekEndCounter = 0;

        for (short i = 1; i <= VacationDays; i++)
        {

            if (IsWeekEnd(DateFrom))
                WeekEndCounter++;

            DateFrom = AddOneDay(DateFrom);
        }
        //to add weekends
        for (short i = 1; i <= WeekEndCounter; i++)
            DateFrom = AddOneDay(DateFrom);

        return DateFrom;
    }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));

    }

    bool IsDateAfterDate2(clsDate Date2)
    {
        return IsDate1AfterDate2(*this, Date2);
    }

    enum enDateCompare { Before = -1, Equal = 0, After = 1 };

    static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;

        if (IsDate1EqualDate2(Date1, Date2))
            return enDateCompare::Equal;

        /* if (IsDate1AfterDate2(Date1,Date2))
             return enDateCompare::After;*/

             //this is faster
        return enDateCompare::After;

    }

    enDateCompare CompareDates(clsDate Date2)
    {
        return CompareDates(*this, Date2);
    }



};


class clsUtil
{

public:

    static string  EncryptText(string Text, short EncryptionKey = 2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey = 2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }


    enum enCharType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static  int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {

        //updated this method to accept mixchars
        if (CharType == MixChars)
        {
            //Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch (CharType)
        {

        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
    defualt:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    static  string GenerateWord(enCharType CharType, short Length)

    {
        string Word;

        for (int i = 1; i <= Length; i++)

        {

            Word = Word + GetRandomCharacter(CharType);

        }
        return Word;
    }

    static string  GenerateKey(enCharType CharType = CapitalLetter)
    {

        string Key = "";


        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);


        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }

    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
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

    static  void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);

    }

    static  void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static  void ShuffleArray(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

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


/*

Class of clsUser :

Represents a user within a system: It encapsulates user-specific information, including credentials, permissions, and personal details.
Manages user data persistence: It handles loading, saving, and deleting user data from text files ("Users.txt" and "Login.txt").
Provides authentication and authorization: It verifies user logins and controls access to system functionalities based on assigned permissions.


*/

class clsUser :public clsPerson
{

private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _UserName = "";
    string _Password = "";
    int _Permissions = 0;
    bool _MarkedForDelete = false;




    /*******************************************/
    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));

    }

    static vector<string> _ConvertLinetoUserLoginObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return vUserData;

    }


    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.getFirstName() + Seperator;
        UserRecord += User.getLastName() + Seperator;
        UserRecord += User.getEmail() + Seperator;
        UserRecord += User.getPhone() + Seperator;
        UserRecord += User.GetUserName() + Seperator;
        UserRecord += User.GetPassword() + Seperator;
        UserRecord += to_string(User.GetPermissions());

        return UserRecord;

    }

    /*******************************************/

    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    /***************************************************/

    static  vector <vector<string>> _LoadUsersLoginDataFromFile()
    {

        vector <vector<string>> vUsers;

        fstream MyFile;
        MyFile.open("Login.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                vector<string> User = _ConvertLinetoUserLoginObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector<clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.GetUserName() == _UserName)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }


    static string _ConverUserUsernamePasswordToLine(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = clsDate::DateOfTodayAndHourMinuteSecond() + Seperator;
        UserRecord += User.GetUserName() + Seperator;
        UserRecord += User.GetPassword() + Seperator;
        UserRecord += to_string(User.GetPermissions());

        return UserRecord;

    }


    static void _AddDataLineToFileIns(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Login.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }




    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
public:
    static  void AddNewInscr(clsUser c)
    {

        _AddDataLineToFileIns(_ConverUserUsernamePasswordToLine(c));
    }










    enum enPermissions {
        eAll = -1, pListClient = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTransaction = 32, pMangeUsers = 64, pLogin = 128
    };

    bool CheckAccessPermission(enPermissions p) {
        if (this->_Permissions == enPermissions::eAll) {
            return true;
        }
        if ((p & this->_Permissions) == p)
            return true;
        else
            return false;
    }


    clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) :clsPerson(FirstName, LastName,
            Email, Phone) {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }


    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    // __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }
    //  __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }

    //  __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.GetUserName() == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                //  User.SetPassword(clsUtil::DecryptText(User.GetPassword()));
                if (User.GetUserName() == UserName && User.GetPassword() == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.GetUserName() == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    static vector <vector<string>> GetUsersListLogin()
    {
        return _LoadUsersLoginDataFromFile();
    }





};

//Global User

clsUser CurrentUser = clsUser::Find("", "");
//----------------------------------------------------//

/*

Encapsulates input validation logic: It centralizes functions for ensuring data integrity and guiding user input.
Provides robust input handling: It gracefully handles invalid input, reprompting users until valid data is entered.
Simplifies input validation throughout the codebase: It offers reusable methods for different data types, promoting consistency and reducing code duplication.

*/


class clsInputValidate
{

public:

    static bool IsNumberBetween(short Number, short From, short To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    static bool IsNumberBetween(int Number, int From, int To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;

    }



    static bool IsNumberBetween(double Number, double From, double To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        //Date>=From && Date<=To
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
            &&
            (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
            )
        {
            return true;
        }

        //Date>=To && Date<=From
        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
            &&
            (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
            )
        {
            return true;
        }

        return false;
    }

    static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        int Number;
        while (!(cin >> Number)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        int Number = ReadIntNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadIntNumber();
        }
        return Number;
    }

    static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        float Number;
        while (!(cin >> Number)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static double ReadFloatNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        float Number = ReadFloatNumber();

        while (!IsNumberBetween(Number, From, To)) {
            cout << ErrorMessage;
            Number = ReadDblNumber();
        }
        return Number;
    }

    static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        double Number;
        while (!(cin >> Number)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        double Number = ReadDblNumber();

        while (!IsNumberBetween(Number, From, To)) {
            cout << ErrorMessage;
            Number = ReadDblNumber();
        }
        return Number;
    }

    static bool IsValideDate(clsDate Date)
    {
        return	clsDate::IsValidDate(Date);
    }

    static string ReadString()
    {
        string  S1 = "";
        // Usage of std::ws will extract allthe whitespace character
        getline(cin >> ws, S1);
        return S1;
    }
};


/*

 class clsBankClient :

Represents a bank client within a system.
Manages client-specific information, including personal details, account details, and balance.
Handles client data persistence (saving and loading from text files).
Provides operations for account management, such as deposits, withdrawals, and transfers.


*/

class clsBankClient :public clsPerson
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDelete = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string oper = "#//#") {
        vector<string>vec = clsString::Split(Line, oper);
        return clsBankClient(enMode::UpdateMode, vec[0], vec[1], vec[2],
            vec[3], vec[4], vec[5], stod(vec[6]));

    }

    static vector<clsBankClient> _LoadClientDataFromFile() {

        vector<clsBankClient>vec;
        fstream MyFile;
        MyFile.open("MyFile.txt", ios::in);
        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line)) {
                clsBankClient client = _ConvertLinetoClientObject(Line);
                vec.push_back(client);
            }
            MyFile.close();

        }
        return vec;


    }

    /***********************************************************/

    static vector<string> _LoadClientDataFromFileTransfer() {


        vector<string>vec;
        fstream MyFile;
        MyFile.open("Transfer.txt", ios::in);
        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line)) {
                vec.push_back(Line);
            }
            MyFile.close();

        }
        return vec;




    }




    /***********************************************************/





    static clsBankClient _GetEmptyClientObject() {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }


    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.getFirstName() + Seperator;
        stClientRecord += Client.getLastName() + Seperator;
        stClientRecord += Client.getEmail() + Seperator;
        stClientRecord += Client.getPhone() + Seperator;
        stClientRecord += Client.getAccountNumber() + Seperator;
        stClientRecord += Client.getPinCode() + Seperator;
        stClientRecord += to_string(Client.getAccountBalance());

        return stClientRecord;

    }






    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients) {

        fstream MyFile;
        MyFile.open("MyFile.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C._MarkForDelete == false) {

                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;


                }

            }

            MyFile.close();

        }

    }

    void _AddNew() {

        AddDataLineToFile(_ConverClientObjectToLine(*this));

    }

    void AddDataLineToFile(string s) {
        fstream MyFile;
        MyFile.open("MyFile.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << s << endl;

            MyFile.close();
        }


    }

    void _Update() {
        vector<clsBankClient>vec;
        vec = _LoadClientDataFromFile();
        for (clsBankClient& c : vec) {
            if (c.getAccountNumber() == getAccountNumber()) {
                c = *this;
                break;
            }
        }
        _SaveCleintsDataToFile(vec);
    }


    static  void  _AddDataLineToFileTransfer(string s) {

        fstream MyFile;
        MyFile.open("Transfer.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << s << endl;

            MyFile.close();
        }




    }








public:

    struct stTransfer {
        string Date;
        string source;
        string Destination;
        int Amount;
        int sourceB;
        int DestinationB;
        string Username;

    };





    static  stTransfer RemplirStTransfer(string s) {

        vector<string>c = clsString::Split(s, "#//#");
        stTransfer st;
        st.Date = c[0];
        st.source = c[1];
        st.Destination = c[2];
        st.Amount = stoi(c[3]);
        st.sourceB = stoi(c[4]);
        st.DestinationB = stoi(c[5]);
        st.Username = c[6];
        return st;


    }



    static  vector<string> GetLoadTransfer() {

        return _LoadClientDataFromFileTransfer();


    }



    static string ConverClientToString(clsBankClient Client, clsBankClient Client1, string Seperator = "#//#", int Transfere = 0)
    {

        string stClientRecord = clsDate::DateOfTodayAndHourMinuteSecond() + Seperator;
        stClientRecord += Client.getAccountNumber() + Seperator;
        stClientRecord += Client1.getAccountNumber() + Seperator;
        stClientRecord += to_string(Transfere) + Seperator;
        stClientRecord += to_string(Client.getAccountBalance() - Transfere) + Seperator;
        stClientRecord += to_string(Client1.getAccountBalance() + Transfere) + Seperator + CurrentUser.GetUserName();

        return stClientRecord;

    }




    static   void UpdateclientBalance(string Account, int x) {
        vector<clsBankClient>vec;
        vec = _LoadClientDataFromFile();
        for (clsBankClient& c : vec) {
            if (c.getAccountNumber() == Account) {
                c.setAccountBalance(x);
                break;
            }
        }
        _SaveCleintsDataToFile(vec);
    }



    clsBankClient(enMode c, string FirstName, string LastName, string Email, string Phone,
        string AccountNumber, string PinCode, float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone) {
        _Mode = c;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    static vector<clsBankClient>GetClientList() {

        return _LoadClientDataFromFile();

    }

    void Print() {
        cout << "Full name: " << FullName() << endl;
        cout << "Acc.Number: " << _AccountNumber << endl;
        cout << "Account Balance: " << _AccountBalance << endl;
    }

    static void AddNew(string s) {

        _AddDataLineToFileTransfer(s);

    }

    bool IsEmpty() {
        return _Mode == enMode::EmptyMode;
    }

    void setAccountNumber(string s) {
        _AccountNumber = s;
    }
    string getAccountNumber() {
        return  _AccountNumber;
    }




    bool Delete() {

        vector<clsBankClient>vec = _LoadClientDataFromFile();
        for (clsBankClient& c : vec) {
            if (c.getAccountNumber() == _AccountNumber) {
                c._MarkForDelete = true;
                break;
            }
        }
        _SaveCleintsDataToFile(vec);
        *this = _GetEmptyClientObject();



    }

    //	__declspec(property(get = getAccountNumber, put = setAccountNumber)) string AccountNumber;

    void setPinCode(string s) {
        _PinCode = s;
    }
    string getPinCode() {
        return  _PinCode;
    }
    //	__declspec(property(get = PinCode, put = setPinCode)) string PinCode;

    void setAccountBalance(float s) {
        _AccountBalance = s;
    }
    float getAccountBalance() {
        return  _AccountBalance;
    }

    //__declspec(property(get = getAccountBalance, put = setAccountBalance)) int AccountBalance;


    static clsBankClient Find(string Accouunt) {
        vector<clsBankClient>vec;
        fstream MyFile;
        MyFile.open("MyFile.txt", ios::in);//Read mode

        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line)) {
                clsBankClient client = _ConvertLinetoClientObject(Line);
                if (client.getAccountNumber() == Accouunt) {
                    MyFile.close();
                    return client;
                }
                vec.push_back(client);


            }
            MyFile.close();
            return _GetEmptyClientObject();
        }
    }

    static clsBankClient Find(string Accouunt, string PinCode) {
        vector<clsBankClient>vec;
        fstream MyFile;
        MyFile.open("MyFile.txt", ios::in);//Read mode
        string Line;
        while (getline(MyFile, Line)) {
            clsBankClient client = _ConvertLinetoClientObject(Line);
            if ((client.getAccountNumber() == Accouunt) && (client.getPinCode() == PinCode)) {
                MyFile.close();
                return client;
            }
            vec.push_back(client);


        }
        MyFile.close();
        return _GetEmptyClientObject();

    }



    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

    enSaveResults save() {
        switch (_Mode) {

        case enMode::EmptyMode: {
            if (IsEmpty()) {
                return enSaveResults::svFaildEmptyObject;
                break;
            }

        }
        case enMode::UpdateMode: {

            _Update();
            return enSaveResults::svSucceeded;
            break;
        }
        case enMode::AddNewMode: {

            if (clsBankClient::IsExistClient(_AccountNumber)) {
                return enSaveResults::svFaildEmptyObject;
            }
            else {
                _AddNew();
                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;

            }


        }

        }
    }


    static clsBankClient GetAddNewClient(string Account) {

        return clsBankClient(enMode::AddNewMode, "", "", "", "", Account, "", 0);

    }

    static bool IsExistClient(string Account) {
        clsBankClient client = clsBankClient::Find(Account);
        return (!client.IsEmpty());

    }

    void Deposit(double x) {
        _AccountBalance += x;
        save();
    }
    bool Withdraw(double x) {
        if (x > _AccountBalance) {
            return false;
        }
        else {
            _AccountBalance -= x;
            save();
            return true;
        }

    }


    static double GetTotalBalances() {

        vector<clsBankClient>vec = _LoadClientDataFromFile();
        double s;
        for (clsBankClient C : vec) {
            s += C._AccountBalance;
        }
        return s;

    }


};



/*

Serves as a base class for defining consistent screen layouts and access control within the application.
Provides reusable methods for formatting screen headers and enforcing user permissions.


*/


class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << endl;
        cout << "\t\t\t\t\tUser: " << CurrentUser.GetUserName() << endl;
        clsDate d;
        d.Print();

    }
    static bool CheckAccessRights(clsUser::enPermissions p) {
        if (!CurrentUser.CheckAccessPermission(p)) {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }




};


// All Function of Client
/*

Displays a list of all client records in a formatted table.
Enforces access control for viewing the client list.

Handles the process of adding new client accounts.
Enforces access control for adding clients.

Enables the deletion of existing client accounts.
Enforces access control for deleting clients.

Allows modification of existing client information.
Enforces access control for updating clients.

Facilitates searching for specific client records.
Enforces access control for finding clients.

*/

class clsClientScreen :protected clsScreen
{

private:
    static void PrintClientRecordLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.getAccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.getPhone();
        cout << "| " << setw(20) << left << Client.getEmail();
        cout << "| " << setw(10) << left << Client.getPinCode();
        cout << "| " << setw(12) << left << Client.getAccountBalance();

    }
public:

    static void ShowClientList() {
        if (!CheckAccessRights(clsUser::enPermissions::pListClient))
        {
            return;// this will exit the function and it will not continue
        }

        vector<clsBankClient>vec = clsBankClient::GetClientList();
        cout << endl;
        string title = "\t Client List Screen";

        string SubTitle = "\t    (" + to_string(vec.size()) + ") Client(s).";
        _DrawScreenHeader(title, SubTitle);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vec.size() == 0) {
            cout << "Unfortunately it was not exsit anyClient" << endl;
        }
        for (clsBankClient Client : vec)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;



    }




};

class clsAddNewClientsScreen :protected clsScreen
{
private:
    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.setFirstName(clsInputValidate::ReadString());

        cout << "\nEnter LastName: ";
        Client.setLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email: ";
        Client.setEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        Client.setPhone(clsInputValidate::ReadString());

        cout << "\nEnter PinCode: ";
        Client.setPinCode(clsInputValidate::ReadString());

        cout << "\nEnter Account Balance: ";
        Client.setAccountBalance(clsInputValidate::ReadFloatNumber());
    }

    static void _Print(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.getFirstName();
        cout << "\nLastName    : " << Client.getLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.getEmail();
        cout << "\nPhone       : " << Client.getPhone();
        cout << "\nAcc. Number : " << Client.getAccountNumber();
        cout << "\nPassword    : " << Client.getPinCode();
        cout << "\nBalance     : " << Client.getAccountBalance();
        cout << "\n___________________\n";

    }

public:

    static void AddNewClient() {

        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;// this will exit the function and it will not continue
        }
        _DrawScreenHeader("\t Add New Client");
        string AccountNumber = "";
        cout << "Please entrer a Account: " << endl;
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsExistClient(AccountNumber)) {
            cout << "Account is aleardy exsit please entrer another one: " << endl;
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient newClient = clsBankClient::GetAddNewClient(AccountNumber);
        ReadClientInfo(newClient);
        clsBankClient::enSaveResults SaveResult;
        SaveResult = newClient.save();
        switch (SaveResult) {

        case clsBankClient::enSaveResults::svSucceeded: {

            cout << "Account Add Successfuly" << endl;
            _Print(newClient);
            break;

        }
        case clsBankClient::enSaveResults::svFaildEmptyObject: {

            cout << "Error  Account was not saved because it is Empty" << endl;
            break;

        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }

    }






};

class clsDeleteClientScreen :protected clsScreen
{

private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.getFirstName();
        cout << "\nLastName    : " << Client.getLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.getEmail();
        cout << "\nPhone       : " << Client.getPhone();
        cout << "\nAcc. Number : " << Client.getAccountNumber();
        cout << "\nPassword    : " << Client.getPinCode();
        cout << "\nBalance     : " << Client.getAccountBalance();
        cout << "\n___________________\n";

    }

public:
    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tDelete Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsExistClient(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";
                _PrintClient(Client1);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }

};

class clsUpdateClientScreen :protected clsScreen

{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.getFirstName();
        cout << "\nLastName    : " << Client.getLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.getEmail();
        cout << "\nPhone       : " << Client.getPhone();
        cout << "\nAcc. Number : " << Client.getAccountNumber();
        cout << "\nPassword    : " << Client.getPinCode();
        cout << "\nBalance     : " << Client.getAccountBalance();
        cout << "\n___________________\n";

    }

    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.setFirstName(clsInputValidate::ReadString());

        cout << "\nEnter LastName: ";
        Client.setLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email: ";
        Client.setEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        Client.setPhone(clsInputValidate::ReadString());

        cout << "\nEnter PinCode: ";
        Client.setPinCode(clsInputValidate::ReadString());

        cout << "\nEnter Account Balance: ";
        Client.setAccountBalance(clsInputValidate::ReadFloatNumber());
    }

public:

    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsExistClient(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);

        cout << "\nAre you sure you want to update this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";


            ReadClientInfo(Client1);

            clsBankClient::enSaveResults SaveResult;

            SaveResult = Client1.save();

            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";

                _PrintClient(Client1);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

class clsFindClientScreen :protected clsScreen
{

private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.getFirstName();
        cout << "\nLastName    : " << Client.getLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.getEmail();
        cout << "\nPhone       : " << Client.getPhone();
        cout << "\nAcc. Number : " << Client.getAccountNumber();
        cout << "\nPassword    : " << Client.getPinCode();
        cout << "\nBalance     : " << Client.getAccountBalance();
        cout << "\n___________________\n";

    }

public:

    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tFind Client Screen");

        string AccountNumber;
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsExistClient(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClient(Client1);

    }

};

//------------------------------------// 


/*
*
* Function of Transation:

To create a structured and user-friendly interface for performing various banking transactions, including deposits, withdrawals, transfers, viewing balances, and checking transfer logs.
To maintain security by enforcing access rights based on user roles.


*/

class clsDepositScreen : protected clsScreen
{

private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.getFirstName();
        cout << "\nLastName    : " << Client.getLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.getEmail();
        cout << "\nPhone       : " << Client.getPhone();
        cout << "\nAcc. Number : " << Client.getAccountNumber();
        cout << "\nPassword    : " << Client.getPinCode();
        cout << "\nBalance     : " << Client.getAccountBalance();
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:

    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t   Deposit Screen");

        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsExistClient(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter deposit amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction y/n? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.getAccountBalance();

        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }

};

class clsWithdrawScreen : protected clsScreen

{

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.getFirstName();
        cout << "\nLastName    : " << Client.getLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.getEmail();
        cout << "\nPhone       : " << Client.getPhone();
        cout << "\nAcc. Number : " << Client.getAccountNumber();
        cout << "\nPassword    : " << Client.getPinCode();
        cout << "\nBalance     : " << Client.getAccountBalance();
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t   Withdraw Screen");

        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsExistClient(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter Withdraw amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction y/n? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client1.Withdraw(Amount)) {
                cout << "\nAmount Withdraw Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.getAccountBalance();
            }
            else {
                cout << "\nAmount Withdraw is not Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.getAccountBalance();

            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }






};

class clsTotalBalancesScreen : protected clsScreen
{

private:

    static void PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.getAccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.getAccountBalance();
    }

public:

    static void ShowTotalBalances()
    {

        vector <clsBankClient> vClients = clsBankClient::GetClientList();

        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else {

            for (clsBankClient Client : vClients)
            {
                PrintClientRecordBalanceLine(Client);
                cout << endl;
            }
        }

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtil::NumberToText(TotalBalances) << ")";
    }

};

class clsTransfer :protected clsScreen {

private:
    static clsBankClient _FindFirstClinet() {

        string Account;
        cout << "Please Entrer Account Number to Transfer from: ";
        cin >> Account;
        while (!clsBankClient::IsExistClient(Account)) {
            cout << "Please Entrer Account Number to Transfer from: ";
            cin >> Account;
        }
        cout << "Client Card: " << endl;
        cout << "________________________" << endl;
        clsBankClient c = clsBankClient::Find(Account);
        cout << "Full name: " << c.FullName() << endl;
        cout << "Acc.Number: " << c.getAccountNumber() << endl;
        cout << "Balance: " << c.getAccountBalance() << endl;
        cout << "________________________" << endl;

        return c;


    }


    static clsBankClient _FindSecondClinet() {
        string Account;
        cout << endl;
        cout << "Please Entrer Account Number to Transfer To: ";
        cin >> Account;
        while (!clsBankClient::IsExistClient(Account)) {
            cout << "Please Entrer Account Number to Transfer To: ";
            cin >> Account;
        }
        cout << "Client Card: " << endl;
        cout << "________________________" << endl;
        clsBankClient c1 = clsBankClient::Find(Account);
        cout << "Full name: " << c1.FullName() << endl;
        cout << "Acc.Number: " << c1.getAccountNumber() << endl;
        cout << "Balance: " << c1.getAccountBalance() << endl;
        cout << "________________________" << endl;
        cout << endl;

        return c1;



    }


    static  int ReadAccoount(clsBankClient c) {
        int TransferBalance;
        cout << "Enter Transfer Amount ? ";
        cin >> TransferBalance;
        while (true) {

            if (TransferBalance < c.getAccountBalance()) {
                break;
            }
            else {
                cout << "Enter another a Transfer Amount ? ";
                cin >> TransferBalance;
            }

        }
        return TransferBalance;

    }

    static  void _Print(clsBankClient c, int x) {

        cout << "__________________________________" << endl;
        cout << "Full name: " << c.FullName() << endl;
        cout << "Acc.Number: " << c.getAccountNumber() << endl;
        cout << "Balance: " << x << endl;
        cout << "__________________________________" << endl;



    }


public:

    static void ShowTransfer()
    {

        string Title = "\t  Transfer Screen";
        //   string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title);

        clsBankClient c = clsTransfer::_FindFirstClinet();
        clsBankClient c1 = clsTransfer::_FindSecondClinet();

        cout << endl;

        int TransferBalance = clsTransfer::ReadAccoount(c);
        char q;
        cout << "Are you sure you want to Perfrom this Operation y/n ";
        cin >> q;
        if (q == 'y') {
            int x = c.getAccountBalance() - TransferBalance;
            clsBankClient::UpdateclientBalance(c.getAccountNumber(), x);
            int x1 = c1.getAccountBalance() + TransferBalance;
            clsBankClient::UpdateclientBalance(c1.getAccountNumber(), x1);
            _Print(c, x);
            _Print(c1, x1);

            string s = clsBankClient::ConverClientToString(c, c1, "#//#", TransferBalance);
            clsBankClient::AddNew(s);



        }
    }

};

class clsShowTransferLog :protected clsScreen {

private:
    static void _Print(clsBankClient::stTransfer s) {


        cout << setw(8) << left << "" << "| " << setw(23) << left << s.Date;
        cout << "| " << setw(8) << left << s.source;
        cout << "| " << setw(8) << left << s.Destination;
        cout << "| " << setw(8) << left << s.Amount;
        cout << "| " << setw(10) << left << s.sourceB;
        cout << "| " << setw(10) << left << s.DestinationB;
        cout << "| " << setw(8) << left << s.Username;
        cout << endl;






    }


public:

    static void ShowTransferLog() {
        string Title = "\t  Transfer Log List Screen";
        vector<string> vClients = clsBankClient::GetLoadTransfer();
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        for (string c : vClients) {
            clsBankClient::stTransfer s;
            s = clsBankClient::RemplirStTransfer(c);
            _Print(s);
        }



    }



};

class clsTransactionsScreen :protected clsScreen
{


private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4, TransferLog = 5, eShowMainMenue = 6
    };

    static void _ShowTransfer() {

        clsTransfer::ShowTransfer();

    }

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        //  cout << "\n Withdraw Screen will be here.\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();

    }

    static void _ShowScreenMenue()
    {
        // clsScreen

    }


    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();

    }


    static void  _ShowTransferLog() {

        clsShowTransferLog::ShowTransferLog();

    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::TransferLog:
        {
            system("cls");
            _ShowTransferLog();
            _GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eTransfer:
        {
            system("cls");
            _ShowTransfer();
            _GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
          //  ShowTransactionsMenue();

        }
        }


    }

public:


    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTransaction))
        {
            return;// this will exit the function and it will not continue
        }
        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }

};

/*-------------------------------------*/


/*
* Manage User :

 clsListUsersScreen:ShowUsersList(): Displays a list of all users with details (username, full name, phone, email, password, permissions).

 clsAddNewUserScreen:ShowAddNewUserScreen(): Guides user through creating a new user, including username, personal details, password, and permissions.

 clsDeleteUserScreen:ShowDeleteUserScreen(): Prompts for a username and deletes the corresponding user after confirmation.

 clsUpdateUserScreen:ShowUpdateUserScreen(): Allows editing an existing user's information, similar to AddNewUserScreen.

 clsFindUserScreen:ShowFindUserScreen(): Prompts for a username and displays details of the found user.

 clsManageUsersScreen:ShowManageUsersMenue(): Presents a menu for user management actions (list, add, delete, update, find, go back to main menu).


*/

class clsListUsersScreen :protected clsScreen
{
private:
    static void _PrintUserRecordLine(clsUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.GetUserName();
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.getPhone();
        cout << "| " << setw(20) << left << User.getEmail();
        cout << "| " << setw(10) << left << User.GetPassword();
        cout << "| " << setw(12) << left << User.GetPermissions();

    }
public:

    static void ShowUsersList()
    {
        vector <clsUser>vUsers = clsUser::GetUsersList();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }




};

class clsAddNewUserScreen : protected clsScreen
{
private:

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.setFirstName(clsInputValidate::ReadString());

        cout << "\nEnter LastName: ";
        User.setLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email: ";
        User.setEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        User.setPhone(clsInputValidate::ReadString());

        cout << "\nEnter Password: ";
        User.SetPassword(clsInputValidate::ReadString());

        cout << "\nEnter Permission: ";
        User.SetPermissions(_ReadPermissionsToSet());
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.getFirstName();
        cout << "\nLastName    : " << User.getLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.getEmail();
        cout << "\nPhone       : " << User.getPhone();
        cout << "\nUser Name   : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClient;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransaction;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pMangeUsers;
        }

        cout << "\nRegister Login? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pLogin;
        }

        return Permissions;

    }

public:

    static void ShowAddNewUserScreen()
    {

        _DrawScreenHeader("\t  Add New User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;

        }
        }
    }



};

class clsDeleteUserScreen :protected clsScreen
{

private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.getFirstName();
        cout << "\nLastName    : " << User.getLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.getEmail();
        cout << "\nPhone       : " << User.getPhone();
        cout << "\nUser Name   : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";

    }

public:
    static void ShowDeleteUserScreen()
    {

        _DrawScreenHeader("\tDelete User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User1.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }

};

class clsUpdateUserScreen :protected clsScreen

{
private:


    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.setFirstName(clsInputValidate::ReadString());

        cout << "\nEnter LastName: ";
        User.setLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email: ";
        User.setEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        User.setPhone(clsInputValidate::ReadString());

        cout << "\nEnter Password: ";
        User.SetPassword(clsInputValidate::ReadString());

        cout << "\nEnter Permission: ";
        User.SetPermissions(_ReadPermissionsToSet());
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.getFirstName();
        cout << "\nLastName    : " << User.getLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.getEmail();
        cout << "\nPhone       : " << User.getPhone();
        cout << "\nUser Name   : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClient;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransaction;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pMangeUsers;
        }
        cout << "\nRegitser Login? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pLogin;
        }

        return Permissions;

    }

public:

    static void ShowUpdateUserScreen()
    {

        _DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";

        cout << "\nPlease Enter User UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nAccount number is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        _PrintUser(User1);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


            _ReadUserInfo(User1);

            clsUser::enSaveResults SaveResult;

            SaveResult = User1.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(User1);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

class clsFindUserScreen :protected clsScreen
{

private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.getFirstName();
        cout << "\nLastName    : " << User.getLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.getEmail();
        cout << "\nPhone       : " << User.getPhone();
        cout << "\nUserName    : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";

    }

public:

    static void ShowFindUserScreen()
    {

        _DrawScreenHeader("\t  Find User Screen");

        string UserName;
        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        if (!User1.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _PrintUser(User1);

    }

};

class clsManageUsersScreen :protected clsScreen
{

private:
    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowManageUsersMenue();
    }

    static void _ShowListUsersScreen()
    {
        //cout << "\nList Users Screen Will Be Here.\n";
        clsListUsersScreen::ShowUsersList();

    }

    static void _ShowAddNewUserScreen()
    {
        //cout << "\nAdd New User Screen Will Be Here.\n";
        clsAddNewUserScreen::ShowAddNewUserScreen();

    }

    static void _ShowDeleteUserScreen()
    {
        //  cout << "\nDelete User Screen Will Be Here.\n";
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        //  cout << "\nUpdate User Screen Will Be Here.\n";
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        //  cout << "\nFind User Screen Will Be Here.\n";
        clsFindUserScreen::ShowFindUserScreen();
    }


    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
    {

        switch (ManageUsersMenueOption)
        {
        case enManageUsersMenueOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eFindUser:
        {
            system("cls");

            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }

public:

    static void ShowManageUsersMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pMangeUsers))
        {
            return;// this will exit the function and it will not continue
        }
        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());
    }

};

/*
*
* clsShowListLoginRegister:

 This class is designed to present a list of user login/register records in a formatted table structure, ensuring access control for viewing this information.

*/

class clsShowListLoginRegister :public clsScreen {



private:
    static void _PrintUserRecordLine(vector<string> User)
    {


        cout << setw(8) << left << "" << "| " << setw(35) << left << User[0];
        cout << "| " << setw(20) << left << User[1];;
        cout << "| " << setw(20) << left << User[2];
        cout << "| " << setw(10) << left << User[3];

    }
public:

    static void ShowListLoginRegister()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pLogin))
        {
            return;// this will exit the function and it will not continue
        }


        vector <vector<string>>vUsers = clsUser::GetUsersListLogin();

        string Title = "\t  Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (vector<string> User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }









};

//Main Scrrenn


/*

 Key Functions:
ShowMainScreen(): Displays the main menu with options for clients, transactions, users, login/register, and logout.
_ReadMainMenueOption(): Reads user input to select a menu option.
_PerfromMainMenueOption(): Executes actions based on the chosen menu option, calling respective screens for clients, transactions, users, login/register, or ending the session.
_GoBackToMainMenue(): Facilitates returning to the main menu after completing actions in other screens.
clsLoginScreen Class:

Purpose: Manages user login, verifying credentials and providing access to the main application.
Key Functions:
ShowLoginScreen(): Presents the login screen for username and password input.
_Login(): Handles login logic, including:
Allowing 3 login attempts.
Validating credentials using clsUser::Find().
Redirecting to the main screen upon successful login using clsMainScreen::ShowMainScreen().
Handling failed login attempts

*/


class clsMainScreen :protected clsScreen {

private:



    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, LoginRegistrer = 8, Currencies = 9, eExit = 10
    };

    static int _ReadMainMenueOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 9]? ";
        int x = clsInputValidate::ReadIntNumberBetween(1, 9, "Entrer number between 1 and 9 ");
        return x;

    }


    static void _ShowAllClientsScreen()
    {
        // cout << "\nClient List Screen Will be here...\n";
        clsClientScreen::ShowClientList();

    }

    static void _ShowAddNewClientsScreen()
    {
        //cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewClientsScreen::AddNewClient();
    }

    static void _ShowDeleteClientScreen()
    {
        //  cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();


    }

    static void _ShowUpdateClientScreen()
    {
        // cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        // cout << "\nFind Client Screen Will be here...\n";
        clsFindClientScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenue()
    {
        // cout << "\nTransactions Menue Will be here...\n";
        clsTransactionsScreen::ShowTransactionsMenue();

    }

    static void _ShowManageUsersMenue()
    {
        // cout << "\nUsers Menue Will be here...\n";
        clsManageUsersScreen::ShowManageUsersMenue();

    }

    static void _ShowEndScreen()
    {
        CurrentUser = clsUser::Find("", "");

    }

    static void _ShowListLoginRegister() {

        clsShowListLoginRegister::ShowListLoginRegister();


    }





    static void _PerfromMainMenueOption(enMainMenueOptions c) {

        switch (c)
        {
        case clsMainScreen::eListClients: {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }

        case clsMainScreen::eAddNewClient:
        {    system("cls");
        _ShowAddNewClientsScreen();
        _GoBackToMainMenue();
        break;
        }

        case clsMainScreen::eDeleteClient:
        {    system("cls");
        _ShowDeleteClientScreen();
        _GoBackToMainMenue();
        break;
        }
        case clsMainScreen::eUpdateClient:
        {    system("cls");
        _ShowUpdateClientScreen();
        _GoBackToMainMenue();
        break;
        }
        case clsMainScreen::eFindClient:
        {    system("cls");
        _ShowFindClientScreen();
        _GoBackToMainMenue();
        break;
        }
        case clsMainScreen::eShowTransactionsMenue:
        {    system("cls");
        _ShowTransactionsMenue();
        _GoBackToMainMenue();
        break;
        }
        case clsMainScreen::eManageUsers: {
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        }
        case clsMainScreen::LoginRegistrer: {
            system("cls");
            _ShowListLoginRegister();
            _GoBackToMainMenue();
            break;
        }

        case clsMainScreen::eExit:
        {    system("cls");
        _ShowEndScreen();
        break;
        }
        default:
            break;
        }

    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        system("cls");
        ShowMainScreen();
    }



public:

    static void ShowMainScreen() {
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Registrer.\n";
        cout << setw(37) << left << "" << "\t[9] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());




    }




};


class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {

        int i = 3;
        bool LoginFaild = false;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                i--;
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "You have " << i << " Trials to Login" << endl;
                if (i == 0) {
                    return false;
                }

            }
            cout << endl;
            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);
        system("cls");

        clsUser::AddNewInscr(CurrentUser);

        clsMainScreen::ShowMainScreen();
        return true;

    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return  _Login();

    }

};


int main()
{

    while (true) {

        if (clsLoginScreen::ShowLoginScreen() == false) {
            break;
        }

    }


    //clsMainScreen::ShowMainScreen();
    system("pause>0");
    return 0;






}