#pragma once
#include<list>
#include<string>
#include<memory>
//��Ʒ��
class Product
{
private:
	std::list<std::string> parts;
public:
	Product() = default;
	~Product() = default;

	void Add(std::string part);

	void Show();
};

//Builder�ࡪ������������,ȷ����Ʒ����������PartA��PartB���
class Builder
{
public:
	virtual void BuildPartA() = 0;
	virtual void BuildPartB() = 0;
	virtual Product GetResult() = 0;
};

//ConcreteBuilder1�ࡪ�����彨������,�������Ĳ���A��B
class ConcreteBuilder1 final : public Builder
{
private:
	Product product;
public:
	void BuildPartA() override;
	void BuildPartB() override;
	Product GetResult() override;
};

//ConcreteBuilder2�ࡪ�����彨������,�������Ĳ���X��Y
class ConcreteBuilder2 final : public Builder
{
private:
	Product product;
public:
	void BuildPartA() override;
	void BuildPartB() override;
	Product GetResult() override;
};

//Director�ࡪ��ָ������,����ָ�ӽ������
class Director
{
public:
	void Construct(std::shared_ptr<Builder> builder);
};