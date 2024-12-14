#include "Indirect_piece_rate_pay.h"

indirect_piece_rate_pay::indirect_piece_rate_pay() {
	sum_money = 0;
}
indirect_piece_rate_pay::indirect_piece_rate_pay(employee obj)
	: piece_rate_pay(),
	salary_calculation(obj){
	sum_money = 0;
}
indirect_piece_rate_pay::indirect_piece_rate_pay(const indirect_piece_rate_pay& obj) {
	sum_money = obj.sum_money;

}
indirect_piece_rate_pay::~indirect_piece_rate_pay() {

}
float indirect_piece_rate_pay::get_sum_money() {
	return sum_money;
}
void indirect_piece_rate_pay::set_sum_money(float var) {
	sum_money = var;
}
istream& operator >>(istream& is, indirect_piece_rate_pay& obj) {
	if (typeid(obj) == typeid(indirect_piece_rate_pay))
		is >> dynamic_cast<piece_rate_pay&>(obj);
	cout << "Введите сумму заработка отдела:" << endl;
	float var = 0;
	var = Enter_Exception::creator_float();
	obj.set_sum_money(var);
	return is;
}
ostream& operator <<(ostream& os, indirect_piece_rate_pay& obj) {
	if (typeid(obj) == typeid(indirect_piece_rate_pay))
		os << dynamic_cast<piece_rate_pay&>(obj);
	os << setw(15) << obj.get_sum_money();
	return os;
}
ofstream& operator <<(ofstream& os, indirect_piece_rate_pay& obj) {
	if (typeid(obj) == typeid(indirect_piece_rate_pay))
		os << dynamic_cast<piece_rate_pay&>(obj);
	os << "|" << obj.get_sum_money();
	return os;
}
void indirect_piece_rate_pay::calculation_monthly_salary() {
	float var = get_sum_money() * get_rate();
	set_amount_p_r_p(var);
	if (typeid(*this) == typeid(indirect_piece_rate_pay))
		piece_rate_pay::calculation_monthly_salary();
}