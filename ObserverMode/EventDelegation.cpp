#include "EventDelegation.h"
#include<iostream>

StockObserver::StockObserver(std::string name, std::shared_ptr<SubjectDeleGate> subject)
{
	this->name = name;
	this->subject = subject;
}

void StockObserver::CloseStockMarket()
{
	std::cout << subject->GetSate() << name << "�رչ�Ʊ���飬���������!"<<std::endl;
}

NBAObserver::NBAObserver(std::string name, std::shared_ptr<SubjectDeleGate> subject)
{
	this->name = name;
	this->subject = subject;
}

void NBAObserver::CloseNBADirectSeeding()
{
	std::cout << subject->GetSate() << name << "�ر�NBAֱ�������������!" << std::endl;
}