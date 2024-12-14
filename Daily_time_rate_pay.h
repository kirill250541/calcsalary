#pragma once
#include "Time_rate_pay.h"
class daily_time_rate_pay :public time_rate_pay {
	int norm_working_days;
	int number_days_worked;
public:
	daily_time_rate_pay();
	daily_time_rate_pay(employee);
	daily_time_rate_pay(const daily_time_rate_pay&);
	~daily_time_rate_pay();
	int get_norm_working_days();
	int get_number_days_worked();
	void set_norm_working_days(int);	
	void set_number_days_worked(int);
	friend istream& operator >>(istream&, daily_time_rate_pay&);
	friend ostream& operator <<(ostream&, daily_time_rate_pay&);
	friend ofstream& operator <<(ofstream&, daily_time_rate_pay&);
	void calculation_monthly_salary();
};
