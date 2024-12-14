#include "Progressive_piece_rate_pay.h"

progressive_piece_rate_pay::progressive_piece_rate_pay() {
	number_products=0;
	norm_number_productions=0;
	number_productions_excess_norm=0;
	coefficient=0;
}
progressive_piece_rate_pay::progressive_piece_rate_pay(employee obj)
	:piece_rate_pay(),
	salary_calculation(obj){
	number_products = 0;
	norm_number_productions = 0;
	number_productions_excess_norm = 0;
	coefficient = 0;
}
progressive_piece_rate_pay::progressive_piece_rate_pay(const progressive_piece_rate_pay& obj) {
	number_products = obj.number_products;
	norm_number_productions = obj.norm_number_productions;
	number_productions_excess_norm = obj.number_productions_excess_norm;
	coefficient = obj.coefficient;
}
progressive_piece_rate_pay::~progressive_piece_rate_pay() {

}

int progressive_piece_rate_pay::get_number_products() {
	return number_products;
}

int progressive_piece_rate_pay::get_norm_number_productions() {
	return norm_number_productions;
}

int progressive_piece_rate_pay::get_number_productions_excess_norm() {
	return number_productions_excess_norm;
}

float progressive_piece_rate_pay::get_coefficient() {
	return coefficient;
}
void progressive_piece_rate_pay::set_number_products(int var) {
	number_products = var;
}
void progressive_piece_rate_pay::set_norm_number_productions(int var) {
	norm_number_productions = var;
}
void progressive_piece_rate_pay::set_number_productions_excess_norm(int var) {
	number_productions_excess_norm = var;
}
void progressive_piece_rate_pay::set_coefficient(float var) {
	coefficient = var;
}
istream& operator >>(istream& is, progressive_piece_rate_pay& obj) {
	if (typeid(obj) == typeid(progressive_piece_rate_pay))
		is >> dynamic_cast<piece_rate_pay&>(obj);
	cout << "Введите норму продукции в месяц:" << endl;
	int var1 = 0;
	var1 = Enter_Exception::creator_int();
	obj.set_norm_number_productions(var1);
	cout << "Введите количество произведенной продукции в месяц:" << endl;
	var1 = Enter_Exception::creator_int();
	obj.set_number_products(var1);
	cout << "Введите коэффициент:" << endl;
	float var2 = 0;
	var2 = Enter_Exception::creator_float();
	obj.set_coefficient(var2);

	return is;
}
ostream& operator <<(ostream& os, progressive_piece_rate_pay& obj) {
	if (typeid(obj) == typeid(progressive_piece_rate_pay))
		os << dynamic_cast<piece_rate_pay&>(obj);
	os << setw(15) << obj.get_norm_number_productions();
	os << setw(15) << obj.get_number_products();
	os << setw(15) << obj.get_number_productions_excess_norm();
	os << setw(15) << obj.get_coefficient();
	return os;
}
ofstream& operator <<(ofstream& os, progressive_piece_rate_pay& obj) {
	if (typeid(obj) == typeid(progressive_piece_rate_pay))
		os << dynamic_cast<piece_rate_pay&>(obj);
	os << "|" << obj.get_norm_number_productions();
	os << "|" << obj.get_number_products();
	os << "|" << obj.get_number_productions_excess_norm();
	os << "|" << obj.get_coefficient();
	return os;
}
void progressive_piece_rate_pay::calculation_monthly_salary() {
	set_number_productions_excess_norm(abs(get_number_products() - get_norm_number_productions()));
	float var = get_number_products() * get_rate() + get_number_productions_excess_norm() * get_rate()* get_coefficient();
	set_amount_p_r_p(var);
	if (typeid(*this) == typeid(progressive_piece_rate_pay))
		piece_rate_pay::calculation_monthly_salary();
}
