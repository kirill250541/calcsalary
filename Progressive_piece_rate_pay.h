#pragma once
#include "Piece_rate_pay.h"
class progressive_piece_rate_pay :public piece_rate_pay {
	int number_products;
	int norm_number_productions;
	int number_productions_excess_norm;
	float coefficient;
public:
	progressive_piece_rate_pay();
	progressive_piece_rate_pay(employee);
	progressive_piece_rate_pay(const progressive_piece_rate_pay&);
	~progressive_piece_rate_pay();
	int get_number_products();	
	int get_norm_number_productions();
	int get_number_productions_excess_norm();
	float get_coefficient();
	void set_number_products(int);	
	void set_norm_number_productions(int);
	void set_number_productions_excess_norm(int);
	void set_coefficient(float);
	friend istream& operator >>(istream&, progressive_piece_rate_pay&);
	friend ostream& operator <<(ostream&, progressive_piece_rate_pay&);
	friend ofstream& operator <<(ofstream&, progressive_piece_rate_pay&);
	void calculation_monthly_salary();
};
