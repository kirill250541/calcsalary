#include "Salary_calculation.h"

salary_calculation::salary_calculation() {
	month_salary = 0;
	year_salary = 0;
	tax = 0;
	rate = 0;
	prepayment = 0;
	amount_tax = 0;
	salary = 0;
	polnya_salary = 0;
	month_employment = 0;
	year_employment = 0;
}
salary_calculation::salary_calculation(employee obj) {
	month_salary = 0;
	polnya_salary = 0;
	year_salary = 0;
	tax = obj.get_tax();
	rate = obj.get_rate();
	prepayment = 0;
	amount_tax = 0;
	salary = 0;
	month_employment = obj.get_month_employment();
	year_employment = obj.get_year_employment();
	month_tax_deduction = obj.get_list_tax_deduction();
	month_sal_deduction = obj.get_list_sal_deduction();
	month_sal_supplement = obj.get_list_sal_supplement();
}
salary_calculation::~salary_calculation() {
	month_tax_deduction.delete_list();
	month_sal_deduction.delete_list();
	month_sal_supplement.delete_list();
}

salary_calculation::salary_calculation(salary_calculation& obj) {
	this->month_salary = obj.month_salary;
	this->year_salary = obj.year_salary;
	this->tax = obj.tax;
	this->rate = obj.rate;
	this->prepayment = obj.prepayment;
	this->amount_tax = obj.amount_tax;
	this->salary = obj.salary;
	this->month_employment = obj.month_employment;
	this->year_employment = obj.year_employment;
	this->month_tax_deduction = obj.month_tax_deduction;
	this->month_sal_deduction = obj.month_sal_deduction;
	this->month_sal_supplement = obj.month_sal_supplement;
}

int salary_calculation::get_month_salary() {
	return month_employment;
}
int salary_calculation::get_year_salary() {
	return year_employment;
}
float salary_calculation::get_rate() {
	return rate;
}
float salary_calculation::get_tax() {
	return tax;
}
int salary_calculation::get_month_employment() {
	return month_employment;
}
int salary_calculation::get_year_employment() {
	return year_employment;
}

float salary_calculation::get_prepayment() {
	return prepayment;
}

float salary_calculation::get_amount_tax() {
	return amount_tax;
}
float salary_calculation::get_salary() {
	return salary;
}
float salary_calculation::get_polnya_salary() {
	return polnya_salary;
}
tax_deduction& salary_calculation::get_month_tax_deduction(int i) {
	return month_tax_deduction[i];
}
salary_deduction& salary_calculation::get_month_sal_deduction(int i) {
	return month_sal_deduction[i];
}
salary_supplement& salary_calculation::get_month_sal_supplement(int i) {
	return month_sal_supplement[i];
}
int salary_calculation::get_size_list_month_tax_deduction() {
	return month_tax_deduction.size();
}
int salary_calculation::get_size_list_month_sal_deduction() {
	return month_sal_deduction.size();
}
int salary_calculation::get_size_list_month_sal_supplement() {
	return month_sal_supplement.size();
}

void salary_calculation::set_month_salary(int var) {
	month_salary = var;
}
void salary_calculation::set_year_salary(int var) {
	year_salary = var;
}
void salary_calculation::set_tax(float var) {
	tax = var;
}
void salary_calculation::set_rate(float var) {
	rate = var;
}
void salary_calculation::set_prepayment(float var) {
	prepayment = var;
}
void salary_calculation::set_amount_tax(float var) {
	amount_tax = var;
}
void salary_calculation::set_salary(float var) {
	salary = var;
}
void salary_calculation::set_polnya_salary(float var) {
	polnya_salary = var;
}
void salary_calculation::set_month_employment(int var) {
	month_employment = var;
}
void salary_calculation::set_year_employment(int var) {
	year_employment = var;
}
void salary_calculation::set_month_tax_deduction(tax_deduction obj) {
	month_tax_deduction.push(obj);
}
void salary_calculation::set_month_sal_deduction(salary_deduction obj) {
	month_sal_deduction.push(obj);
}
void salary_calculation::set_month_sal_supplement(salary_supplement obj) {
	month_sal_supplement.push(obj);
}

ostream& operator << (ostream& os, salary_calculation& obj) {
	for (int i = 0; i < obj.get_size_list_month_sal_supplement(); i++) {
		os << setw(15) << obj.get_month_sal_supplement(i) << endl;
	}
	os << setw(15) << obj.get_polnya_salary() << endl;
	os << "Вычеты:" <<endl;
	os << setw(15)<<obj.get_prepayment() << endl;
	os << setw(15) << obj.get_amount_tax() << endl;
	for (int i = 0; i < obj.get_size_list_month_sal_deduction(); i++) {
		os << setw(15) << obj.get_month_sal_deduction(i) << endl;
	}
	os << setw(15) << obj.get_salary() << endl;
	return os;
}

