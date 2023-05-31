#include <locale>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

struct date {
	int day;
	int month;
	int year;
};

struct delo {
	string name;
	int priority;
	string opisanie;
	date date_a;
	date date_b;
};

void delete_delo(delo*& note, int& size) {
	int index;
	cout << "Введите число списка который хотите удалить: " << endl;
	cin >> index;
	index--;
	if (note != nullptr && index >= 0 && index < size) {
		for (int i = index; i < size - 1; ++i) {
			note[i] = note[i + 1];
		}
		--size;
		delo* newArray = new delo[size];
		for (int i = 0; i < size; ++i) {
			newArray[i] = note[i];
		}
		delete[] note;
		note = newArray;
	}
}

void add(delo*& note, int& size)
{
	delo* temp = new delo[size + 1];
	for (int i = 0; i < size; i++) {
		temp[i] = note[i];
	}
	cout << "Добавление списка" << endl << endl;
	cout << "Введите название: ";
	getline(cin, temp[size].name);
	cout << "Введите описание: ";
	getline(cin, temp[size].opisanie);
	cout << "Введите приоритет: ";
	cin >> temp[size].priority;
	cout << "Установите дату: " << endl;
	cout << "День: ";
	cin >> temp[size].date_a.day;
	cout << "Месяц: ";
	cin >> temp[size].date_a.month;
	cout << "Год: ";
	cin >> temp[size].date_a.year;
	cout << "Установите срок: " << endl;
	cout << "День: ";
	cin >> temp[size].date_b.day;
	cout << "Месяц: ";
	cin >> temp[size].date_b.month;
	cout << "Год: ";
	cin >> temp[size].date_b.year;
	size++;
	delete[] note;
	note = temp;
}

void all(delo*& note, int size)
{
	cout << "Bсе списки:" << endl << endl;
	cout << "1 - сортировка по приоритету" << endl;
	cout << "2 - сортировка по дате" << endl;
	int x;
	cin >> x;
	if (x == 1) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (note[i].priority > note[j].priority) {
					delo temp = note[i];
					note[i] = note[j];
					note[j] = temp;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			cout << endl;
			cout << "Название: " << note[i].name << endl;
			cout << "Описание: " << note[i].opisanie << endl;
			cout << "Приоритет: " << note[i].priority << endl;
			cout << "Сделан: " << note[i].date_b.day << "/" << note[i].date_b.month << "/" << note[i].date_b.year << endl;
			cout << "До: " << note[i].date_a.day << "/" << note[i].date_a.month << "/" << note[i].date_a.year << endl;
		}
		cout << endl << endl;
	}
	else if (x == 2) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (note[i].date_a.day + note[i].date_a.month + note[i].date_a.year > note[j].date_a.day + note[j].date_a.month + note[j].date_a.year) {
					delo temp = note[i];
					note[i] = note[j];
					note[j] = temp;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			cout << endl;
			cout << "Название: " << note[i].name << endl;
			cout << "Описание: " << note[i].opisanie << endl;
			cout << "Приоритет: " << note[i].priority << endl;
			cout << "Сделан: " << note[i].date_b.day << "/" << note[i].date_b.month << "/" << note[i].date_b.year << endl;
			cout << "До: " << note[i].date_a.day << "/" << note[i].date_a.month << "/" << note[i].date_a.year << endl;
		}
		cout << endl << endl;
	}
}

void search7(delo* note, int size) {
	cout << "1 - Поиск списка по названию" << endl;
	cout << "2 - Поиск списка по приоритету" << endl;
	cout << "3 - Поиск списка по описанию" << endl;
	cout << "4 - Поиск списка по дате" << endl;
	int x;
	cin >> x;
	if (x == 1) {
		string title;
		cout << "Введите название: ";
		getline(cin, title);
		for (int i = 0; i < size; i++) {
			if (note[i].name == title) {
				cout << endl;
				cout << "Название: " << note[i].name << endl;
				cout << "Описание: " << note[i].opisanie << endl;
				cout << "Приоритет: " << note[i].priority << endl;
				cout << "Сделан: " << note[i].date_b.day << "/" << note[i].date_b.month << "/" << note[i].date_b.year << endl;
				cout << "До: " << note[i].date_a.day << "/" << note[i].date_a.month << "/" << note[i].date_a.year << endl;
			}
		}
	}
	else if (x == 2) {
		int pri;
		cout << "Введите приоритет: ";
		cin >> pri;
		for (int i = 0; i < size; i++) {
			if (note[i].priority == pri) {
				cout << endl;
				cout << "Название: " << note[i].name << endl;
				cout << "Описание: " << note[i].opisanie << endl;
				cout << "Приоритет: " << note[i].priority << endl;
				cout << "Сделан: " << note[i].date_b.day << "/" << note[i].date_b.month << "/" << note[i].date_b.year << endl;
				cout << "До: " << note[i].date_a.day << "/" << note[i].date_a.month << "/" << note[i].date_a.year << endl;
			}
		}
	}
	else if (x == 3) {
		string op;
		cout << "Введите одно слово из описания: " << endl;
		cin >> op;
		for (int i = 0; i < size; i++) {
			size_t text = note[i].opisanie.find(op);
			if (text != string::npos) {
				cout << endl;
				cout << "Название: " << note[i].name << endl;
				cout << "Описание: " << note[i].opisanie << endl;
				cout << "Приоритет: " << note[i].priority << endl;
				cout << "Сделан: " << note[i].date_b.day << "/" << note[i].date_b.month << "/" << note[i].date_b.year << endl;
				cout << "До: " << note[i].date_a.day << "/" << note[i].date_a.month << "/" << note[i].date_a.year << endl;
			}
		}
	}
	else if (x == 4) {
		int d;
		int m;
		int y;
		cout << "Введите дату: " << endl;
		cin >> d;
		cin >> m;
		cin >> y;
		for (int i = 0; i < size; i++) {
			if (note[i].date_a.day == d || note[i].date_a.month == m || note[i].date_a.year == y || note[i].date_b.day == d || note[i].date_b.month == m || note[i].date_b.year == y) {
				cout << endl;
				cout << "Название: " << note[i].name << endl;
				cout << "Описание: " << note[i].opisanie << endl;
				cout << "Приоритет: " << note[i].priority << endl;
				cout << "Сделан: " << note[i].date_b.day << "/" << note[i].date_b.month << "/" << note[i].date_b.year << endl;
				cout << "До: " << note[i].date_a.day << "/" << note[i].date_a.month << "/" << note[i].date_a.year << endl;
			}
		}
	}
}

