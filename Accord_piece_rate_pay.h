#pragma once
#include "Piece_rate_pay.h"
class accord_piece_rate_pay :public piece_rate_pay {
	float dolya_work_month;
	float dolya_work_last_month;
public:
	accord_piece_rate_pay();
	accord_piece_rate_pay(employee);
	accord_piece_rate_pay(const accord_piece_rate_pay&);
	~accord_piece_rate_pay();
	float get_dolya_work_month();
	float get_dolya_work_last_month();
	void set_dolya_work_month(float);
	void set_dolya_work_last_month(float);
	friend istream& operator >>(istream&, accord_piece_rate_pay&);
	friend ostream& operator <<(ostream&, accord_piece_rate_pay&);
	friend ofstream& operator <<(ofstream&, accord_piece_rate_pay&);
	void calculation_monthly_salary();
};
