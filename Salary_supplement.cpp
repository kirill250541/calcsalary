#include "Salary_supplement.h"

salary_supplement::salary_supplement()
	:salary_change() {
	amount = 0;
	persentage = 0;
	taxation = false;
}
salary_supplement::salary_supplement(const salary_supplement& obj)
	:salary_change(obj){ 
	this->amount = obj.amount;
	this->persentage = obj.persentage;
	this->taxation = obj.taxation;
}
salary_supplement::~salary_supplement() {

}

float salary_supplement::get_amount() {
	return amount;
}
float salary_supplement::get_persentage() {
	return persentage;
}
bool salary_supplement::get_taxation() {
	return taxation;
}

void salary_supplement::set_amount(float ptr) {
	amount = ptr;
}
void salary_supplement::set_persentage(float ptr) {
	persentage = ptr;
}

void salary_supplement::set_taxation(bool ptr) {
	taxation = ptr;
}

salary_supplement& salary_supplement::operator = (const salary_supplement& obj) {
	if (this == &obj)
		return *this;
	if (typeid(obj) == typeid(salary_supplement)) {
		salary_change::operator = (obj);
	}
	amount = obj.amount;
	persentage = obj.persentage;
	taxation = obj.taxation;
	return *this;
}

bool salary_supplement::operator ==(salary_supplement& obj) {
	if (typeid(obj) == typeid(salary_supplement))
		if (!salary_change::operator ==(obj))
			return false;
	if (get_amount() == obj.get_amount())
		if (get_persentage() == obj.get_persentage())
			if (get_taxation() == obj.get_taxation())
				return true;
	return false;
}
bool salary_supplement::operator !=(salary_supplement& obj) {
	if (typeid(obj) == typeid(salary_supplement))
		if (!salary_change::operator !=(obj))
			return false;
	if (get_amount() != obj.get_amount())
		return true;
	if (get_persentage() != obj.get_persentage())
		return true;
	if (get_taxation() != obj.get_taxation())
		return true;
	return false;
}

istream& operator >> (istream& is, salary_supplement& obj) {
	if (typeid(obj) == typeid(salary_supplement))
		is >> dynamic_cast<salary_change&>(obj);

	char choice = ' ';
	cout << "Налогообложение:" << "\n1)Да" << "\n2)Нет" << endl;
	while (choice !='1' && choice != '2')
		choice = _getch();
	if (choice == '1')
		obj.set_taxation(true);
	if (choice == '2')
		obj.set_taxation(false);
	choice = ' ';
	cout << "1) Процент от заработка" << endl;
	cout << "2) Сумма" << endl;
	while (choice < '1' || choice > '2') 
		choice = _getch();
	float var = 0;
	if (choice == '1'){
		cout << "Введите процент от заработка:" << endl;
		var = Enter_Exception::creator_float();
		obj.set_persentage(var);
	}
	if (choice == '2') {
		cout << "Введите сумму:" << endl;
		var = Enter_Exception::creator_float();
		obj.set_amount(var);
	}
	return is;
}

ostream& operator << (ostream & os, salary_supplement & obj) {
	if (typeid(obj) == typeid(salary_supplement))
		os  << dynamic_cast<salary_change&>(obj);
	if (obj.get_amount())
		os << obj.get_amount();
	if (obj.get_persentage())
		os << obj.get_taxation();
	if (obj.get_persentage())
		os << obj.get_taxation();
	return os;
}

ofstream& operator << (ofstream & os, salary_supplement & obj) {
	if (typeid(obj) == typeid(salary_supplement))
		os << dynamic_cast<salary_change&>(obj);
	os << '|' << obj.get_amount();
	os << '|' << obj.get_persentage();
	os << '|' << obj.get_taxation();
	return os;
}

ifstream& operator >> (ifstream & is, salary_supplement & obj) {
	if (typeid(obj) == typeid(salary_supplement))
		is >> dynamic_cast<salary_change&>(obj);
	string str;
	getline(is, str, '|');
	obj.set_amount(stof(str));
	getline(is, str, '|');
	obj.set_persentage(stof(str));	
	getline(is, str, '|');
	obj.set_taxation(stoi(str));
	return is;
}
void salary_supplement::change_salary_change(salary_supplement& obj) {
	if (typeid(obj) == typeid(salary_supplement))
		salary_change::change_salary_change(obj);
}

void salary_supplement::compare() {

}