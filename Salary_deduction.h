#pragma once

#include "Salary_change.h" 
using namespace std;

class salary_deduction: public salary_change {
	float amount;
	float persentage;
public:
	salary_deduction();
	salary_deduction(const salary_deduction&);
	~salary_deduction();
	float get_amount();
	float get_persentage();
	void set_amount(float);
	void set_persentage(float);
	salary_deduction& operator = (const salary_deduction&);
	bool operator ==(salary_deduction&);
	bool operator !=(salary_deduction&);
	friend istream& operator >> (istream&, salary_deduction&);
	friend ostream& operator << (ostream&, salary_deduction&);
	friend ofstream& operator << (ofstream&, salary_deduction&);
	friend ifstream& operator >> (ifstream&, salary_deduction&);
	void change_salary_change(salary_deduction&);
	void compare();
};