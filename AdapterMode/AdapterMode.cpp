#include "AdapterMode.h"
#include<iostream>

Forwards::Forwards(std::string name):Player(name)
{
}

void Forwards::Attack()
{
	std::cout << "ǰ��" << name << "����" << std::endl;
}

void Forwards::Defense()
{
	std::cout << "ǰ��" << name << "����" << std::endl;
}

ForeignForwards::ForeignForwards(std::string name)
{
	this->name = name;
}

void ForeignForwards::Attack_CH()
{
	std::cout << "�⼮ǰ��" << name << "����" << std::endl;
}

void ForeignForwards::Defense_CH()
{
	std::cout << "�⼮ǰ��" << name << "����" << std::endl;
}

Translator::Translator(std::string name)
	:Player(name), foreignForwards(name)
{
}

void Translator::Attack()
{
	foreignForwards.Attack_CH();
}

void Translator::Defense()
{
	foreignForwards.Defense_CH();
}