#pragma once

#include <iostream>
#include <conio.h>
#include "Employee.h"
#include "Accord_piece_rate_pay.h"
#include "Daily_time_rate_pay.h"
#include "Direct_piece_rate_pay.h"
#include "Hourly_time_rate_pay.h"
#include "Indirect_piece_rate_pay.h"
#include "Progressive_piece_rate_pay.h"

using namespace std;
class interface {
public:
	void main_menu();
	void employee_menu(List<employee>&);
	void type_calculate_salary(employee);
};