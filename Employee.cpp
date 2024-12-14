#include "Employee.h"
using namespace std;

employee::employee() {
	gender = 0;
	b_day.day = 0; b_day.month = 0; b_day.year = 0;
	d_empl.day = 0; d_empl.month = 0; d_empl.year = 0;
	salary_type = 0;
	rate = 0;
	tax = 0;
}
employee::~employee() {
	number_employee.clear();
	first_name.clear();
	last_name.clear();
	patronymic.clear();
	education.clear();
	employee_position.clear(); 
	t_deduction.delete_list();
	sal_deduction.delete_list();
	sal_supplement.delete_list();
}
//���������� ����������� 
employee::employee(const employee& obj) {
	this->number_employee = obj.number_employee;
	this->first_name = obj.first_name;
	this->last_name = obj.last_name;
	this->patronymic = obj.patronymic; 
	this->b_day.day = obj.b_day.day;
	this->b_day.month = obj.b_day.month;
	this->b_day.year = obj.b_day.year;
	this->education = obj.education;
	this->d_empl.day = obj.d_empl.day;
	this->d_empl.month = obj.d_empl.month;
	this->d_empl.year = obj.d_empl.year;
	this->employee_position = obj.employee_position;
	this->salary_type = obj.salary_type;
	this->rate = obj.rate;
	this->tax = obj.tax;
	this->t_deduction = obj.t_deduction;
	this->sal_deduction = obj.sal_deduction;
	this->sal_supplement = obj.sal_supplement;
}

string employee::get_number_employee() {
	return number_employee;
}
string employee::get_last_name() {
	return last_name;
}
string employee::get_first_name() {
	return first_name;
}
string employee::get_patronymic() {
	return patronymic;
}
int employee::get_gender() {
	return gender;
}
int employee::get_day_birthday() {
	return b_day.day;
}
int employee::get_month_birthday() {
	return b_day.month;
}
int employee::get_year_birthday() {
	return b_day.year;
}
string employee::get_education() {
	return education;
}
int employee::get_day_employment() {
	return d_empl.day;
}
int employee::get_month_employment() {
	return d_empl.month;
}
int employee::get_year_employment() {
	return d_empl.year;
}
string employee::get_employee_position() {
	return employee_position;
}
int employee::get_salary_type() {
	return salary_type;
}
float employee::get_rate() {
	return rate;
}
float employee::get_tax() {
	return tax;
}
List<tax_deduction>& employee::get_list_tax_deduction() {
	return t_deduction;
}
List<salary_deduction>& employee::get_list_sal_deduction(){
	return sal_deduction;
}
List <salary_supplement>& employee::get_list_sal_supplement() {
	return sal_supplement;
}
tax_deduction& employee::get_tax_deduction(int i) {
	return t_deduction[i];
}
salary_deduction& employee::get_sal_deduction(int i) {
	return sal_deduction[i];
}
salary_supplement& employee::get_sal_supplement(int i) {
	return sal_supplement[i];
}
int employee::get_size_list_tax_deduction() {
	return t_deduction.size();
}
int employee::get_size_list_sal_deduction() {
	return sal_deduction.size();
}
int employee::get_size_list_sal_supplement() {
	return sal_supplement.size();
}

void employee::set_number_employee(string ptr) {
	if (!number_employee.empty()) {
		number_employee.clear();
	}
	number_employee = ptr;
}
void employee::set_last_name(string ptr) {
	if (!last_name.empty()) {
		last_name.clear();
	}
	last_name = ptr;
}
void employee::set_first_name(string ptr) {
	if (!first_name.empty()) {
		first_name.clear();
	}
	first_name = ptr;
}
void employee::set_patronymic(string ptr) {
	if (!patronymic.empty()) {
		patronymic.clear();
	}
	patronymic = ptr;
}
void employee::set_gender(int var) {
	gender = var;
}
void employee::set_day_birthday(int var) {
	b_day.day = var;
}
void employee::set_month_birthday(int var) {
	b_day.month = var;
}
void employee::set_year_birthday(int var) {
	b_day.year = var;
}
void employee::set_education(string ptr) {
	if (!education.empty()) {
		education.clear();
	}
	education = ptr;
}
void employee::set_day_employment(int var) {
	d_empl.day = var;
}
void employee::set_month_employment(int var) {
	d_empl.month = var;
}
void employee::set_year_employment(int var) {
	d_empl.year = var;
}
void employee::set_employee_position(string ptr) {
	if (!employee_position.empty()) {
		employee_position.clear();
	}
	employee_position = ptr;
}
void employee::set_salary_type(int var) {
	salary_type = var;
}
void employee::set_rate(float var) {
	rate = var;
}
void employee::set_tax(float var) {
	tax = var;
}
void employee::set_tax_deduction(tax_deduction obj) {
	t_deduction.push(obj);
}
void employee::set_sal_deduction(salary_deduction obj) {
	sal_deduction.push(obj);

}
void employee::set_sal_supplement(salary_supplement obj) {
	sal_supplement.push(obj);

}

