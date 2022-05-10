#pragma once
#include<list>
#include<string>

//��˾�࣬����ӿ�
class Company
{
protected:
	std::string name;
	Company(std::string name)
	{
		this->name = name;
	}
public:
	virtual void Add(std::shared_ptr<Company> c) = 0;//��Ӳ���
	virtual void Remove(std::shared_ptr<Company> c) = 0;//�Ƴ�����
	virtual void Display(int depth) = 0;//��ʾ����
	virtual void LineOfDuty() = 0;//����ְ��
};

//���幫˾�ࡡʵ�ֽӿڡ���֦�ڵ�
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

//������Դ��������ࡡ��Ҷ�ڵ�
class HRDepartment final :public Company
{
public:
	HRDepartment(std::string name);

	void Add(std::shared_ptr<Company> c) override;
	void Remove(std::shared_ptr<Company> c) override;
	void Display(int depth) override;
	void LineOfDuty() override;
};

//����
class FinanceDepartment final :public Company
{
public:
	FinanceDepartment(std::string name);

	void Add(std::shared_ptr<Company> c) override;
	void Remove(std::shared_ptr<Company> c) override;
	void Display(int depth) override;
	void LineOfDuty() override;
};