#include "BuilderMode.h"
#include <iostream>
#include <algorithm>

void Product::Add(std::string part)
{
	parts.emplace_back(part);
}

void Product::Show()
{
	std::cout << "��Ʒ ����---\n";
	std::for_each(parts.cbegin(),parts.cend(),[](std::string part)
	{
		std::cout << part << std::endl;
	});
}

void ConcreteBuilder1::BuildPartA()
{
	product.Add("����A");
}

void ConcreteBuilder1::BuildPartB()
{
	product.Add("����B");
}

Product ConcreteBuilder1::GetResult()
{
	return product;
}

void ConcreteBuilder2::BuildPartA()
{
	product.Add("����X");
}

void ConcreteBuilder2::BuildPartB()
{
	product.Add("����Y");
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