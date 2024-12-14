#include "Tax_deduction.h"

tax_deduction::tax_deduction()
	:salary_change() {
	tax_deduction_amount = 0;
}

tax_deduction::tax_deduction(const tax_deduction& obj)
	:salary_change(obj) {
	this->tax_deduction_amount = obj.tax_deduction_amount;
}

tax_deduction::~tax_deduction() {

}

float tax_deduction::get_tax_deduction_amount() {
	return tax_deduction_amount;
}

void tax_deduction::set_tax_deduction_amount(float ptr) {
	tax_deduction_amount = ptr;
}

tax_deduction& tax_deduction::operator = (const tax_deduction& obj) {
	if (this == &obj)
		return *this;
	if (typeid(obj) == typeid(tax_deduction)) {
		salary_change::operator = (obj);
	}
	tax_deduction_amount = obj.tax_deduction_amount;
	return *this;
}

bool tax_deduction::operator ==(tax_deduction& obj) {
	if (typeid(obj) == typeid(tax_deduction))
		if (!salary_change::operator ==(obj))
			return false;
	if(get_tax_deduction_amount() == obj.get_tax_deduction_amount())
		return true;
	return false;
}
bool tax_deduction::operator !=(tax_deduction& obj) {
	if (typeid(obj) == typeid(tax_deduction))
		if (!salary_change::operator !=(obj))
			return false;
	if (get_tax_deduction_amount() != obj.get_tax_deduction_amount())
		return true;
	return false;
}

istream& operator >> (istream& is, tax_deduction& obj) {
	if (typeid(obj) == typeid(tax_deduction))
		is >> dynamic_cast<salary_change&>(obj);
	cout << "Введите сумму:" << endl;
	float var = Enter_Exception::creator_float();
	obj.set_tax_deduction_amount(var);	
	return is;
}

ostream& operator << (ostream& os, tax_deduction& obj) {
	if (typeid(obj) == typeid(tax_deduction))
		os << dynamic_cast<salary_change&>(obj);
	os << obj.get_tax_deduction_amount();
	return os;
}

ofstream& operator << (ofstream& os, tax_deduction& obj) {
	if (typeid(obj) == typeid(tax_deduction))
		os << dynamic_cast<salary_change&>(obj);
	os << '|' << obj.get_tax_deduction_amount();
	return os;
}

ifstream& operator >> (ifstream& is, tax_deduction& obj) {
	if (typeid(obj) == typeid(tax_deduction))
		is >> dynamic_cast<salary_change&>(obj);
	string str;
	getline(is, str, '|');
	obj.set_tax_deduction_amount(stof(str));
	str.clear();
	return is;
}

void tax_deduction::compare() {

}

void tax_deduction::change_salary_change(tax_deduction& obj) {
	if (typeid(obj) == typeid(tax_deduction))
		salary_change::change_salary_change(obj);
}

