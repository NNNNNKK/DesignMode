#pragma once
#include<string>

//部门类
class Department
{
private:
	int id;
	std::string deptName;
public:
	Department() = default;
	inline int GetId() const { return id; }
	inline void SetId(int id) { this->id = id; }

	inline std::string GetDeptName() { return deptName; }
	inline void SetDeptName(std::string deptName) { this->deptName = deptName; }
};

//数据库部门操作虚基类
class IDepartment
{
public:
	virtual void Insert(Department* department) = 0;
	virtual Department* GetDepartment(int id) = 0;
};

//SqlserverDepartment类，用于访问SQL Server的Department
class SqlserverDepartment final : public IDepartment
{
public:
	void Insert(Department* department) override;
	Department* GetDepartment(int id) override;
};

//AccessDepartment类，用于访问Access的Department
class AccessDepartment final : public IDepartment
{
public:
	void Insert(Department* department) override;
	Department* GetDepartment(int id) override;
};

//IFactory接口，定义一个创建访问Department表对象的抽象的工厂接口
class IFactory
{
public:
	virtual IDepartment* CreateDepartment() = 0;//创建部门表类的接口
};

//SqlServerFactory类，实现IFactory接口，实例化SqlserverDepartment
class SqlServerFactory final : public IFactory
{
public:
	IDepartment* CreateDepartment() override;
};

//AccessFactory类，实现IFactory接口，实例化AccessDepartment
class AccessFactory final : public IFactory
{
public:
	IDepartment* CreateDepartment() override;
};