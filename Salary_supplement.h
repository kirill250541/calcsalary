#pragma once

#include "Salary_change.h" 
using namespace std;

class salary_supplement: public salary_change {
	float amount;
	float persentage;
	bool taxation;
public:
	salary_supplement();
	salary_supplement(const salary_supplement&);
	~salary_supplement();
	float get_amount();
	float get_persentage();
	bool get_taxation();
	void set_amount(float);
	void set_persentage(float);
	void set_taxation(bool);
	salary_supplement& operator = (const salary_supplement&);
	bool operator ==(salary_supplement&);
	bool operator !=(salary_supplement&);
	friend istream& operator >> (istream&, salary_supplement&);
	friend ostream& operator << (ostream&, salary_supplement&);
	friend ofstream& operator << (ofstream&, salary_supplement&);
	friend ifstream& operator >> (ifstream&, salary_supplement&);
	void change_salary_change(salary_supplement&);
	void compare();
};