#pragma once
#include "Time_rate_pay.h"
class hourly_time_rate_pay :public time_rate_pay {
	int norm_working_hours;
	int number_hours_worked; 
public:
	hourly_time_rate_pay();
	hourly_time_rate_pay(employee);
	hourly_time_rate_pay(const hourly_time_rate_pay&);
	~hourly_time_rate_pay();
	int get_norm_working_hours();
	int get_number_hours_worked();
	void set_norm_working_hours(int);
	void set_number_hours_worked(int);
	friend istream& operator >>(istream&, hourly_time_rate_pay&);
	friend ostream& operator <<(ostream&, hourly_time_rate_pay&);
	friend ofstream& operator <<(ofstream&, hourly_time_rate_pay&);
	void calculation_monthly_salary();
};
