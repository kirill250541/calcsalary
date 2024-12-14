#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stack>
#include <vector>
#include "Exceptions.h"
using namespace std;
//���������
template <typename T>
class List {
private:
	//������� ������
	struct node {
		T value;
		node* next;
		node* previous;
	}*head;
public:
	List();
	~List();
	bool push(T&);
	void pop();
	int size();
	T& find(T&);
	bool find_and_delete(T&);
	void find_and_show(T&);
	bool find_and_change(T&);
	void show();
	void sort(int);
	void write_list();
	void read_list();
	bool delete_list();
	void Cancel_Action();
	bool operator ==(List<T>&);
	bool operator !=(List<T>&);
	T& operator [] (int);
	List<T>& operator =(const List<T>&);

	class iterator {
	private:
		node* ptr;
	public:
		iterator() {
			ptr = nullptr;
		}
		void set_ptr(node* tmp) {
			ptr = tmp;
		}
		iterator& operator ++ (int) {
			if (ptr == nullptr) {
				return *this;
			}
			ptr = ptr->next;
			return *this;
		}
		iterator& operator -- (int) {
			if (ptr == nullptr) {
				return *this;
			}
			ptr = ptr->previous;
			return *this;
		}
		T& operator *() {
			return ptr->value;
		}
		bool operator != (iterator& obj) {
			if (ptr == obj.ptr)
				return false;
			return true;
		}
		bool operator == (iterator& obj) {
			if (ptr == obj.ptr)
				return true;
			return false;
		}
	};
	iterator& get_begin() {
		begin.set_ptr(head);
		return begin;
	}
	iterator& get_end() {
		end.set_ptr(nullptr);
		return end;
	}
private:
	iterator begin, end;
	//�������� �� ������ ��������
	stack<T> obj1_stack;
	//�������� �� ����� ��������
	stack<T> obj2_stack;
	stack<int> type_stack;
};
template <typename T>
List<T>::List() {
	head = nullptr;
}
template <typename T>
List<T>::~List() {
	delete_list();
	while (!obj1_stack.empty())
		obj1_stack.pop();
	while (!obj2_stack.empty())
		obj2_stack.pop();
	while (!type_stack.empty())
		type_stack.pop();
}
template<class T>
bool List<T>::operator !=(List<T>& obj) {
	List<T>::iterator iter1 = get_begin();
	List<T>::iterator iter2 = obj.get_begin();
	if (iter1 == get_end() && iter2 == get_end())
		return false;
	while (iter1 != get_end() && iter2 != get_end()) {
		if (*iter1 == *iter2)
			return false;
		iter1++;
		iter2++;
	}
	if (iter1 == get_end() && iter2 == get_end())
		return false;
	return true;
}
template<class T>
T& List<T>::operator[] (int i) {
	List<T>::iterator iter = get_begin();
	for (int j = 0; j < i; j++) {
		iter++;
	}
	return *iter;
}
template<class T>
List<T>& List<T>::operator =(const List<T>& obj) {
	if (this == &obj)
		return *this;
	node* ptr_obj = obj.head;
	node* ptr = head;

	if (ptr != nullptr)
		delete_list();

	if (ptr_obj != nullptr) {
		if (ptr == nullptr) {
			ptr = new node;
			ptr->value = ptr_obj->value;
			ptr->next = nullptr;
			ptr->previous = nullptr;
			head = ptr;
		}
		while (ptr_obj->next != nullptr) {
			ptr_obj = ptr_obj->next;
			ptr->next = new node;
			ptr->next->value = ptr_obj->value;
			ptr->next->previous = ptr;
			ptr->next->next = nullptr;
		}
	}
	return *this;
}
template<class T>
bool List<T>::operator ==(List<T>& obj) {
	List<T>::iterator iter1 = get_begin();
	List<T>::iterator iter2 = obj.get_begin();
	while (iter1 != get_end() && iter2 != get_end()) {
		if (*iter1 != *iter2)
			return false;
		iter1++;
		iter2++;
	}
	if (iter1 == get_end() || iter2 == get_end())
		return true;
	return false;
}
template <typename T>
bool List<T>::push(T& var) {
	node* ptr = head;
	List<T>::iterator iter = get_begin();
	bool fl = false;
	if (ptr == nullptr) {
		ptr = new node;
		ptr->value = var;
		ptr->next = nullptr;
		ptr->previous = nullptr;
		head = ptr;
		fl = true;
	}
	else {
		while (ptr->next != nullptr)
			ptr = ptr->next;
		ptr->next = new node;
		ptr->next->value = var;
		ptr->next->previous = ptr;
		ptr->next->next = nullptr;
		fl = true;
	}
	if (fl == true) {
		obj1_stack.push(var);
		type_stack.push(1);
	}
	return fl;
}
template<class T>
void List<T>::pop() {
	node* ptr = head;
	node* ptr2 = head;
	while (ptr != nullptr) {
		if (ptr->value == obj1_stack.top()) {
			//�������� �����-����
			if (ptr == head) {
				head = head->next;
				if (head)
					head->previous = nullptr;
				ptr2 = ptr->next;
				delete ptr;
				ptr = ptr2;
			}
			else {
				node* ptr1 = head;
				while (ptr1->next != ptr)
					ptr1 = ptr1->next;
				ptr1->next = ptr->next;
				if (ptr->next != nullptr)
					ptr->next->previous = ptr1;
				ptr2 = ptr->next;
				delete ptr;
				ptr = ptr2;
			}
		}
		else
			ptr = ptr->next;
	}
}
template<class T>
T& List<T>::find(T& obj) {
	List<T>::iterator iter = get_begin();
	if (iter == get_end()) {
		cout << "Список пуст." << endl;
		return obj;
	}
	int item_number=0;
	vector<int> item_numbers;
	int j = 0;
	while (iter != get_end()) {
		if (*iter == obj){
			j++;
			cout << j << ") " << *iter << endl;
			item_numbers.push_back(item_number);
		}
		iter++;
		item_number++;
	}
	if (j == 0) {
		cout << "Ничего не найдено"<< endl;
		return obj;
	}
	cout << "Выберите нужное значение : " << endl;
	int var = 0;
	while (var < 1 || var > j) {
		var = Enter_Exception::creator_int();
	}
	iter = get_begin();
	j = var;
	for (item_number = 1; item_number < item_numbers[j-1];item_number++) {
		iter++;
	}
	return *iter;
}
template<class T>
bool List<T>::find_and_delete(T& obj) {
	node* ptr = head;
	node* ptr2 = head;
	if (head == nullptr) {
		cout << "Список пуст." << endl;
		return false;
	}
	int item_number = 0;
	vector<int> item_numbers;
	int j = 0;
	int cancel_number = 0;
	bool fl=false;
	//���� � ����� ���� ������ ������� �������� ��� ������ 3
	//�� ������ ����� �������� ����� ��� ������ 4
	if (type_stack.empty())
		cancel_number = 3;
	else {
		if (type_stack.top() == 3)
			cancel_number = 4;
		else
			cancel_number = 3;
	}
	while (ptr != nullptr) {
		item_number++; 
		if (ptr->value == obj) {
			j++;
			cout << j << ") " << ptr->value << endl;
			item_numbers.push_back(item_number);
		}
		ptr=ptr->next;
	}
	if (j == 0) {
		cout << "Ничего не найдено" << endl;
		return fl;
	}

	cout << "Выберите нужное значение:" << endl;
	int var = 0;
	while (var < 1 || var > j) {
		var = Enter_Exception::creator_int();
	}
	j = var;
		ptr = head;
		for (item_number = 1; item_number < item_numbers[j-1]; item_number++) {
			ptr = ptr->next;
		}
		try {
			if (ptr == head) {
				head = head->next;
				if (head)
					head->previous = nullptr;
				ptr2 = ptr->next;
				obj1_stack.push(ptr->value);
				type_stack.push(cancel_number);
				delete ptr;
				ptr = ptr2;
				fl = true;
			}
			else {
				node* ptr1 = head;
				while (ptr1->next != ptr)
					ptr1 = ptr1->next;
				ptr1->next = ptr->next;
				if (ptr->next != nullptr)
					ptr->next->previous = ptr1;
				ptr2 = ptr->next;
				obj1_stack.push(ptr->value);
				type_stack.push(cancel_number);
				delete ptr;
				ptr = ptr2;
				fl = true;
			}
			if (!fl)
				throw List_Exception(-1);
		}
		catch (List_Exception object) {
			object.what();
		}
	return fl;
}
template<class T>
void List<T>::find_and_show(T& obj) {
	system("cls");
	List<T>::iterator iter = get_begin();
	if (iter == get_end()) {
		cout << "Список пуст." << endl;
		return;
	}
	int fl = 0;
	while (iter != get_end()) {
		if (*iter == obj) {
			//����� �� �����
			fl = 1;
			cout << *iter << endl;
		}
		iter++;
	}
	if (fl == 0)
		cout << "Ничего не найдено" << endl;
}
template <class T>
bool List<T>::find_and_change(T& obj) {
	List<T>::iterator iter = get_begin();
	if (iter == get_end()) {
		cout << "Список пуст." << endl;
		return false;
	}
	bool fl = false;
	while (iter != get_end()) {
		if (*iter == obj){
			obj.parameter_selection(obj);
			obj1_stack.push(*iter);
			type_stack.push(2);
			obj2_stack.push(obj);
			*iter = obj;
			fl = true;
			break;
		}
		iter++;
	}
	return fl;
}
template <class T>
void List<T>::write_list() {
	ofstream file;
	file.open("Employee_list.txt", ios::out | ios::trunc);
	try {
		if (!(file.is_open()))
			throw List_Exception(-2);
	}
	catch (List_Exception object) {
		object.what();
		return;
	}
	List<T>::iterator iter;
	for (iter = get_begin(); iter != get_end(); iter++) {
		file << *iter;
	}
	file << '%';
	file.close();
}
template <class T>
void List<T>::read_list() {
	ifstream file;
	file.open("Employee_list.txt", ios::in);
	try {
		if (!(file.is_open()))
			throw List_Exception(-1);
	}
	catch (List_Exception object) {
		object.what();
		return;
	}
	node* ptr = head;
	List<T>::iterator iter = get_begin();
	bool fl = false;
	T var;
	while (file.peek() != '%') {
		//������ �� �����
		file >> var;
		try {
			if (ptr == nullptr) {
				ptr = new node;
				ptr->value = var;
				ptr->next = nullptr;
				ptr->previous = nullptr;
				head = ptr;
				fl = true;
			}
			else {
				while (ptr->next != nullptr)
					ptr = ptr->next;
				ptr->next = new node;
				ptr->next->value = var;
				ptr->next->previous = ptr;
				ptr->next->next = nullptr;
				fl = true;
			}
			if (!fl)
				throw List_Exception(-1);
		}
		catch (List_Exception object) {
			object.what();
		}
	}
	file.close();
}
template<class T>
void List<T>::show() {
	List<T>::iterator iter = get_begin();
	if (iter == get_end()) {
		cout << "Список пуст." << endl;
		return;
	}
	//����� ������ �� ����� 
	while (iter != get_end()) {
		cout << *iter << endl;
		iter++;
	}
}
template<class T>
int List<T>::size() {
	int size_list = 0;
	List<T>::iterator iter = get_begin();
	if (iter == get_end())
		return size_list; 
	while (iter != get_end()) {
		iter++;
		size_list++;
	}
	return size_list;
}
template <class T>
void List<T>::sort(int number) {
	List<T>::iterator iter1 = get_begin();
	List<T>::iterator iter2 = get_begin();
	if (iter1 == get_end()) {
		cout << "Список пуст." << endl;
		return;
	}
	iter1++;
	while (iter2 != get_end()) {
		while (iter1 != get_end()) {
			if ((*iter1).compare(number,*iter2))
				swap(*iter1, *iter2);
			iter1++;
		}
		iter2++;
		iter1 = iter2;
		iter1++;
	}
}
template<class T>
bool List<T>::delete_list() {
	if (head == nullptr)
		return false;
	while (head != nullptr) {
		node* ptr = head;
		head = head->next;
		delete ptr;
	}
	return true;
}
template<class T>
void List<T>::Cancel_Action() {
	List<T>::iterator iter = get_begin();
	int type = 0;
	if (type_stack.empty()) {
		return;
	}
	type = type_stack.top();
	switch (type) {
	case 1:
		pop();
		type_stack.pop();
		obj1_stack.pop();
		cout << "Отмена добавления элемента." << endl;
		break;
	case 2:
		while (iter != get_end()) {
			if (*iter == obj2_stack.top()) {
				*iter = obj1_stack.top();
				break;
			}
			iter++;
		}
		obj1_stack.pop();
		obj2_stack.pop();
		type_stack.pop();
		cout << "Отмена редактирования элемента." << endl;
		break;
	case 3:
		while (type_stack.top() == 3) {
			push(obj1_stack.top());
			type_stack.pop();
			obj1_stack.pop();
			obj1_stack.pop();
			type_stack.pop();
			if (type_stack.empty())
				break;
		}
		cout << "Удаленный эдемент восстановлен." << endl;
		break;
	case 4:
		while (type_stack.top() == 4) {
			push(obj1_stack.top());
			type_stack.pop();
			obj1_stack.pop();
			obj1_stack.pop();
			type_stack.pop();
			if (type_stack.empty())
				break;
		}
		cout << "Удаленный эдемент восстановлен." << endl;
		break;
	}
}


