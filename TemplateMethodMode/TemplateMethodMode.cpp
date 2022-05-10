#include "TemplateMethodMode.h"
#include <iostream>
#include <string>

void ConcreteClassA::PrimitiveOperation1()
{
	std::cout << "具体类方法A 方法1实现"<<std::endl;
}

void ConcreteClassA::PrimitiveOperation2()
{
	std::cout << "具体类方法A 方法2实现" << std::endl;
}

void ConcreteClassB::PrimitiveOperation1()
{
	std::cout << "具体类方法B 方法1实现" << std::endl;
}

void ConcreteClassB::PrimitiveOperation2()
{
	std::cout << "具体类方法B 方法2实现" << std::endl;
}
