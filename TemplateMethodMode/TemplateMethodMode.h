#pragma once

//������࣬ģ�巽������
class AbstractTemplateMethod
{
public:
	virtual void PrimitiveOperation1() = 0; //������Ϊ1������ʵ��
	virtual void PrimitiveOperation2() = 0; //������Ϊ2������ʵ��

	//ģ�巽�����㷨�Ǽ�
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