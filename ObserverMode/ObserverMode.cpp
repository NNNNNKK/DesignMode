#include "ObserverMode.h"
#include<algorithm>
#include<iostream>

void  Subject::Attach(SpObserver observer)
{
	observers.emplace_back(observer);
}

void Subject::Detach(SpObserver observer)
{
	observers.remove(observer);
}

void Subject::Notify()
{
	std::for_each(observers.cbegin(), observers.cend(), [](SpObserver observer)
	{
		observer->Update();
	});
}

ConcreteObserver::ConcreteObserver(std::shared_ptr<ConcreteSubject> subject, std::string name)
{
	this->subject = subject;
	this->name = name;
}

void ConcreteObserver::Update()
{
	observerState = subject->GetState();
	std::cout<<"观察者"<<name<<"的新状态是"<< observerState<<std::endl;
}