bool employee::operator ==(employee& obj) {
	if (!obj.get_number_employee().empty() && get_number_employee() == obj.get_number_employee()) 
		return true;
	if (!obj.get_last_name().empty() && get_last_name() == obj.get_last_name()) 
		return true;
	if (!obj.get_first_name().empty() && get_first_name() == obj.get_first_name()) 
		return true;
	if (!obj.get_patronymic().empty() && get_patronymic() == obj.get_patronymic()) 
		return true;
	if (!obj.get_education().empty() && get_education() == obj.get_education()) 
		return true;
	if (!obj.get_employee_position().empty() && get_employee_position() == obj.get_employee_position())
		return true;
	if (obj.get_gender() && get_gender() == obj.get_gender()) 
		return true;
	if (obj.get_day_birthday() && get_day_birthday() == obj.get_day_birthday())
		return true;
	if (obj.get_month_birthday() && get_month_birthday() == obj.get_month_birthday())
		return true;
	if (obj.get_year_birthday() && get_year_birthday() == obj.get_year_birthday())
		return true;
	if (obj.get_day_employment() && get_day_employment() == obj.get_day_employment())
		return true;
	if (obj.get_month_employment() && get_month_employment() == obj.get_month_employment())
		return true;
	if (obj.get_year_employment() && get_year_employment() == obj.get_year_employment())
		return true;
	if (obj.get_salary_type() && get_salary_type() == obj.get_salary_type())
		return true;
	if (obj.get_rate() && get_rate() == obj.get_rate()) 
		return true;
	if (obj.get_tax() && get_tax() == obj.get_tax()) 
		return true;
	if (obj.get_size_list_tax_deduction() && get_list_tax_deduction() == obj.get_list_tax_deduction())
		return true;
	if (obj.get_size_list_sal_deduction() &&get_list_sal_deduction() == obj.get_list_sal_deduction())
		return true;
	if (obj.get_size_list_sal_supplement() && get_list_sal_supplement() == obj.get_list_sal_supplement())
		return true;

	return false;
}
bool employee::operator !=(employee& obj) {
	if (get_number_employee() != obj.get_number_employee())
		return true;
	if (get_last_name() != obj.get_last_name())
		return true;
	if (get_first_name() != obj.get_first_name())
		return true;
	if (get_patronymic() != obj.get_patronymic())
		return true;
	if (get_employee_position() != obj.get_employee_position())
		return true;
	if (get_gender() != obj.get_gender())
		return true;
	if (get_day_birthday() != obj.get_day_birthday())
		return true;
	if (get_month_birthday() != obj.get_month_birthday())
		return true;
	if (get_year_birthday() != obj.get_year_birthday())
		return true;
	if (get_education() != obj.get_education())
		return true;
	if (get_day_employment() != obj.get_day_employment())
		return true;
	if (get_month_employment() != obj.get_month_employment())
		return true;
	if (get_year_employment() != obj.get_year_employment())
		return true;
	if (get_salary_type() != obj.get_salary_type())
		return true;
	if (get_rate() != obj.get_rate())
		return true;
	if (get_tax() != obj.get_tax())
		return true;
	if (get_list_tax_deduction() != obj.get_list_tax_deduction())
		return true;
	if (get_list_sal_deduction() != obj.get_list_sal_deduction())
		return true;
	if (get_list_sal_supplement() != obj.get_list_sal_supplement())
		return true;

	return false;
}

