#pragma once
#include<list>
#include<string>
#include<memory>
//产品类
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

//Builder类——抽象建造者类,确定产品由两个部件PartA和PartB组成
class Builder
{
public:
	virtual void BuildPartA() = 0;
	virtual void BuildPartB() = 0;
	virtual Product GetResult() = 0;
};

//ConcreteBuilder1类——具体建造者类,建造具体的部件A和B
class ConcreteBuilder1 final : public Builder
{
private:
	Product product;
public:
	void BuildPartA() override;
	void BuildPartB() override;
	Product GetResult() override;
};

//ConcreteBuilder2类——具体建造者类,建造具体的部件X和Y
class ConcreteBuilder2 final : public Builder
{
private:
	Product product;
public:
	void BuildPartA() override;
	void BuildPartB() override;
	Product GetResult() override;
};

//Director类——指挥者类,用来指挥建造过程
class Director
{
public:
	void Construct(std::shared_ptr<Builder> builder);
};