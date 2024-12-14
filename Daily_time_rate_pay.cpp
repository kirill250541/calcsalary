#include "Daily_time_rate_pay.h"

daily_time_rate_pay::daily_time_rate_pay() {
	norm_working_days = 0;
	number_days_worked = 0;
}
daily_time_rate_pay::daily_time_rate_pay(employee obj)
	:time_rate_pay(),
	salary_calculation(obj) {
	norm_working_days = 0;
	number_days_worked = 0;
}
daily_time_rate_pay::daily_time_rate_pay(const daily_time_rate_pay& obj) {
	norm_working_days = obj.norm_working_days;
	number_days_worked = obj.number_days_worked;
}
daily_time_rate_pay::~daily_time_rate_pay() {

}
int daily_time_rate_pay::get_norm_working_days() {
	return norm_working_days;
}
int daily_time_rate_pay::get_number_days_worked() {
	return number_days_worked;
}
void daily_time_rate_pay::set_norm_working_days(int var) {
	norm_working_days = var;
}
void daily_time_rate_pay::set_number_days_worked(int var) {
	number_days_worked = var;
}

istream& operator >>(istream& is, daily_time_rate_pay& obj) {
	if (typeid(obj) == typeid(daily_time_rate_pay))
		is >> dynamic_cast<time_rate_pay&>(obj);
	cout << "Введите норму рабочих дней в месяце:" << endl;
	int var = 0;
	var = Enter_Exception::creator_int();
	obj.set_norm_working_days(var);
	cout << "Введите количество отработанных дней в месяце:" << endl;
	var = Enter_Exception::creator_int();
	obj.set_number_days_worked(var);
	return is;
}
ostream& operator <<(ostream& os, daily_time_rate_pay& obj) {
	if (typeid(obj) == typeid(daily_time_rate_pay))
		os << dynamic_cast<time_rate_pay&>(obj);
	os << setw(15) << obj.get_norm_working_days();
	os << setw(15) << obj.get_number_days_worked();
	return os;
}
ofstream& operator <<(ofstream& os, daily_time_rate_pay& obj) {
	if (typeid(obj) == typeid(daily_time_rate_pay))
		os << dynamic_cast<time_rate_pay&>(obj);
	os << "|" << obj.get_norm_working_days();
	os << "|" << obj.get_number_days_worked();
	return os;
}
void daily_time_rate_pay::calculation_monthly_salary() {
	float var = get_number_days_worked() * get_rate() / get_norm_working_days();
	set_amount_t_r_p(var);
	if (typeid(*this) == typeid(daily_time_rate_pay))
		time_rate_pay::calculation_monthly_salary();
}