employee& employee::operator = (const employee& obj) {
	if (this == &obj)
		return *this;
	if (!number_employee.empty()) 
		number_employee.clear();
	if (!last_name.empty()) 
		last_name.clear();
	if (!first_name.empty()) 
		first_name.clear();
	if (!patronymic.empty()) 
		patronymic.clear();
	if (!education.empty())
		education.clear();	
	if (!employee_position.empty())
		employee_position.clear();

	if (!obj.number_employee.empty())
		number_employee = obj.number_employee;
	if (!obj.last_name.empty())
		last_name = obj.last_name;
	if (!obj.first_name.empty())
		first_name = obj.first_name;
	if (!obj.patronymic.empty())
		patronymic = obj.patronymic;
	if (!obj.education.empty())
		education = obj.education;
	if (!obj.employee_position.empty())
		employee_position = obj.employee_position;
	t_deduction = obj.t_deduction;
	sal_deduction = obj.sal_deduction;
	sal_supplement = obj.sal_supplement;
	
	gender = obj.gender;
	b_day.day = obj.b_day.day;
	b_day.month = obj.b_day.month;
	b_day.year = obj.b_day.year;
	d_empl.day = obj.d_empl.day;
	d_empl.month = obj.d_empl.month;
	d_empl.year = obj.d_empl.year;
	salary_type = obj.salary_type;
	rate = obj.rate;
	tax = obj.tax;

	return *this;
}

ostream& operator << (ostream& os, employee& obj) {
	//������� ������ �� �����
	os << setw(15) << obj.get_number_employee();
	os << setw(15) << obj.get_last_name();
	os << setw(15) << obj.get_first_name();
	os << setw(15) << obj.get_patronymic();
	os << setw(15) << obj.get_gender();
	os << setw(15) << obj.get_day_birthday();
	os << "." << obj.get_month_birthday();
	os << "." << obj.get_year_birthday();
	os << setw(15) << obj.get_education();
	os << setw(15) << obj.get_day_employment();
	os << "." << obj.get_month_employment();
	os << "." << obj.get_year_employment();
	os << setw(15) << obj.get_employee_position();
	os << setw(15) << obj.get_salary_type();
	os << setw(15) << obj.get_rate();
	os << setw(15) << obj.get_tax() << endl;
	os << setw(15) << "Налоговый вычет" << endl;
	for (int i = 0; i < obj.get_size_list_tax_deduction(); i++) 
		os << setw(15) << obj.get_tax_deduction(i);
	os << setw(15) << "Взнос/вычет/штраф" << endl;
	for (int i = 0; i < obj.get_size_list_sal_deduction(); i++) 
		os << setw(15) << obj.get_sal_deduction(i);
	os << setw(15) << "Добавка/премия" << endl;
	for (int i = 0; i < obj.get_size_list_sal_supplement(); i++) 
		os << setw(15) << obj.get_sal_supplement(i);
	return os;
}

ofstream& operator << (ofstream& os, employee& obj) {
	//���������� ������ � ����
	os << '|' << obj.get_number_employee();
	os << '|' << obj.get_last_name();
	os << '|' << obj.get_first_name();
	os << '|' << obj.get_patronymic();
	os << '|' << obj.get_gender();
	os << '|' << obj.get_day_birthday();
	os << '|' << obj.get_month_birthday();
	os << '|' << obj.get_year_birthday();
	os << '|' << obj.get_education();
	os << '|' << obj.get_day_employment();
	os << '|' << obj.get_month_employment();
	os << '|' << obj.get_year_employment();
	os << '|' << obj.get_employee_position();
	os << '|' << obj.get_salary_type();
	os << '|' << obj.get_rate();
	os << '|' << obj.get_tax();
	os << '|' << obj.get_size_list_tax_deduction();
	for (int i = 0; i < obj.get_size_list_tax_deduction(); i++) {
		os << obj.get_tax_deduction(i);
	}
	os << '|' << obj.get_size_list_sal_deduction();
	for (int i = 0; i < obj.get_size_list_sal_deduction(); i++) {
		os << obj.get_sal_deduction(i);
	}
	os << '|' << obj.get_size_list_sal_supplement();
	for (int i = 0; i < obj.get_size_list_sal_supplement(); i++) {
		os << obj.get_sal_supplement(i);
	}
	os << '|' << endl;
	return os;
}

