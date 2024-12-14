#include "Salary_deduction.h"

salary_deduction::salary_deduction()
	:salary_change() {
	amount = 0;
	persentage = 0;
}
salary_deduction::salary_deduction(const salary_deduction& obj)
	:salary_change(obj) {
	this->amount = obj.amount;
	this->persentage = obj.persentage;
}
salary_deduction::~salary_deduction() {

}

float salary_deduction::get_amount() {
	return amount;
}
float salary_deduction::get_persentage() {
	return persentage;
}

void salary_deduction::set_amount(float ptr) {
	amount = ptr;
}
void salary_deduction::set_persentage(float ptr) {
	persentage = ptr;
}

salary_deduction& salary_deduction::operator = (const salary_deduction& obj) {
	if (this == &obj)
		return *this;
	if (typeid(obj) == typeid(salary_deduction)) {
		salary_change::operator = (obj);
	}
	amount = obj.amount;
	persentage = obj.persentage;
	return *this;
}

bool salary_deduction::operator ==(salary_deduction& obj) {
	if (typeid(obj) == typeid(salary_deduction))
		if (!salary_change::operator ==(obj))
			return false;
	if (get_amount() == obj.get_amount())
		if (get_persentage() == obj.get_persentage())
			return true;
	return false;
}
bool salary_deduction::operator !=(salary_deduction& obj) {
	if (typeid(obj) == typeid(salary_deduction))
		if (!salary_change::operator !=(obj))
			return false;
	if (get_amount() != obj.get_amount())
		return true;
	if (get_persentage() == obj.get_persentage())
		return true;
	return false;
}

istream& operator >> (istream& is, salary_deduction& obj) {
	if (typeid(obj) == typeid(salary_deduction))
		is >> dynamic_cast<salary_change&>(obj);
	char choice = ' ';
	cout << "1) Процент от заработка" << endl;
	cout << "2) Сумма" << endl;
	while (choice < '1' || choice > '3') {
		choice = _getch();
	}
	float var = 0;
	switch (choice) {
	case '1':
		cout << "Введите процент от заработка:" << endl;
		var = Enter_Exception::creator_float();
		obj.set_persentage(var);
		break;
	case '2':
		cout << "Введиет сумму:" << endl;
		var = Enter_Exception::creator_float();
		obj.set_amount(var);
		break;

	}
		return is;
}

ostream& operator << (ostream & os, salary_deduction & obj) {
	if (typeid(obj) == typeid(salary_deduction))
		os  << dynamic_cast<salary_change&>(obj);
	if (obj.get_amount())
		os << obj.get_amount();
	if (obj.get_persentage())
		os << obj.get_persentage();
	return os;
}

ofstream& operator << (ofstream & os, salary_deduction & obj) {
	if (typeid(obj) == typeid(salary_deduction))
		os << dynamic_cast<salary_change&>(obj);
	os << '|' << obj.get_amount();
	os << '|' << obj.get_persentage();
	return os;
}

ifstream& operator >> (ifstream & is, salary_deduction & obj) {
	if (typeid(obj) == typeid(salary_deduction))
		is >> dynamic_cast<salary_change&>(obj);
	string str;
	getline(is, str, '|');
	obj.set_amount(stof(str));
	getline(is, str, '|');
	obj.set_persentage(stof(str));
	return is;
}
void salary_deduction::change_salary_change(salary_deduction& obj) {
	if (typeid(obj) == typeid(salary_deduction))
		salary_change::change_salary_change(obj);
}

void salary_deduction::compare() {

}