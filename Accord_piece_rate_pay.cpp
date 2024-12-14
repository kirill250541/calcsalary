#include "Accord_piece_rate_pay.h"

accord_piece_rate_pay::accord_piece_rate_pay() {
	dolya_work_month = 0;
	dolya_work_last_month = 0;
}
accord_piece_rate_pay::accord_piece_rate_pay(employee obj)
	:piece_rate_pay(),
	salary_calculation(obj) {
	dolya_work_month = 0;
	dolya_work_last_month = 0;
}
accord_piece_rate_pay::accord_piece_rate_pay(const accord_piece_rate_pay& obj) {
	this->dolya_work_month = obj.dolya_work_month;
	this->dolya_work_last_month = obj.dolya_work_last_month;
}
accord_piece_rate_pay::~accord_piece_rate_pay() {

}
float accord_piece_rate_pay::get_dolya_work_month() {
	return dolya_work_month;
}
float accord_piece_rate_pay::get_dolya_work_last_month() {
	return dolya_work_last_month;
}
void accord_piece_rate_pay::set_dolya_work_month(float var) {
	dolya_work_month = var;
}
void accord_piece_rate_pay::set_dolya_work_last_month(float var) {
	dolya_work_last_month = var;
}
istream& operator >>(istream& is, accord_piece_rate_pay& obj) {
	if (typeid(obj) == typeid(accord_piece_rate_pay))
		is >> dynamic_cast<piece_rate_pay&>(obj);
	cout << "Введите процент выполненной работы в месяце:" << endl;
	float var = Enter_Exception::creator_float();
	obj.set_dolya_work_month(var);
	cout << "Введите процент выполненной работы в прошлом месяце:" << endl;
	var = Enter_Exception::creator_float();
	obj.set_dolya_work_last_month(var);
	return is;
}

ostream& operator <<(ostream& os, accord_piece_rate_pay& obj) {
	if (typeid(obj) == typeid(accord_piece_rate_pay))
		os << dynamic_cast<piece_rate_pay&>(obj);
	os << setw(15) << obj.get_dolya_work_month();
	os << setw(15) << obj.get_dolya_work_last_month();
	return os;
}
ofstream& operator <<(ofstream& os, accord_piece_rate_pay& obj) {
	if (typeid(obj) == typeid(accord_piece_rate_pay))
		os << dynamic_cast<piece_rate_pay&>(obj);
	os << "|" << obj.get_dolya_work_month();
	os << "|" << obj.get_dolya_work_last_month();
	return os;
}
void accord_piece_rate_pay::calculation_monthly_salary() {
	float var =(get_dolya_work_month()- get_dolya_work_last_month()) * get_rate();
	set_amount_p_r_p(var);
	if (typeid(*this) == typeid(accord_piece_rate_pay))
		piece_rate_pay::calculation_monthly_salary();
}