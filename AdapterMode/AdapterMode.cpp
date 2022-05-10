#include "AdapterMode.h"
#include<iostream>

Forwards::Forwards(std::string name):Player(name)
{
}

void Forwards::Attack()
{
	std::cout << "前锋" << name << "进攻" << std::endl;
}

void Forwards::Defense()
{
	std::cout << "前锋" << name << "防守" << std::endl;
}

ForeignForwards::ForeignForwards(std::string name)
{
	this->name = name;
}

void ForeignForwards::Attack_CH()
{
	std::cout << "外籍前锋" << name << "进攻" << std::endl;
}

void ForeignForwards::Defense_CH()
{
	std::cout << "外籍前锋" << name << "防守" << std::endl;
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