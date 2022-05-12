#pragma once
#include<list>
#include<memory>
#include<string>

//���⴮��
class Barbecuer
{
public:
	//�����⴮
	void BakeMutton();
	//ը����
	void BakeChickenWing();
};

//����������
class Command
{
protected:
	Barbecuer m_barbecuer;
public:
	Command() = delete;
	Command(Barbecuer barbecuer):m_barbecuer(barbecuer){}
	//ִ������
	virtual void ExcuteCommand() = 0;
};

//�����⴮����
class BakeMuttonCommand final :public Command
{
public:
	BakeMuttonCommand(Barbecuer barbecuer);
	void ExcuteCommand() override;
};

//ը��������
class BakeChickenWingCommand final :public Command
{
public:
	BakeChickenWingCommand(Barbecuer barbecuer);
	void ExcuteCommand() override;
};

//����Ա��
class Waiter
{
private:
	std::list<std::shared_ptr<Command>> orders;
public:
	//���ö���
	void SetOrder(std::shared_ptr<Command> command);
	//ȡ������
	void CancleOrder(std::shared_ptr<Command> command);
	//֪ͨȫ��ִ��
	void Notify();
};