#include "Direct_piece_rate_pay.h"

direct_piece_rate_pay::direct_piece_rate_pay() {
	number_products = 0;
	norm_number_productions = 0;
}
direct_piece_rate_pay::direct_piece_rate_pay(employee obj)
	:piece_rate_pay(),
	salary_calculation(obj) {
	number_products = 0;
	norm_number_productions = 0;
}
direct_piece_rate_pay::direct_piece_rate_pay(const direct_piece_rate_pay& obj) {
	number_products = obj.number_products;
	norm_number_productions = obj.norm_number_productions;
}
direct_piece_rate_pay::~direct_piece_rate_pay() {
}
int direct_piece_rate_pay::get_number_products() {
	return number_products;
}
int direct_piece_rate_pay::get_norm_number_productions() {
	return norm_number_productions;
}
void direct_piece_rate_pay::set_number_products(int var) {
	number_products = var;
}
void direct_piece_rate_pay::set_norm_number_productions(int var) {
	norm_number_productions = var;
}
istream& operator >>(istream& is, direct_piece_rate_pay& obj) {
	if (typeid(obj) == typeid(direct_piece_rate_pay))
		is >> dynamic_cast<piece_rate_pay&>(obj);
	cout << "Введите норму продукции в месяц:" << endl;
	int var = 0;
	var = Enter_Exception::creator_int();
	obj.set_norm_number_productions(var);
	cout << "Введите количество произведенной продукции в месяц:" << endl;
	var = Enter_Exception::creator_int();
	obj.set_number_products(var);
	return is;
}
ostream& operator <<(ostream& os, direct_piece_rate_pay& obj) {
	if (typeid(obj) == typeid(direct_piece_rate_pay))
		os << dynamic_cast<piece_rate_pay&>(obj);
	os << setw(15) << obj.get_number_products();
	os << setw(15) << obj.get_norm_number_productions();
	return os;
}
ofstream& operator <<(ofstream& os, direct_piece_rate_pay& obj) {
	if (typeid(obj) == typeid(direct_piece_rate_pay))
		os << dynamic_cast<piece_rate_pay&>(obj); 
	os << "|" << obj.get_number_products();
	os << "|" << obj.get_norm_number_productions();
	return os;
}
void direct_piece_rate_pay::calculation_monthly_salary() {
	float var = get_number_products() * get_rate();
	set_amount_p_r_p(var);
	if (typeid(*this) == typeid(direct_piece_rate_pay))
		piece_rate_pay::calculation_monthly_salary();
}
