#pragma once
#include "Salary_calculation.h"
class piece_rate_pay : virtual public salary_calculation {
	float amount_p_r_p;
public:
	piece_rate_pay();
	piece_rate_pay(const piece_rate_pay&);
	virtual ~piece_rate_pay();
	float get_amount_p_r_p();
	void set_amount_p_r_p(float);
	friend istream& operator >>(istream&, piece_rate_pay&);
	friend ofstream& operator <<(ofstream&, piece_rate_pay&);
	friend ostream& operator <<(ostream&, piece_rate_pay&);
	void calculation_monthly_salary();
};