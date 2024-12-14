#pragma once
#include <iostream>
#include <string>  
#include <vector>  
#include <iomanip>
#include <fstream>
#include <conio.h>
#include "Employee.h"
#include "List.h"
#include "Tax_deduction.h"
#include "salary_supplement.h"
#include "salary_deduction.h"

using namespace std;
class salary_calculation {
	int month_salary;
	int year_salary;
	float tax;
	float rate;
	float prepayment;
	float amount_tax;
	float salary;
	float polnya_salary;
	int month_employment;
	int year_employment;
	List<tax_deduction> month_tax_deduction;
	List<salary_deduction> month_sal_deduction;
	List<salary_supplement> month_sal_supplement;
	
public:
	salary_calculation();
	salary_calculation(employee);
	salary_calculation(salary_calculation&);
	virtual ~salary_calculation();
	int get_month_salary();
	int get_year_salary();
	float get_rate();
	float get_tax();
	int get_month_employment();
	int get_year_employment();
	float get_prepayment();
	float get_amount_tax();
	float get_salary();
	float get_polnya_salary();
	tax_deduction& get_month_tax_deduction(int);
	salary_deduction& get_month_sal_deduction(int);
	salary_supplement& get_month_sal_supplement(int);
	int get_size_list_month_tax_deduction();
	int get_size_list_month_sal_deduction();
	int get_size_list_month_sal_supplement();
	void set_month_salary(int);
	void set_year_salary(int);
	void set_rate(float);
	void set_tax(float);
	void set_month_employment(int);
	void set_year_employment(int);
	void set_prepayment(float);
	void set_amount_tax(float);
	void set_salary(float);
	void set_polnya_salary(float);
	void set_month_tax_deduction(tax_deduction);
	void set_month_sal_deduction(salary_deduction);
	void set_month_sal_supplement(salary_supplement);
	friend ostream& operator << (ostream&, salary_calculation&);
	friend ofstream& operator << (ofstream&, salary_calculation&);
	friend istream& operator >> (istream&, salary_calculation&);
	void calculation_monthly_salary();
};
