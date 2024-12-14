#pragma once

#include <iostream>
#include <string>  
#include <iomanip>
#include <fstream>
#include <conio.h>
#include "List.h"

using namespace std;
class salary_change {
	string name;
public:
	salary_change();
	salary_change(const salary_change&);
	~salary_change();
	string get_name();
	void set_name(string);
	salary_change& operator = (const salary_change&);
	bool operator <(const salary_change&) const;
	bool operator ==(salary_change&);
	bool operator !=(salary_change&);
	friend istream& operator >> (istream&, salary_change&);
	friend ostream& operator << (ostream&, salary_change&);
	friend ofstream& operator << (ofstream&, salary_change&);
	friend ifstream& operator >> (ifstream&, salary_change&);
	void change_salary_change(salary_change&);
	//virtual void compare() = 0;
};