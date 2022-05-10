// main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>
#include "TemplateMethodMode.h"

int main()
{
	std::unique_ptr<AbstractTemplateMethod> c = nullptr;
	c.reset(new ConcreteClassA);
	c->TemplateMethod();
	c.reset(new ConcreteClassB);
	c->TemplateMethod();
}

