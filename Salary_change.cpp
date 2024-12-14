#include "Salary_change.h"

salary_change::salary_change() {
}
salary_change::salary_change(const salary_change& obj) {
	this->name = obj.name;
}
salary_change::~salary_change() {
	name.clear();
}

string salary_change::get_name() {
	return name;
}

void salary_change::set_name(string ptr) {
	if (!name.empty())
		name.clear();
	name = ptr;
}

salary_change& salary_change::operator = (const salary_change& obj) {
	if (this == &obj)
		return *this;
	if (!name.empty())
		name.clear();
	if (!obj.name.empty())
		name = obj.name;
	return *this;
}

bool salary_change::operator <(const salary_change& obj) const {
	if (name < obj.name)
		return true;
	return false;
}

bool salary_change::operator ==(salary_change& obj) {
	if (!obj.get_name().empty() && get_name() == obj.get_name())
			return true;
	return false;
}
bool salary_change::operator !=(salary_change& obj) {
	if (!obj.get_name().empty())
		if (get_name() != obj.get_name())
			return true;
	return false;
}

istream& operator >> (istream& is, salary_change& obj) {
	cout << "Введите название:" << endl;
	string text = Enter_Exception::Creator_Text();
	obj.set_name(text);
	text.clear();
	return is;
}

ostream& operator << (ostream& os, salary_change& obj) {
	os << obj.get_name();
	return os;
}

ofstream& operator << (ofstream& os, salary_change& obj) {
	os << '|' << obj.get_name();
	return os;
}

ifstream& operator >> (ifstream& is, salary_change& obj) {
	string str;
	getline(is, str, '|');
	obj.set_name(str);
	str.clear();
	return is;
}

void salary_change::change_salary_change(salary_change& obj) {
	cout << "Введите название:" << endl;
	string text = Enter_Exception::Creator_Text();
	obj.set_name(text);
	text.clear();
}
