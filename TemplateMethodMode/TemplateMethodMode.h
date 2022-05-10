#pragma once

//纯虚基类，模板方法父类
class AbstractTemplateMethod
{
public:
	virtual void PrimitiveOperation1() = 0; //抽象行为1，子类实现
	virtual void PrimitiveOperation2() = 0; //抽象行为2，子类实现

	//模板方法，算法骨架
	void TemplateMethod()
	{
		PrimitiveOperation1();
		PrimitiveOperation2();
	}
};

class ConcreteClassA final : public AbstractTemplateMethod
{
public:
	ConcreteClassA() = default;
	~ConcreteClassA() = default;

	void PrimitiveOperation1() override;
	void PrimitiveOperation2() override;

};

class ConcreteClassB final : public AbstractTemplateMethod
{
public:
	ConcreteClassB() = default;
	~ConcreteClassB() = default;
	void PrimitiveOperation1() override;
	void PrimitiveOperation2() override;
};