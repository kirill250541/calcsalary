#pragma once

#include <iostream>
#include <string>  
#include <iomanip>
#include <fstream>
#include <vector> 
#include "List.h"
#include "Tax_deduction.h"
#include "Salary_supplement.h"
#include "Salary_deduction.h"

using namespace std;

class employee {
	string number_employee;
	string last_name;
	string first_name;
	string patronymic;
	int gender;
	struct birthday {
		int day;
		int month;
		int year;
	}b_day;
	string education;
	struct date_employment {
		int day;
		int month;
		int year;
	}d_empl;
	string employee_position;
	int salary_type;
	float rate;
	float tax;
	List<tax_deduction> t_deduction;
	List<salary_deduction> sal_deduction;
	List<salary_supplement> sal_supplement;
public:
	employee();
	employee(const employee&);
	~employee();
	string get_number_employee();
	string get_last_name();
	string get_first_name();
	string get_patronymic();
	int get_gender();
	int get_day_birthday();
	int get_month_birthday();
	int get_year_birthday();
	string get_education();
	int get_day_employment();
	int get_month_employment();
	int get_year_employment();
	string get_employee_position();
	int get_salary_type();
	float get_rate();
	float get_tax();
	List<tax_deduction>& get_list_tax_deduction();
	List<salary_deduction>& get_list_sal_deduction();
	List <salary_supplement>& get_list_sal_supplement();
	tax_deduction& get_tax_deduction(int);
	salary_deduction& get_sal_deduction(int);
	salary_supplement& get_sal_supplement(int);
	int get_size_list_tax_deduction();
	int get_size_list_sal_deduction();
	int get_size_list_sal_supplement();


	void set_number_employee(string);
	void set_last_name(string);
	void set_first_name(string);
	void set_patronymic(string);
	void set_gender(int);
	void set_day_birthday(int);
	void set_month_birthday(int);
	void set_year_birthday(int);
	void set_education(string);
	void set_day_employment(int);
	void set_month_employment(int);
	void set_year_employment(int);
	void set_employee_position(string);
	void set_salary_type(int);
	void set_rate(float);
	void set_tax(float);
	void set_tax_deduction(tax_deduction);
	void set_sal_deduction(salary_deduction);
	void set_sal_supplement(salary_supplement);

	//���������� ��������� ==
	bool operator ==(employee&);
	bool operator !=(employee&);
	//���������� ��������� =
	employee& operator = (const employee&);
	//������� ���������� ������ �� ����� 
	friend ostream& operator << (ostream&, employee&);
	//������� ���������� ������ � ���� 
	friend ofstream& operator << (ofstream&, employee&);
	//������ ���������� ����� ����������
	friend istream& operator >> (istream&, employee&);
	//������� ���������� ������ �� �����
	friend ifstream& operator >> (ifstream&, employee&);

	bool parameter_selection(employee&);
	int parameters(int);
	void change_employee(employee&, int);
	template<typename T>
	void change_list(List<T>&, int);
	bool compare(int,employee&);
};