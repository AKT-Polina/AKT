#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Cat{
public:
	//��������
	string name;//���
	int age;//�������
	string color;//�������
	//�����������
	Cat(string n, int a, string c){
		name = n;
		age = a;
		color = c;
	}
	//����������� �� ���������
	Cat(){
		name = "Barsik";
		age = 0;
		color = "Ginger";
	}
	//����� ���������� � ����
	void Print(){
		cout << "���: " << name;
		cout << "�������: " <<age;
		cout << "�������: " <<color;
	}

	//�����
	void meow(){
		cout << "meow";
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, ".1251");
	//�������� ������� ������
	Cat cat1{ "Vasya", 5, "Grey" };
	cout << cat1.name << " ���";
	cout << cat1.age << " ������� ";
	cout << cat1.color << " ������� ";
	
	//�������� ������� ����
	Cat cat2{};
	//����� ������ ������
	cat2.Print();

	//������ �����
	Cat cats[4] = 
	{   cat1, 
		cat2,
		{ "bobik", 3, "Green" },
		{"Kotik", 45, "pink"}
	};
	//������� �����
	for (int i = 0; i < 4; i++){
		//����� ���������� �� �������
		cats[i].Print();
	}
	
	return 0;
}

