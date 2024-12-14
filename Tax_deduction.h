#pragma once

#include "Salary_change.h"
using namespace std;

class tax_deduction: public salary_change {
	float tax_deduction_amount;
public:
	tax_deduction();
	tax_deduction(const tax_deduction&);
	~tax_deduction();
	float get_tax_deduction_amount();
	void set_tax_deduction_amount(float);
	tax_deduction& operator = (const tax_deduction&);
	//bool operator <(const tax_deduction&) const;
	bool operator ==(tax_deduction&);
	bool operator !=(tax_deduction&);
	friend istream& operator >> (istream&, tax_deduction&);
	friend ostream& operator << (ostream&, tax_deduction&);
	friend ofstream& operator << (ofstream&, tax_deduction&);
	friend ifstream& operator >> (ifstream&, tax_deduction&);
	void change_salary_change(tax_deduction&);
	void compare();
};