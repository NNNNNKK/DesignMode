#include "AbstractFactoryMode.h"
#include<iostream>
#include<string>

void SqlserverDepartment::Insert(Department* department)
{
	//仅模拟，不做实际操作
	std::cout << "在SQL Server中给Department表增加一条记录!" << std::endl;
}

Department* SqlserverDepartment::GetDepartment(int id)
{
	std::cout << "在SQL Server中根据ID得到Department表一条记录!" << std::endl;
	return new Department();
}

void AccessDepartment::Insert(Department* department)
{
	//仅模拟，不做实际操作
	std::cout << "在Access中给Department表增加一条记录!" << std::endl;
}

Department* AccessDepartment::GetDepartment(int id)
{
	std::cout << "在Access中根据ID得到Department表一条记录!" << std::endl;
	return new Department();
}

IDepartment* SqlServerFactory::CreateDepartment()
{
	return new SqlserverDepartment();
}

IDepartment* AccessFactory::CreateDepartment()
{
	return new AccessDepartment();
}