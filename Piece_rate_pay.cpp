#include "Piece_rate_pay.h"

piece_rate_pay::piece_rate_pay() {
	amount_p_r_p = 0;
}
piece_rate_pay::piece_rate_pay(const piece_rate_pay& obj) {
	amount_p_r_p = obj.amount_p_r_p;
}
piece_rate_pay::~piece_rate_pay() {

}

float piece_rate_pay::get_amount_p_r_p() {
	return amount_p_r_p;
}
void piece_rate_pay::set_amount_p_r_p(float var) {
	amount_p_r_p = var;
}
istream& operator >> (istream& is, piece_rate_pay& obj) {
	//if (typeid(obj) == typeid(piece_rate_pay))
	is >> dynamic_cast<salary_calculation&>(obj);
	return is;
}
ostream& operator << (ostream& os, piece_rate_pay& obj) {
	//if (typeid(obj) == typeid(piece_rate_pay))
		os << dynamic_cast<salary_calculation&>(obj);
	return os;
}
ofstream& operator << (ofstream& os, piece_rate_pay& obj) {
	if (typeid(obj) == typeid(piece_rate_pay))
		os << dynamic_cast<salary_calculation&>(obj);
	return os;
}
void piece_rate_pay::calculation_monthly_salary() {
	set_salary(amount_p_r_p);
	//if (typeid(*this) == typeid(piece_rate_pay))
		salary_calculation::calculation_monthly_salary();
}