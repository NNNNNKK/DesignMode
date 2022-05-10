#include "FacadeMode.h"
#include <iostream>

void SubSystemOne::MethodOne()
{
	std::cout << "子系统方法一" << std::endl;
}

void SubSystemTwo::MethodTwo()
{
	std::cout << "子系统方法二" << std::endl;
}

void SubSystemThree::MethodThree()
{
	std::cout << "子系统方法三" << std::endl;
}

void SubSystemFour::MethodFour()
{
	std::cout << "子系统方法四" << std::endl;
}

void Facade::MethodA()
{
	std::cout << "\n方法组A（）---\n";
	one.MethodOne();
	two.MethodTwo();
	four.MethodFour();
}

void Facade::MethodB()
{
	std::cout << "\n方法组B（）---\n";
	two.MethodTwo();
	three.MethodThree();
}
