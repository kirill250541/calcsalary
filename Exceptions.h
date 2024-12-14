#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;
class Exception {
protected:
	int errorCode;
public:
	Exception(int);
	virtual void what() = 0;
};
//����� ��� ����������, ����������� ��� �����
class Enter_Exception : public Exception {
public:
	Enter_Exception(int);
	//������� ����� ������ ��� ����
	static char* creator();
	//������� �����
	static char* Creator_Text();
	static char* Creator_Text_and_Number();
	static int Creator_gender();
	static int Creator_day();
	static int Creator_month();
	static int Creator_year();
	static string Creator_education();
	static int Creator_type_rate();
	static float creator_float();
	static int creator_int();

	static bool Check_Text(const char*);
	static bool Check_Text_and_Number(const char*);
	//��������� ������������ ����� ����
	static bool Check_float(const char*);
	static bool Check_int(const char*);
	static bool check_day_month_year(int, int, int);
	static bool check_month_year(int, int, int, int);
	//������ ���������� �� ������
	void what();
};
//����� ��� ����������, ����������� ��� ������ �� �������
class List_Exception : public Exception {
public:
	List_Exception(int);
	//������ ���������� �� ������
	void what();
};

class File_Exception : public Exception {
public:
	File_Exception(int);
	//������ ���������� �� ������
	void what();
};