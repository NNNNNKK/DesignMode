// main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
#include"ObserverMode.h"
#include"EventDelegation.h"

int main()
{
#pragma region TestObserverMode
	auto s = std::make_shared<ConcreteSubject>();
	s->Attach(std::make_shared<ConcreteObserver>(s, "X"));
	s->Attach(std::make_shared<ConcreteObserver>(s, "Y"));
	s->Attach(std::make_shared<ConcreteObserver>(s, "Z"));

	s->SetState("ABC");
	s->Notify();
#pragma endregion

#pragma region TestEventDelegation
	auto huhansan = std::make_shared<Boss>();
	StockObserver tongshi1("魏关姹", huhansan);
	NBAObserver tongshi2("易观察", huhansan);
	//绑定观察者两个类的关闭函数
	huhansan->AddDelegate(std::bind(&StockObserver::CloseStockMarket,&tongshi1));
	huhansan->AddDelegate(std::bind(&NBAObserver::CloseNBADirectSeeding,&tongshi2));

	huhansan->SetState("我胡汉三回来了!");
	huhansan->Notify();
#pragma endregion

}

