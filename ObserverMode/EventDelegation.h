#pragma once
#include<iostream>
#include<string>
#include<functional>
#include<list>
#include<algorithm>

//通知者接口
class SubjectDeleGate 
{
protected:
	std::list<std::function<void()>> delegates;//存储所代理的函数指针，函数的原型必须相同
public:
	void Notify()
	{
		std::for_each(delegates.cbegin(), 
			delegates.cend(), [](std::function<void()> f){f();});
	}

	//状态字段的读写
	virtual void SetState(std::string state) = 0;
	virtual std::string GetSate() const = 0;
	//添加所代理的通知函数
	void AddDelegate(std::function<void()> delegate)
	{
		delegates.emplace_back(delegate);
	}
};

//查看股票类
class StockObserver
{
private:
	std::string name;
	std::shared_ptr<SubjectDeleGate> subject;
public:
	StockObserver(std::string name, std::shared_ptr<SubjectDeleGate> subject);

	//关闭股票行情
	void CloseStockMarket();
};

//看NBA的同事类
class NBAObserver
{
private:
	std::string name;
	std::shared_ptr<SubjectDeleGate> subject;
public:
	NBAObserver(std::string name, std::shared_ptr<SubjectDeleGate> subject);

	//关闭NBA直播
	void CloseNBADirectSeeding();
};

//老板类
class Boss final : public SubjectDeleGate
{
private:
	std::string action;
public:
	inline void SetState(std::string state) override { this->action = state; }
	inline std::string GetSate() const override { return action; }
};