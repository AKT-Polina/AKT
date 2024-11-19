#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Cat{
public:
	//свойства
	string name;//имя
	int age;//возраст
	string color;//раскрас
	//конструктор
	Cat(string n, int a, string c){
		name = n;
		age = a;
		color = c;
	}
	//Конструкотр по умолчанию
	Cat(){
		name = "Barsik";
		age = 0;
		color = "Ginger";
	}
	//вывод информации о коте
	void Print(){
		cout << "Имя: " << name;
		cout << "Возраст: " <<age;
		cout << "Раскрас: " <<color;
	}

	//метод
	void meow(){
		cout << "meow";
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, ".1251");
	//создание объекта класса
	Cat cat1{ "Vasya", 5, "Grey" };
	cout << cat1.name << " Имя";
	cout << cat1.age << " Возраст ";
	cout << cat1.color << " Раскрас ";
	
	//создание другого кота
	Cat cat2{};
	//вызов метода класса
	cat2.Print();

	//массив котов
	Cat cats[4] = 
	{   cat1, 
		cat2,
		{ "bobik", 3, "Green" },
		{"Kotik", 45, "pink"}
	};
	//перебор котов
	for (int i = 0; i < 4; i++){
		//вывод информации на консоль
		cats[i].Print();
	}
	
	return 0;
}

