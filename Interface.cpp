#include "Interface.h"
#include "List.h"
#include "Employee.h"

void interface::main_menu() {
	char choice;
	List<employee> list;
	int i = 0,number=0;
	list.read_list();
	while (true) {
		employee value;
		choice = ' ';
		system("cls");
		cout << "\t\tГЛАВНОЕ МЕНЮ" << endl << endl;
		cout << "1) Выбор карточки рабоника." << endl;
		cout << "2) Добавление новой карточки работника." << endl;
		cout << "3) Удаление карточки работника." << endl;
		cout << "4) Поиск по параметру." << endl;
		cout << "5) Показать весь список." << endl;
		cout << "6) Сортировка списка." << endl;
		cout << "7) Отменить действие." << endl;
		cout << "8) Выход." << endl;
		cout << endl << "Выберите нужный пункт:" << endl;
		while (choice < '1' || choice > '8') {
			choice = _getch();
		}
		switch (choice) {
		case '1':
			employee_menu(list);
			system("pause");
			break;
		case '2':
			system("cls");
			try {
				if (!(cin >> value))
					throw Enter_Exception(-5);
			}
			catch (Enter_Exception object) {
				object.what();
				system("pause");
				break;
			}		
			try {
				if (!(list.push(value)))
					throw List_Exception(-1);
			}
			catch (List_Exception object) {
				object.what();
				system("pause");
			}
			system("pause");
			break;
		case '3':
			if (value.parameter_selection(value))
				list.find_and_delete(value);
			system("pause");
			break;
		case '4':
			if (value.parameter_selection(value))
				list.find_and_show(value);	
			system("pause");
			break;
		case '5':
			list.show();
			system("pause");
			break;
		case '6':
			number=value.parameters(1);
			list.sort(number);
			list.show();
			system("pause");
			break;
		case '7':
			list.Cancel_Action();
			system("pause");
			break;
		case '8':
			list.write_list();
			return;
		}
	}
}

void interface::employee_menu(List<employee>& list) {
	char choice;
	int i = 0;
	employee value1, value2;
	if (value1.parameter_selection(value1)) {
		value2 = list.find(value1);
		if (value1 != value2) {
			while (true) {
				choice = ' ';
				system("cls");
				cout << value2 << endl;
				cout << "1) Расчет заработной платы." << endl;
				cout << "2) Редактирование карточки работника." << endl;
				cout << "3) Выход в главное меню." << endl;
				cout << endl << "Выберите нужный пункт: " << endl;
				while (choice < '1' || choice > '3') {
					choice = _getch();
				}
				switch (choice) {
				case '1':
					type_calculate_salary(value2);
					break;
				case '2':
					list.find_and_change(value2);
					break;
				case '3':
					return;
				}
			}
		}
	}
}

void interface::type_calculate_salary(employee obj) {
	int salary_type = 0;
	salary_type = obj.get_salary_type();
	if (salary_type == 1) {
		accord_piece_rate_pay aprs(obj);
		cout << "Аккордная система оплаты труда" << endl;
		cin >> aprs;
		aprs.calculation_monthly_salary();
		cout << aprs;
	}
	if (salary_type == 2) {
		daily_time_rate_pay dtrp(obj);
		cout << "Поденная система оплаты труда" << endl;
		cin >> dtrp;
		dtrp.calculation_monthly_salary();
		cout << dtrp;
	}
	if (salary_type == 3){
		direct_piece_rate_pay dptp(obj);
		cout << "Прамая сдельная система оплаты труда" << endl;
		cin >> dptp;
		dptp.calculation_monthly_salary();
		cout << dptp;
	}
	if (salary_type == 4) {
		hourly_time_rate_pay htrp(obj);	
		cout << "Почасовая система оплаты труда" << endl;
		cin >> htrp;
		htrp.calculation_monthly_salary();
		cout << htrp;
	}
	if (salary_type == 5) {
		indirect_piece_rate_pay iprp(obj);
		cout << "Косвенная сдельная система оплаты труда" << endl;
		cin >> iprp;
		iprp.calculation_monthly_salary();
		cout << iprp;
	}
	if (salary_type == 6) {
		progressive_piece_rate_pay pprp(obj);
		cout << "Прогрессивная сдельная система оплаты труда" << endl;
		cin >> pprp;
		pprp.calculation_monthly_salary();
		cout << pprp;
	}
}