istream& operator >> (istream& is, employee& obj) {
	string text;
	int day = 0, month = 0, year = 0, var_int=0;
	float var_float;
	tax_deduction t_d;
	salary_deduction s_d;
	salary_supplement s_s;

	cout << "Введите номер карточки рабоника:" << endl;
	text = Enter_Exception::Creator_Text_and_Number();
	obj.set_number_employee(text);
	text.clear();
	cout << "Введите фамилию работника:" << endl;
	text = Enter_Exception::Creator_Text();
	obj.set_last_name(text);
	text.clear();
	cout << "Введите имя работника:" << endl;
	text = Enter_Exception::Creator_Text();
	obj.set_first_name(text);
	text.clear();
	cout << "Введите отчество работника:" << endl;
	text = Enter_Exception::Creator_Text();
	obj.set_patronymic(text);
	text.clear();
	cout << "Введите пол работника:" << endl;
	var_int = Enter_Exception::Creator_gender();
	obj.set_gender(var_int);
	do {
		cout << "Введите дату рождения:"<<"/n"<<"День:" << endl;
		day = Enter_Exception::Creator_day();
		cout << "Месяц:" << endl;
		month = Enter_Exception::Creator_month();
		cout << "Год:" << endl;
		year = Enter_Exception::Creator_year();
	} while (Enter_Exception::check_day_month_year(day, month, year));
	obj.set_day_birthday(day);
	obj.set_month_birthday(month);
	obj.set_year_birthday(year);
	day = month = year = 0;
	cout << "Введите уровень образования работника:" << endl;
	text = Enter_Exception::Creator_education();
	obj.set_education(text);
	text.clear();
	 do{
		cout << "Введите дату трудоустройства:" << "/nДень:" << endl;
		text = Enter_Exception::Creator_day();
		cout << "Месяц:" << endl;
		text = Enter_Exception::Creator_month();
		cout << "Год:" << endl;
		text = Enter_Exception::Creator_year();
	 } while (Enter_Exception::check_day_month_year(day,month,year));
	 obj.set_day_employment(day);
	 obj.set_month_employment(month);
	 obj.set_year_employment(year);
	cout << "Введите должность работника:" << endl;
	text = Enter_Exception::Creator_Text();
	obj.set_employee_position(text);
	text.clear();
	cout << "Введите тип зарплаты работника:" << endl;
	var_int = Enter_Exception::Creator_type_rate();
	obj.set_salary_type(var_int);
	cout << "Введите оклад/ставку/тариф:" << endl;
	var_float = Enter_Exception::creator_float();
	obj.set_rate(var_float);
	cout << "Введите индивидуальный налог работника:" << endl;
	var_float = Enter_Exception::creator_float();
	obj.set_tax(var_float);
	text.clear();
	char choice = ' ';
	while (choice != '2') {
		cout << "Ввести налоговый вычет:"<<"\n1)Да"<<"\n2)Нет" << endl;
		choice = ' ';
		while (choice != '1' && choice != '2')
			choice = _getch();
		if (choice == '1') {
			cin >> t_d;
			obj.set_tax_deduction(t_d);
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
			obj.set_sal_deduction(s_d);
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
			obj.set_sal_supplement(s_s);
		}
	}
	return is;
}

ifstream& operator >> (ifstream& is, employee& obj) {
	//��������� �� ����� ������
	string str;
	is.get();
	getline(is, str, '|');
	obj.set_number_employee(str);
	str.clear();
	getline(is, str, '|');
	obj.set_last_name(str);
	str.clear();
	getline(is, str, '|');
	obj.set_first_name(str);
	str.clear();
	getline(is, str, '|');
	obj.set_patronymic(str);
	str.clear();
	getline(is, str, '|');
	obj.set_gender(stoi(str));
	str.clear();
	getline(is, str, '|');
	obj.set_day_birthday(stoi(str));
	str.clear();
	getline(is, str, '|');
	obj.set_month_birthday(stoi(str));
	str.clear();
	getline(is, str, '|');
	obj.set_year_birthday(stoi(str));
	str.clear();
	getline(is, str, '|');
	obj.set_education(str);
	str.clear();
	getline(is, str, '|');
	obj.set_day_employment(stoi(str));
	str.clear();
	getline(is, str, '|');
	obj.set_month_employment(stoi(str));
	str.clear();
	getline(is, str, '|');
	obj.set_year_employment(stoi(str));
	str.clear();
	getline(is, str, '|');
	obj.set_employee_position(str);
	str.clear();
	getline(is, str, '|');
	obj.set_salary_type(stoi(str));
	str.clear();
	getline(is, str, '|');
	obj.set_rate(stof(str));
	str.clear();
	getline(is, str, '|');
	obj.set_tax(stof(str));
	str.clear();


	int size = 0;
	getline(is, str, '|');
	size=stoi(str);
	str.clear();
	tax_deduction t_d;
	for (int i = 0; i < size; i++) {
		getline(is, str, '|');
		t_d.set_name(str);
		str.clear();
		getline(is, str, '|');
		t_d.set_tax_deduction_amount(stof(str));
		str.clear();
		obj.set_tax_deduction(t_d);
	}

	getline(is, str, '|');
	size = stoi(str);
	str.clear();
	salary_deduction s_d;
	for (int i = 0; i < size; i++) {
		getline(is, str, '|');
		s_d.set_name(str);
		str.clear();
		getline(is, str, '|');
		s_d.set_amount(stof(str));
		str.clear();
		getline(is, str, '|');
		s_d.set_persentage(stof(str));
		str.clear();
		obj.set_sal_deduction(s_d);
	}

	getline(is, str, '|');
	size = stoi(str);
	str.clear();
	salary_supplement s_s;
	for (int i = 0; i < size; i++) {
		getline(is, str, '|');
		s_s.set_name(str);
		str.clear();
		getline(is, str, '|');
		s_s.set_amount(stof(str));
		str.clear();
		getline(is, str, '|');
		s_s.set_persentage(stof(str));
		str.clear();
		getline(is, str, '|');
		s_s.set_taxation(stoi(str));
		str.clear();
		obj.set_sal_supplement(s_s);
	}
	is.get();
	return is;
}

