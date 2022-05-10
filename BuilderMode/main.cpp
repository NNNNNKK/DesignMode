// main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>
#include "BuilderMode.h"

int main()
{
	Director director;
	std::shared_ptr<Builder> b1 = std::make_shared<ConcreteBuilder1>();
	std::shared_ptr<Builder> b2 = std::make_shared<ConcreteBuilder2>();

	director.Construct(b1);
	auto p1 = b1->GetResult();
	p1.Show();

	director.Construct(b2);
	auto p2 = b2->GetResult();
	p2.Show();
}

