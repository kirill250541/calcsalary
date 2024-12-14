#pragma once
#include "Piece_rate_pay.h"
class indirect_piece_rate_pay :public piece_rate_pay {
	float sum_money;
public:
	indirect_piece_rate_pay();
	indirect_piece_rate_pay(employee);
	indirect_piece_rate_pay(const indirect_piece_rate_pay&);
	~indirect_piece_rate_pay();
	float get_sum_money();
	void set_sum_money(float);
	friend istream& operator >>(istream&, indirect_piece_rate_pay&);
	friend ostream& operator <<(ostream&, indirect_piece_rate_pay&);
	friend ofstream& operator <<(ofstream&, indirect_piece_rate_pay&);
	void calculation_monthly_salary();
};
