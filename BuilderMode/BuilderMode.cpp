#include "BuilderMode.h"
#include <iostream>
#include <algorithm>

void Product::Add(std::string part)
{
	parts.emplace_back(part);
}

void Product::Show()
{
	std::cout << "产品 创建---\n";
	std::for_each(parts.cbegin(),parts.cend(),[](std::string part)
	{
		std::cout << part << std::endl;
	});
}

void ConcreteBuilder1::BuildPartA()
{
	product.Add("部件A");
}

void ConcreteBuilder1::BuildPartB()
{
	product.Add("部件B");
}

Product ConcreteBuilder1::GetResult()
{
	return product;
}

void ConcreteBuilder2::BuildPartA()
{
	product.Add("部件X");
}

void ConcreteBuilder2::BuildPartB()
{
	product.Add("部件Y");
}

Product ConcreteBuilder2::GetResult()
{
	return product;
}

void Director::Construct(std::shared_ptr<Builder> builder)
{
	builder->BuildPartA();
	builder->BuildPartB();
}