int employee::parameters(int i) {
	char choice = ' ';
	int var = 0, number =0;
	system("cls");
	cout << "\t\tВыберите параметр" << endl << endl;
	cout << ++number << ") Номер карточки работника." << endl;
	cout << ++number << ") Фамилия работника." << endl;
	cout << ++number << ") Имя работника." << endl;
	cout << ++number << ") Отчество работника." << endl;
	cout << ++number << ") Пол." << endl;
	cout << ++number << ") Дата рождения работника." << endl;
	cout << ++number << ") Образование работника." << endl;
	cout << ++number << ") Дата трудоустройства." << endl;
	cout << ++number << ") Должность работника." << endl;
	cout << ++number << ") Тип зарплаты работника." << endl;
	cout << ++number << ") Оклад/ставку/тариф работника:" << endl;
	cout << ++number << ") Индивидкальный налог работника." << endl;
	if (i == 0) {
		cout << ++number << ") Налоговый вычет." << endl;
		cout << ++number << ") Штраф/взнос/вычет." << endl;
		cout << ++number << ") Премия/надбавка." << endl;
	}
	cout << ++number << ") Отмена." << endl;
	cout << endl << "Выберите нужный пункт:" << endl;
	while (((var < 1 || var > 16) && i==0) || ((var < 1 || var > 13) && i == 1)) {
		var = Enter_Exception::creator_int();
	}
	return var;
}

