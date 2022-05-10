#include "AbstractFactoryMode.h"
#include<iostream>
#include<string>

void SqlserverDepartment::Insert(Department* department)
{
	//��ģ�⣬����ʵ�ʲ���
	std::cout << "��SQL Server�и�Department������һ����¼!" << std::endl;
}

Department* SqlserverDepartment::GetDepartment(int id)
{
	std::cout << "��SQL Server�и���ID�õ�Department��һ����¼!" << std::endl;
	return new Department();
}

void AccessDepartment::Insert(Department* department)
{
	//��ģ�⣬����ʵ�ʲ���
	std::cout << "��Access�и�Department������һ����¼!" << std::endl;
}

Department* AccessDepartment::GetDepartment(int id)
{
	std::cout << "��Access�и���ID�õ�Department��һ����¼!" << std::endl;
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