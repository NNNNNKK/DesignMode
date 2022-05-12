#pragma once
#include<list>
#include<memory>
#include<string>

//烤肉串者
class Barbecuer
{
public:
	//烤羊肉串
	void BakeMutton();
	//炸鸡翅
	void BakeChickenWing();
};

//抽象命令类
class Command
{
protected:
	Barbecuer m_barbecuer;
public:
	Command() = delete;
	Command(Barbecuer barbecuer):m_barbecuer(barbecuer){}
	//执行命令
	virtual void ExcuteCommand() = 0;
};

//烤羊肉串命令
class BakeMuttonCommand final :public Command
{
public:
	BakeMuttonCommand(Barbecuer barbecuer);
	void ExcuteCommand() override;
};

//炸鸡翅命令
class BakeChickenWingCommand final :public Command
{
public:
	BakeChickenWingCommand(Barbecuer barbecuer);
	void ExcuteCommand() override;
};

//服务员类
class Waiter
{
private:
	std::list<std::shared_ptr<Command>> orders;
public:
	//设置订单
	void SetOrder(std::shared_ptr<Command> command);
	//取消订单
	void CancleOrder(std::shared_ptr<Command> command);
	//通知全部执行
	void Notify();
};