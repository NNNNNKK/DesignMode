#include"CompositeMode.h"
#include <iostream>

int main()
{
	ConcreteCompany root("北京公司总部");
	root.Add(std::make_shared<HRDepartment>("总公司人力资源部"));
	root.Add(std::make_shared<FinanceDepartment>("总公司财务部"));

	auto comp = std::make_shared<ConcreteCompany>("上海华东分公司");
	comp->Add(std::make_shared<HRDepartment>("华东分公司人力资源部"));
	comp->Add(std::make_shared<FinanceDepartment>("华东分公司财务部"));
	root.Add(comp);

	auto comp1 = std::make_shared<ConcreteCompany>("南京办事处");
	comp1->Add(std::make_shared<HRDepartment>("南京办事处人力资源部"));
	comp1->Add(std::make_shared<FinanceDepartment>("南京办事处财务部"));
	root.Add(comp1);

	auto comp2 = std::make_shared<ConcreteCompany>("杭州办事处");
	comp2->Add(std::make_shared<HRDepartment>("杭州办事处人力资源部"));
	comp2->Add(std::make_shared<FinanceDepartment>("杭州办事处财务部"));
	root.Add(comp2);

	std::cout << "结构图：" << std::endl;
	root.Display(1);

	std::cout << "职责：" << std::endl;
	root.LineOfDuty();
}
