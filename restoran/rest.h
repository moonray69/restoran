#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;


class personal {
private:
	string positions;
	string salary;
	string work_schedule;


public:
	personal() {
		positions = "";
		salary = "";
		work_schedule = "";
	}

	personal(const string& positions_, const string& salary_, const string& work_schedule_){
		positions = positions_;
		salary = salary_;
		work_schedule = work_schedule_;

	}

	personal(const personal& other){
		this->positions = other.positions;
		this->salary = other.salary;
		this->work_schedule = other.work_schedule;
	}

	void print()const {
		cout << positions << " " << salary << " " << work_schedule << endl;
	}

	void enter() {
		cout << "enter positions:";
		cin >> positions;
		cout << "enter desired salary: ";
		cin >> salary;
		cout << "enter desired work schedule: ";
		cin >> work_schedule;
	}


};


class dish {
private: 
	string name_dish;
	int cost_dish;
	int weight;

public:
	dish() {
		name_dish = "";
		cost_dish = 0;
		weight = 0;
	}

	dish(const string& name_dish_, int cost_dish_, int weight_) {
		name_dish = name_dish_;
		cost_dish = cost_dish_;
		weight = weight_;
	}

	dish(const dish& other) {
		this->name_dish = other.name_dish;
		this->cost_dish = other.cost_dish;
		this->weight = other.weight;
	}

	void print()const {
		cout << name_dish << " " << cost_dish << " " << weight << endl;
	}
	
	string get_name()const {
		return name_dish;
	}

	void enter() {
		cout << "enter favorite dish:";
		cin >> name_dish;
		cout << "enter price dish : ";
		cin >> cost_dish;
		cout << "enter desired weight: ";
		cin >> weight;
	}
};

class table {
private:
	int number;
	dish* dishes;
	personal people;
	int size;
	int copasity;

public:
	table() : people() {
		number = 0;
		dishes = 0;
		size = 0;
		copasity = 0;
	}

	table(int number_, const personal& people_, int size_) :people(people_) {
		number = number_;
		size = size_;
		dishes = new dish[size];
		copasity = 0;
	}

	table(const table& other) {
		this->number = other.number;
		this->size = other.size;
		this->dishes = new dish[this->size];
		for (int i = 0; i < other.copasity; i++) {
			this->dishes[i] = other.dishes[i];
		}
		this->copasity = other.copasity;
	}
	~table() { delete[]dishes; }

	void print()const {
		cout << number << " "  << copasity << endl;
		for (int i = 0; i < copasity; i++){
			this->dishes[i].print();
		}
		cout << endl;
	}

	void add_dish(const dish& addlock) {
		if (copasity >= size) {
			cout << "overflow ";
			cout << endl;
			return;
		}
		dishes[copasity++] = addlock;

	}

	void del_dish(const string& name_dish) {
		dish* dishess = new dish[this->size - 1];
		int j = 0;
		for (int i = 0; i < copasity; i++){
			if (name_dish != dishes[i].get_name()) {
				dishess[j++] = dishes[i];
			}
		}
		copasity--;
		size--;
		delete[]dishes;
		dishes = dishess;
	}

	void enter() {
		cout << "enter number table:";
		cin >> number;
		cout << "enter amount of dishes : ";
		cin >> copasity;
		cout << endl;
		size = copasity * 2;
		people.enter();
		cout << endl;
		if (dishes != 0) {
			delete[]dishes;
		}
		dishes = new dish[this->size];
		for (int i = 0; i < copasity; i++){
			dishes[i].enter();
			cout << endl;
		}
		cout << endl;
	}

	void print_order() {
		cout << "your order: ";
		for (int i = 0; i < copasity ; i++){
			dishes[i].print();
		}
		cout << endl;
	}
};



