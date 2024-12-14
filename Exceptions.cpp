#include <iostream>
#include "Exceptions.h"
using namespace std;
Exception::Exception(int var)
	: errorCode(var) {
}
Enter_Exception::Enter_Exception(int var)
	: Exception(var) {
}
List_Exception::List_Exception(int var)
	: Exception(var) {
}
File_Exception::File_Exception(int var)
	: Exception(var) {
}

char* Enter_Exception::creator() {
	char* str = nullptr, *tmp = nullptr;
	int size = 10, i = 0;
	try {
		str = new char[size];
	}
	catch (bad_alloc& object) {
		cout << object.what() << endl;
		return nullptr;
	}
	char symb = '\0';
	rewind(stdin);
	while (!(symb = cin.get()) || symb != '\n'){
		str[i++] = symb;
		if (i == size) {
			try {
				tmp = new char[size];
			}
			catch (bad_alloc& object) {
				delete[] str;
				str = nullptr;
				cout << object.what() << endl;;
				return nullptr;
			}
			for (int j(0); j < i; j++)
				tmp[j] = str[j];
			delete[] str;
			str = nullptr;
			size += 20;
			try {
				str = new char[size];
			}
			catch (bad_alloc& object) {
				cout << object.what() << endl;;
				return nullptr;
			}
			for (int j(0); j < i; j++) {
				str[j] = tmp[j];
			}
			delete[] tmp;
		}
	}
	str[i] = '\0';

	if (i + 1 == size)
		return str;
	try {
		tmp = new char[i+1];
	}
	catch (bad_alloc& object) {
		delete[] str;
		str = nullptr;
		cout << object.what() << endl;;
		return nullptr;
	}
	strcpy_s(tmp, i + 1, str);
	delete[] str;
	str = nullptr;
	return tmp;
}

char* Enter_Exception::Creator_Text() {
	char* str = nullptr;
	int fl = 0;
	while (true) {
		str = creator();
		if (str == nullptr) {
			fl++;
			if (fl == 4)
				break;
			continue;
		}
		try {
			if (Check_Text(str)) 
				throw Enter_Exception(-1);
		}
		catch (Enter_Exception object) {
			object.what();
			cout << "Повторите попытку:" << endl;
			delete[] str;
			str = nullptr;
			continue;
		}
		break;
	}
	return str;
}
char* Enter_Exception::Creator_Text_and_Number() {
	char* str = nullptr;
	int fl = 0;
	while (true) {
		str = creator();
		if (str == nullptr) {
			fl++;
			if (fl == 4)
				break;
			continue;
		}
		try {
			if (Check_Text_and_Number(str))
				throw Enter_Exception(-2);
		}
		catch (Enter_Exception object) {
			object.what();
			cout << "Повторите попытку:" << endl;
			delete[] str;
			str = nullptr;
			continue;
		}
		break;
	}
	return str;
}
int Enter_Exception::Creator_gender() {
	cout << "1) Муж\n2) Жен"<< endl;
	char choice = ' ';
	while (choice != '1' && choice != '2')
		choice = _getch();
	if (choice == '1')
		return 1;
	if (choice == '2')
		return 2;
	return 1;
}
int Enter_Exception::Creator_day() {
	char* str = nullptr;
	int day = 0, fl=0;
	while (day < 1 || day > 31) {
		str = creator();
		if (str == nullptr) {
			fl++;
			if (fl == 4)
				break;
			continue;
		}
		try {
			if (Check_int(str))
				throw Enter_Exception(-3);
		}
		catch (Enter_Exception object) {
			object.what();
			cout << "Повторите попытку:" << endl;
			delete[] str;
			str = nullptr;
			continue;
		}
		day = stoi(str);
	}
	return day;
}
int Enter_Exception::Creator_month() {
	char* str = nullptr;
	int month = 0,fl=0;
	while (month < 1 || month > 12) {
		str = creator();
		if (str == nullptr) {
			fl++;
			if (fl == 4)
				break;
			continue;
		}
		try {
			if (Check_int(str))
				throw Enter_Exception(-3);
		}
		catch (Enter_Exception object) {
			object.what();
			cout << "Повторите попытку:" << endl;
			delete[] str;
			str = nullptr;
			continue;
		}
		month = stoi(str);
	}
	return month;
}
int Enter_Exception::Creator_year() {
	char* str = nullptr;
	int year = 0,fl=0;
	while (year < 1950 || year > 2024) {
		str = creator();
		if (str == nullptr) {
			fl++;
			if (fl == 4)
				break;
			continue;
		}
		try {
			if (Check_int(str))
				throw Enter_Exception(-3);
		}
		catch (Enter_Exception object) {
			object.what();
			cout << "Повторите попытку:" << endl;
			delete[] str;
			str = nullptr;
			continue;
		}
		year = stoi(str);
	}
	return year;
}
string Enter_Exception::Creator_education() {
	vector<string> education { "Базовое", "Общее среднее", "Среднее специальное", "Высшее", "Другое"};
	cout << "1) " << education[0] << endl;
	cout << "2) " << education[1] << endl;
	cout << "3) " << education[2] << endl;
	cout << "4) " << education[3] << endl;
	cout << "5) " << education[4] << endl;
	char choice = ' ';
	while (choice < '1' || choice > '5') {
		choice = _getch();
	}
	if (choice == '1')
		return education[0];
	if (choice == '2')
		return education[1];
	if (choice == '3')
		return education[2];
	if (choice == '4')
		return education[3];
	if (choice == '5') {
		cout << "Введите образование:" << endl;
		education[4] = Creator_Text();
		return education[4];
	}
	return education[4];
}
int Enter_Exception::Creator_type_rate() {
	cout << "1) Аккордная сдельная система оплаты труда" << endl;
	cout << "2) Поденная система оплаты труда" << endl;
	cout << "3) Прямая сдельная система оплаты труда" << endl;
	cout << "4) Почасовая система оплаты труда" << endl;
	cout << "5) Косвенная сдельная система оплаты труда" << endl;
	cout << "6) Прогрессивная сдельная система оплаты труда" << endl;
	char choice = ' ';
	int var = 0;
	while (choice < '1' || choice > '6')
		choice = _getch();
	var = choice - '0';
	return var;
}
float Enter_Exception::creator_float() {
	char* str = nullptr;
	float var=0;
	int fl = 0;
	while (true) {
		str = creator();
		if (str == nullptr) {
			fl++;
			if (fl == 4)
				break;
			continue;
		}
		try {
			if (Check_float(str)) {
				throw Enter_Exception(-3);
			}
		}
		catch (Enter_Exception object) {
			object.what();
			cout << "Повторите попытку:" << endl;
			delete[] str;
			str = nullptr;
			continue;
		}
		var = stof(str);
		break;
	}
	return var;
}
int Enter_Exception::creator_int() {
	char* str = nullptr;
	int var = 0, fl = 0;
	while (true) {
		str = creator();
		if (str == nullptr) {
			fl++;
			if (fl == 4)
				break;
			continue;
		}
		try {
			if (Check_int(str)) {
				throw Enter_Exception(-3);
			}
		}
		catch (Enter_Exception object) {
			object.what();
			cout << "Повторите попытку:" << endl;
			delete[] str;
			str = nullptr;
			continue;
		}
		var = stoi(str);
		break;
	}
	return var;
}

