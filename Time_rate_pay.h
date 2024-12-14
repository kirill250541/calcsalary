#pragma once
#include "Salary_calculation.h"
class time_rate_pay : virtual public salary_calculation {
	float amount_t_r_p;
public:
	time_rate_pay();
	time_rate_pay(const time_rate_pay&);
	virtual ~time_rate_pay();
	float get_amount_t_r_p();
	void set_amount_t_r_p(float);
	friend istream& operator >>(istream&, time_rate_pay&);
	friend ofstream& operator <<(ofstream&, time_rate_pay&);
	friend ostream& operator <<(ostream&, time_rate_pay&);
	void calculation_monthly_salary();
};