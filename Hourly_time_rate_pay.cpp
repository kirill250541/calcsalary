#include "Hourly_time_rate_pay.h"

hourly_time_rate_pay::hourly_time_rate_pay() {
	norm_working_hours = 0;
	number_hours_worked = 0;
}
hourly_time_rate_pay::hourly_time_rate_pay(employee obj)
	:time_rate_pay(),
	salary_calculation(obj) {
	norm_working_hours = 0;
	number_hours_worked = 0;
}

hourly_time_rate_pay::hourly_time_rate_pay(const hourly_time_rate_pay& obj) {
	norm_working_hours = obj.norm_working_hours;
	number_hours_worked = obj.number_hours_worked;
}
hourly_time_rate_pay::~hourly_time_rate_pay() {

}
int hourly_time_rate_pay::get_norm_working_hours() {
	return norm_working_hours;
}
int hourly_time_rate_pay::get_number_hours_worked() {
	return number_hours_worked;
}
void hourly_time_rate_pay::set_norm_working_hours(int var) {
	norm_working_hours = var;
}
void hourly_time_rate_pay::set_number_hours_worked(int var) {
	number_hours_worked = var;
}
istream& operator >>(istream& is, hourly_time_rate_pay& obj) {
	if (typeid(obj) == typeid(hourly_time_rate_pay))
		is >> dynamic_cast<time_rate_pay&>(obj);
	cout << "Введите норму рабочих часов:" << endl;
	int var = 0;
	var = Enter_Exception::creator_int();
	obj.set_norm_working_hours(var);
	cout << "Введите количество отработанных часов:" << endl;
	var = Enter_Exception::creator_int();
	obj.set_number_hours_worked(var);
	return is;
}
ostream& operator <<(ostream& os, hourly_time_rate_pay& obj) {
	if (typeid(obj) == typeid(hourly_time_rate_pay))
		os << dynamic_cast<time_rate_pay&>(obj);
	os << setw(15) << obj.get_norm_working_hours();
	os << setw(15) << obj.get_number_hours_worked();
	return os;
}
ofstream& operator <<(ofstream& os, hourly_time_rate_pay& obj) {
	if (typeid(obj) == typeid(hourly_time_rate_pay))
		os << dynamic_cast<time_rate_pay&>(obj);
	os << "|" << obj.get_norm_working_hours();
	os << "|" << obj.get_number_hours_worked();
	return os;
}
void hourly_time_rate_pay::calculation_monthly_salary() {
	float var = get_norm_working_hours() * get_rate() / get_number_hours_worked();
	set_amount_t_r_p(var);
	if (typeid(*this) == typeid(hourly_time_rate_pay))
		time_rate_pay::calculation_monthly_salary();
}