void edit(delo* note, int size, int index) {
	index--;
	if (index > size) {
		cout << "Неверный ввод" << endl;
	}
	cout << "Введите имя: ";
	getline(cin, note[index].name);
	cout << "Введите описание: ";
	getline(cin, note[index].opisanie);
	cout << "Введите приоритет: ";
	cin >> note[index].priority;
	cout << "Установите дату: " << endl;
	cout << "День: ";
	cin >> note[index].date_a.day;
	cout << "Месяц: ";
	cin >> note[index].date_a.month;
	cout << "Год: ";
	cin >> note[index].date_a.year;
	cout << "Установите срок: " << endl;
	cout << "День: ";
	cin >> note[index].date_b.day;
	cout << "Месяц: ";
	cin >> note[index].date_b.month;
	cout << "Год: ";
	cin >> note[index].date_b.year;
}

void f1(delo*& note, int size) {
	int d;
	cout << "Введите день: " << endl;
	cin >> d;
	for (int i = 0; i < size; i++) {
		if (note[i].date_a.day == d || note[i].date_b.day == d) {
			cout << endl;
			cout << "Название: " << note[i].name << endl;
			cout << "Описание: " << note[i].opisanie << endl;
			cout << "Приоритет: " << note[i].priority << endl;
			cout << "Сделан: " << note[i].date_b.day << "/" << note[i].date_b.month << "/" << note[i].date_b.year << endl;
			cout << "До: " << note[i].date_a.day << "/" << note[i].date_a.month << "/" << note[i].date_a.year << endl;
		}
	}
	cout << endl;
}

void f2(delo*& note, int size) {
	int m;
	cout << "Введите месяц: " << endl;
	cin >> m;
	for (int i = 0; i < size; i++) {
		if (note[i].date_a.month == m || note[i].date_b.month == m) {
			cout << endl;
			cout << "Название: " << note[i].name << endl;
			cout << "Описание: " << note[i].opisanie << endl;
			cout << "Приоритет: " << note[i].priority << endl;
			cout << "Сделан: " << note[i].date_b.day << "/" << note[i].date_b.month << "/" << note[i].date_b.year << endl;
			cout << "До: " << note[i].date_a.day << "/" << note[i].date_a.month << "/" << note[i].date_a.year << endl;
		}
	}
	cout << endl;
}

void menu() {
	system("cls");
	cout << "===========TO-DO-LIST======================" << endl;
	cout << "1 - Добавить список" << endl;
	cout << "2 - Показать все списки" << endl;
	cout << "3 - Отобразить списки на день" << endl;
	cout << "4 - Отобразить список на месяц" << endl;
	cout << "5 - Удалить cписок" << endl;
	cout << "6 - Редактировать список" << endl;
	cout << "7 - Поиск списка" << endl;
	cout << "0 - Выход" << endl;
	cout << "===========================================" << endl;
}

int main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	int size{};
	delo* note = new delo[size];
	while (true) {
		int temp{};
		menu();
		cout << endl;
		cout << "Выберите действие: ";
		cin >> temp;
		if (temp == 1)
		{
			system("cls");
			cin.ignore();
			add(note, size);
		}
		else if (temp == 2)
		{
			system("cls");
			all(note, size);
			system("pause");
		}
		else if (temp == 3)
		{
			system("cls");
			f1(note, size);
			system("pause");
		}
		else if (temp == 4)
		{
			system("cls");
			f2(note, size);
			system("pause");
		}
		else if (temp == 5)
		{
			system("cls");
			delete_delo(note, size);
		}
		else if (temp == 6)
		{
			system("cls");
			int index;
			cout << "Введите номер списка: " << endl;
			cin >> index;
			cin.ignore();
			edit(note, size, index);
		}
		else if (temp == 7)
		{
			system("cls");
			cin.ignore();
			search7(note, size);
			system("pause");
		}
		else if (temp == 0)
		{
			system("cls");
			return 0;
		}
		else
			cout << "Неверный ввод" << endl;
	}
}