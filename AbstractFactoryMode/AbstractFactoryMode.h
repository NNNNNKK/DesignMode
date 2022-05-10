#pragma once
#include<string>

//������
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

//���ݿⲿ�Ų��������
class IDepartment
{
public:
	virtual void Insert(Department* department) = 0;
	virtual Department* GetDepartment(int id) = 0;
};

//SqlserverDepartment�࣬���ڷ���SQL Server��Department
class SqlserverDepartment final : public IDepartment
{
public:
	void Insert(Department* department) override;
	Department* GetDepartment(int id) override;
};

//AccessDepartment�࣬���ڷ���Access��Department
class AccessDepartment final : public IDepartment
{
public:
	void Insert(Department* department) override;
	Department* GetDepartment(int id) override;
};

//IFactory�ӿڣ�����һ����������Department�����ĳ���Ĺ����ӿ�
class IFactory
{
public:
	virtual IDepartment* CreateDepartment() = 0;//�������ű���Ľӿ�
};

//SqlServerFactory�࣬ʵ��IFactory�ӿڣ�ʵ����SqlserverDepartment
class SqlServerFactory final : public IFactory
{
public:
	IDepartment* CreateDepartment() override;
};

//AccessFactory�࣬ʵ��IFactory�ӿڣ�ʵ����AccessDepartment
class AccessFactory final : public IFactory
{
public:
	IDepartment* CreateDepartment() override;
};