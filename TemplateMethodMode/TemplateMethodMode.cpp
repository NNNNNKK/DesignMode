#include "TemplateMethodMode.h"
#include <iostream>
#include <string>

void ConcreteClassA::PrimitiveOperation1()
{
	std::cout << "�����෽��A ����1ʵ��"<<std::endl;
}

void ConcreteClassA::PrimitiveOperation2()
{
	std::cout << "�����෽��A ����2ʵ��" << std::endl;
}

void ConcreteClassB::PrimitiveOperation1()
{
	std::cout << "�����෽��B ����1ʵ��" << std::endl;
}

void ConcreteClassB::PrimitiveOperation2()
{
	std::cout << "�����෽��B ����2ʵ��" << std::endl;
}
