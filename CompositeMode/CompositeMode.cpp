#include "CompositeMode.h"
#include<iostream>
#include<algorithm>

ConcreteCompany::ConcreteCompany(std::string name)
	:Company(name)
{
}

void ConcreteCompany::Add(std::shared_ptr<Company> c)
{
	children.emplace_back(c);
}

void ConcreteCompany::Remove(std::shared_ptr<Company> c)
{
	children.remove(c);
}

void ConcreteCompany::Display(int depth)
{
	std::cout << "-" << depth << name << std::endl;
	std::for_each(children.cbegin(), children.cend(), [&](std::shared_ptr<Company> c)
	{
		c->Display(depth + 2);
	});
}

void ConcreteCompany::LineOfDuty()
{
	std::for_each(children.cbegin(), children.cend(), [](std::shared_ptr<Company> c)
	{
		c->LineOfDuty();
	});
}

HRDepartment::HRDepartment(std::string name)
	:Company(name)
{
}

void HRDepartment::Add(std::shared_ptr<Company> c)
{
}

void HRDepartment::Remove(std::shared_ptr<Company> c)
{
}

void HRDepartment::Display(int depth)
{
	std::cout << "-" << depth << name << std::endl;
}

void HRDepartment::LineOfDuty()
{
	std::cout << name << ":员工招聘培训管理!" << std::endl;
}

FinanceDepartment::FinanceDepartment(std::string name)
	:Company(name)
{
}

void FinanceDepartment::Add(std::shared_ptr<Company> c)
{
}

void FinanceDepartment::Remove(std::shared_ptr<Company> c)
{
}

void FinanceDepartment::Display(int depth)
{
	std::cout << "-" << depth << name << std::endl;
}

void FinanceDepartment::LineOfDuty()
{
	std::cout << name << ":公司财务收支管理!" << std::endl;
}