#include "FacadeMode.h"
#include <iostream>

void SubSystemOne::MethodOne()
{
	std::cout << "��ϵͳ����һ" << std::endl;
}

void SubSystemTwo::MethodTwo()
{
	std::cout << "��ϵͳ������" << std::endl;
}

void SubSystemThree::MethodThree()
{
	std::cout << "��ϵͳ������" << std::endl;
}

void SubSystemFour::MethodFour()
{
	std::cout << "��ϵͳ������" << std::endl;
}

void Facade::MethodA()
{
	std::cout << "\n������A����---\n";
	one.MethodOne();
	two.MethodTwo();
	four.MethodFour();
}

void Facade::MethodB()
{
	std::cout << "\n������B����---\n";
	two.MethodTwo();
	three.MethodThree();
}
