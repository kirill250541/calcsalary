#include "Time_rate_pay.h"

time_rate_pay::time_rate_pay() {
	amount_t_r_p = 0;
}
time_rate_pay::time_rate_pay(const time_rate_pay& obj) {
	amount_t_r_p = obj.amount_t_r_p;
}
time_rate_pay::~time_rate_pay() {

}
float time_rate_pay::get_amount_t_r_p() {
	return amount_t_r_p;
}
void time_rate_pay::set_amount_t_r_p(float var) {
	amount_t_r_p = var;
}
istream& operator >> (istream& is, time_rate_pay& obj) {
	//if (typeid(obj) == typeid(time_rate_pay))
	is >> dynamic_cast<salary_calculation&>(obj);
	return is;
}
ostream& operator << (ostream& os, time_rate_pay& obj) {
	if (typeid(obj) == typeid(time_rate_pay))
		os << dynamic_cast<salary_calculation&>(obj);
	return os;
}
ofstream& operator << (ofstream& os, time_rate_pay& obj) {
	if (typeid(obj) == typeid(time_rate_pay))
		os << dynamic_cast<salary_calculation&>(obj);
	return os;
}
void time_rate_pay::calculation_monthly_salary() {
	set_salary(amount_t_r_p);
	//if (typeid(*this) == typeid(time_rate_pay))
		salary_calculation::calculation_monthly_salary();
}