ofstream& operator << (ofstream& os, salary_calculation& obj) {
	os << setw(15) << obj.get_month_salary();
	os << "." << obj.get_year_salary();
	os << "\n" << obj.get_polnya_salary();
	os << "\n" << obj.get_prepayment();
	os << setw(15) << obj.get_amount_tax();
	os << setw(15) << obj.get_salary();
	os << setw(15) << obj.get_polnya_salary();
	for (int i = 0; i < obj.get_size_list_month_sal_deduction(); i++) {
		os << setw(15) << obj.get_month_sal_deduction(i) << endl;
	}
	for (int i = 0; i < obj.get_size_list_month_sal_supplement(); i++) {
		os << setw(15) << obj.get_month_sal_supplement(i) << endl;
	}
	return os;
}

istream& operator >> (istream& is, salary_calculation& obj) {
	int day = 0, month = 0, year = 0;
	tax_deduction t_d;
	salary_deduction s_d;
	salary_supplement s_s;
	cout << "Введите период, за который нужно рассчитать зарплату:" << endl;
	do {
		cout << "Месяц:" << endl;
		month = Enter_Exception::Creator_month();
		cout << "Год:" << endl;
		year = Enter_Exception::Creator_year();
	} while (Enter_Exception::check_month_year(month, year, obj.get_month_employment(), obj.get_year_employment()));
	obj.set_month_salary(month);
	obj.set_year_salary(year);
	char choice = ' ';
	while (choice != '2') {
		cout << "Ввести налоговый вычет:" << "\n1)Да" << "\n2)Нет" << endl;
		choice = ' ';
		while (choice != '1' && choice != '2')
			choice = _getch();
		if (choice == '1') {
			cin >> t_d;
			obj.set_month_tax_deduction(t_d);
		}
	}
	choice = ' ';
	while (choice != '2') {
		cout << "Ввести штраф/взнос/вычет:" << "\n1)Да" << "\n2)Нет" << endl;
		choice = ' ';
		while (choice != '1' && choice != '2')
			choice = _getch();
		if (choice == '1') {
			cin >> s_d;
			obj.set_month_sal_deduction(s_d);
		}
	}
	choice = ' ';
	while (choice != '2') {
		cout << "Ввести премию/надбавку:" << "\n1)Да" << "\n2)Нет" << endl;
		choice = ' ';
		while (choice != '1' && choice != '2')
			choice = _getch();
		if (choice == '1') {
			cin >> s_s;
			obj.set_month_sal_supplement(s_s);
		}
	}
	return is;
}

void salary_calculation::calculation_monthly_salary() {
	int i = 0;
	salary_supplement s_s;
	float amount_sal_supplement = 0,amount_sal_supplement_w_tax=0, t_salary = 0;

	for (i = 0; i < get_size_list_month_sal_supplement(); i++) {
		s_s = get_month_sal_supplement(i);
		if (s_s.get_taxation())
			amount_sal_supplement += s_s.get_amount();
		if (!s_s.get_taxation())
			amount_sal_supplement_w_tax += s_s.get_amount();
	}
	t_salary = get_salary() + amount_sal_supplement;

	tax_deduction t_d;
	float amount_tax_deduction = 0, t_tax_base = 0;
	for (i = 0; i < get_size_list_month_tax_deduction(); i++) {
		t_d = get_month_tax_deduction(i);
		amount_tax_deduction += t_d.get_tax_deduction_amount();
	}
	t_tax_base= t_salary - amount_tax_deduction;

	float t_amount_tax = 0;
	t_amount_tax = t_tax_base * get_tax()/100;
	set_amount_tax(t_amount_tax);

	t_salary += amount_sal_supplement_w_tax;
	
	salary_deduction s_d;
	float t_salary_deduction = 0;
	for (i = 0; i < get_size_list_month_sal_deduction(); i++) {
		s_d = get_month_sal_deduction(i);
		t_salary_deduction += s_d.get_amount();
	}
	float t_prepayment = 0;
	cout << "Введите сумму предоплаты:" << endl;
	t_prepayment = Enter_Exception::creator_float();
	set_prepayment(t_prepayment);
	t_salary = t_salary - t_salary_deduction - t_amount_tax - t_prepayment;
	set_salary(t_salary);
}