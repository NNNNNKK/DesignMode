#include <iostream>
#include<memory>
#include"AbstractFactoryMode.h"


int main()
{
	auto department = std::make_shared<Department>();
	std::shared_ptr<IFactory> factory(nullptr);
	factory.reset(new SqlServerFactory());

	std::unique_ptr<IDepartment> id(factory->CreateDepartment());
	id->Insert(department.get());
	id->GetDepartment(1);

	factory.reset(new AccessFactory());
	id.reset(factory->CreateDepartment());
	id->Insert(department.get());
	id->GetDepartment(1);
}

