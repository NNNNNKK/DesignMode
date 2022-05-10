#include "ProxyPatternMode.h"
#include <iostream>

Pursuit::Pursuit(SchoolGirl mm)
{
	this->mm = mm;
}

void Pursuit::GiveDolls()
{
	std::cout << (mm.GetName() + " ËÍÄãÑóÍÞÍÞ")<<std::endl;
}


void Pursuit::GiveFlowers()
{
	std::cout << (mm.GetName() + " ËÍÄãÏÊ»¨") << std::endl;
}

void Pursuit::GiveChocolate()
{
	std::cout << (mm.GetName() + " ËÍÄãÇÉ¿ËÁ¦") << std::endl;
}

SchoolGirl::SchoolGirl(const std::string _name)
	:name(_name)
{

}

SchoolGirl::SchoolGirl(const SchoolGirl & girl)
{
	this->name = girl.name;
}

SchoolGirl & SchoolGirl::operator=(const SchoolGirl & girl)
{
	if (this!= &girl)
	{
		this->name = girl.name;
	}
	return *this;
}

const std::string SchoolGirl::GetName() const &
{
	return name;
}

void SchoolGirl::SetName(const std::string name)
{
	this->name = name;
}

Proxy::Proxy(SchoolGirl mm)
{
	gg = std::make_shared<Pursuit>(mm);
}

void Proxy::GiveDolls()
{
	gg->GiveDolls();
}

void Proxy::GiveFlowers()
{
	gg->GiveFlowers();
}

void Proxy::GiveChocolate()
{
	gg->GiveChocolate();
}
