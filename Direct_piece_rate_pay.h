#pragma once
#include "Piece_rate_pay.h"
class direct_piece_rate_pay :public piece_rate_pay {
	int number_products;
	int norm_number_productions;
public:
	direct_piece_rate_pay();
	direct_piece_rate_pay(employee);
	direct_piece_rate_pay(const direct_piece_rate_pay&);
	~direct_piece_rate_pay();
	int get_number_products();
	int get_norm_number_productions();
	void set_number_products(int);
	void set_norm_number_productions(int);
	friend istream& operator >>(istream&, direct_piece_rate_pay&);
	friend ostream& operator <<(ostream&, direct_piece_rate_pay&);
	friend ofstream& operator <<(ofstream&, direct_piece_rate_pay&);
	void calculation_monthly_salary();
};