bool Enter_Exception::Check_Text(const char* t_text) {
	bool fl = true;
	for (int i(0); t_text[i] != '\0'; i++) {
		if ((t_text[i] < 'а' || t_text[i] > 'я') && (t_text[i] < 'А' || t_text[i] > 'Я'))
			if((t_text[i] < 'a' || t_text[i] > 'z') && (t_text[i] < 'A' || t_text[i] > 'Z') && (t_text[i] != ' '))
				return fl;
		if ((t_text[i] >= 'a' && t_text[i] <= 'z') || (t_text[i] >= 'A' && t_text[i] <= 'Z') ||
			(t_text[i] >= 'А' && t_text[i] <= 'Я') || (t_text[i] >= 'а' && t_text[i] <= 'я'))
				fl = false;
	}
	return fl;
}
bool Enter_Exception::Check_Text_and_Number(const char* t_text) {
	bool fl = true;
	for (int i(0); t_text[i] != '\0'; i++) {
		if ((t_text[i] < 'а' || t_text[i] > 'я') && (t_text[i] < 'А' || t_text[i] > 'Я') && (t_text[i]<'0' || t_text[i]>'9'))
			if ((t_text[i] < 'a' || t_text[i] > 'z') && (t_text[i] < 'A' || t_text[i] > 'Z') && (t_text[i] != ' '))
				return fl;
		if ((t_text[i] >= 'a' && t_text[i] <= 'z') || (t_text[i] >= 'A' && t_text[i] <= 'Z') || (t_text[i] >= '0' && t_text[i]<='9') ||
			(t_text[i] >= 'А' && t_text[i] <= 'Я') && (t_text[i] >= 'а' && t_text[i] <= 'я'))
				fl = false;
	}
	return fl;
}
bool Enter_Exception::Check_float(const char* t_code) {
	bool fl = true;
	for (int i(0); t_code[i] != '\0'; i++) {
		if ((t_code[i] < '0' || t_code[i] > '9') && t_code[i] != ',')
			return fl;
		if (t_code[i] >= '0' && t_code[i] <= '9' || (t_code[i] == ',' && i!=0))
			fl = false;
	}
	return fl;
}
bool Enter_Exception::Check_int(const char* t_code) {
	bool fl = true;
	for (int i(0); t_code[i] != '\0'; i++) {
		if (t_code[i] < '0' || t_code[i] > '9')
			return fl;
		if (t_code[i] >= '0' && t_code[i] <= '9')
			fl = false;
	}
	return fl;
}
bool Enter_Exception::check_day_month_year(int day, int month, int year) {
	if (month == 4 || month == 6 || month == 9 || month == 11)
		if (day == 31)
			return true;
	if (year % 4) {
		if (day > 28 && month == 2)
			return true;
		return false;
	}
	return false;
}

bool Enter_Exception::check_month_year(int month, int year, int month_employment, int year_employment) {
	if (year_employment > year)
		return true;
	if (year_employment == year)
		if (month_employment > month)
			return true;
	return false;
}


void Enter_Exception::what() {
	switch (errorCode) {
	case -1: cout << "Нужен текст!" << endl; break;
	case -2: cout << "Нужен текст или чисто!" << endl; break;
	case -3: cout << "Нужно чсило!" << endl; break;
	case -4: cout << "Ошибка выделения памяти!" << endl; break;
	case -5: cout << "Ошибка ввода элемента!" << endl; break;
	default: cout << "Неизвестная ошибка!" << endl;
	}
}

void List_Exception::what() {
	switch (errorCode) {
	case -1: cout << "Ошибка добавления элемента в список." << endl; break;
	}
}


void File_Exception::what() {
	switch (errorCode) {
	case -1: cout << "Файл не был открыт! Информация не было считана из файла." << endl; break;
	case -2: cout << "Файл не был открыт! Информация не была записана в файл." << endl; break;
	}
}