#pragma once
#include<list>
#include<string>

//公司类，抽象接口
class Company
{
protected:
	std::string name;
	Company(std::string name)
	{
		this->name = name;
	}
public:
	virtual void Add(std::shared_ptr<Company> c) = 0;//添加部门
	virtual void Remove(std::shared_ptr<Company> c) = 0;//移出部门
	virtual void Display(int depth) = 0;//显示部门
	virtual void LineOfDuty() = 0;//履行职责
};

//具体公司类　实现接口　树枝节点
class ConcreteCompany final : public Company
{
private:
	std::list<std::shared_ptr<Company>> children;
public:
	ConcreteCompany() = delete;
	ConcreteCompany(std::string name);
	
	void Add(std::shared_ptr<Company> c) override;
	void Remove(std::shared_ptr<Company> c) override;
	void Display(int depth) override;
	void LineOfDuty() override;	
};

//人力资源部与财务部类　树叶节点
class HRDepartment final :public Company
{
public:
	HRDepartment(std::string name);

	void Add(std::shared_ptr<Company> c) override;
	void Remove(std::shared_ptr<Company> c) override;
	void Display(int depth) override;
	void LineOfDuty() override;
};

//财务部
class FinanceDepartment final :public Company
{
public:
	FinanceDepartment(std::string name);

	void Add(std::shared_ptr<Company> c) override;
	void Remove(std::shared_ptr<Company> c) override;
	void Display(int depth) override;
	void LineOfDuty() override;
};