template<typename T>
void employee::change_list(List<T>& obj, int i) {
	string name;
	T value;
	int choice = 0, number = 0;
	if (i == 1)
		name = "налоговый вычет";
	if (i == 2)
		name = "штраф/взнос/вычет";
	if (i == 3)
		name = "премию/надбавку";

	while (choice != '4') {
		choice = 0;
		obj.show();
		cout << "1) Добавить " << name << endl;
		cout << "2) Удалить " << name << endl;
		cout << "3) Удалить список" << endl;
		cout << "4) �����" << endl;
		while (choice < '1' || choice > '4') {
			choice = _getch();
		}
		if (choice == '1') {
			cin >> value;
			obj.push(value);
		}
		if (choice == '2') {
			value.change_salary_change(value);
			obj.find_and_delete(value);
		}
		if (choice == '3') {
			obj.delete_list();
		}
	}
}
void employee::change_employee(employee& obj, int number) {
	string text;
	int day = 0, month = 0, year = 0, var_int = 0;
	float var_float;
	switch (number) {
	case 1:
		cout << "Введите номер карточки рабоника:" << endl;
		text = Enter_Exception::Creator_Text_and_Number();
		obj.set_number_employee(text);
		text.clear();
		break;
	case 2:
		cout << "Введите фамилию работника:" << endl;
		text = Enter_Exception::Creator_Text();
		obj.set_last_name(text);
		text.clear();
		break;
	case 3:
		cout << "Введите имя работника:" << endl;
		text = Enter_Exception::Creator_Text();
		obj.set_first_name(text);
		text.clear();
		break;
	case 4:
		cout << "Введите отчество работника:" << endl;
		text = Enter_Exception::Creator_Text();
		obj.set_patronymic(text);
		text.clear();
		break;
	case 5:
		cout << "Введите пол работника:" << endl;
		var_int = Enter_Exception::Creator_gender();
		obj.set_gender(var_int);
		break;
	case 6:
		do {
			cout << "Введите дату рождения:" << "/n" << "День:" << endl;
			day = Enter_Exception::Creator_day();
			cout << "Месяц:" << endl;
			month = Enter_Exception::Creator_month();
			cout << "Год:" << endl;
			year = Enter_Exception::Creator_year();
		} while (Enter_Exception::check_day_month_year(day, month, year));
		obj.set_day_birthday(day);
		obj.set_month_birthday(month);
		obj.set_year_birthday(year);
		break;
	case 7:
		cout << "Введите уровень образования работника:" << endl;
		text = Enter_Exception::Creator_education();
		obj.set_education(text);
		text.clear();
		break;
	case 8:
		do {
			cout << "Введите дату трудоустройства:" << "/nДень:" << endl;
			text = Enter_Exception::Creator_day();
			cout << "Месяц:" << endl;
			text = Enter_Exception::Creator_month();
			cout << "Год:" << endl;
			text = Enter_Exception::Creator_year();
		} while (Enter_Exception::check_day_month_year(day, month, year));
		obj.set_day_employment(day);
		obj.set_month_employment(month);
		obj.set_year_employment(year);
		break;
	case 9:
		cout << "Введите должность работника:" << endl;
		text = Enter_Exception::Creator_Text();
		obj.set_employee_position(text);
		text.clear();
		break;
	case 10:
		cout << "Введите тип зарплаты работника:" << endl;
		var_int = Enter_Exception::Creator_type_rate();
		obj.set_salary_type(var_int);
		break;
	case 11:
		cout << "Введите оклад/ставку/тариф:" << endl;
		var_float = Enter_Exception::creator_float();
		obj.set_rate(var_float);
		break;
	case 12:
		cout << "Введите индивидуальный налог работника:" << endl;
		var_float = Enter_Exception::creator_float();
		obj.set_tax(var_float);
		text.clear();
		break;
	case 13:
		obj.change_list(obj.t_deduction, 1);
		break;
	case 14:
		obj.change_list(obj.sal_deduction, 2);
		break;
	case 15:
		obj.change_list(obj.sal_deduction, 3);
		break;
	}

}	

bool employee::parameter_selection(employee& obj) {
	int number= 0;
	number = obj.parameters(0);
	if (number != 16) {
		obj.change_employee(obj, number);
		return true;
	}
	return false;
}



bool employee::compare(int number_par,employee& obj) {
	if (number_par == 1 && get_number_employee() < obj.get_number_employee())
		return true;
	if (number_par == 2 && get_last_name() < obj.get_last_name())
		return true;
	if (number_par == 3 && get_first_name() < obj.get_first_name())
		return true;
	if (number_par == 4 && get_patronymic() < obj.get_patronymic())
		return true;
	if (number_par == 5 && get_gender() < obj.get_gender())
		return true;
	if (number_par == 6 && get_year_birthday() <= obj.get_year_birthday()) {
		if (get_year_birthday() == obj.get_year_birthday()) {
			if (get_month_birthday() <= obj.get_month_birthday()) {
				if (get_month_birthday() == obj.get_month_birthday()) {
					if (get_day_birthday() < obj.get_day_birthday())
						return true;
				}
				return true;
			}
		}
		return true;
	}
	if (number_par == 7 &&get_education() < obj.get_education())
		return true;
	if (number_par == 8 && get_year_employment() <= obj.get_year_employment()) {
		if (get_year_employment() == obj.get_year_employment()) {
			if (get_month_employment() <= obj.get_month_employment()) {
				if (get_month_employment() == obj.get_month_employment()) {
					if (get_day_employment() < obj.get_day_employment())
						return true;
				}
				return true;
			}
		}
		return true;
	}
	if (number_par == 9 && get_employee_position() < obj.get_employee_position())
		return true;
	if (number_par == 10 && get_salary_type() < obj.get_salary_type())
		return true;
	if (number_par == 11 && get_rate() < obj.get_rate())
		return true;
	if (number_par == 12 && get_tax() < obj.get_tax())
		return true;
		
	return false;
}