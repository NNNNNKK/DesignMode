#pragma once
#include<list>
#include<memory>
#include<string>

//抽象观察者类
class Obsever
{
public:
	virtual void Update() = 0;
};

//抽象通知者类
class Subject
{
private:
	using SpObserver = std::shared_ptr<Obsever>;
	std::list<SpObserver> observers;

public:
	//增加观察者
	void Attach(SpObserver observer);
	//移出观察者
	void Detach(SpObserver observer);
	//通知
	void Notify();
};

//具体通知者类,将有关状态存入具体观察者对象
class ConcreteSubject final : public Subject
{
private:
	std::string subjectState;
public:
	inline void SetState(std::string state) { this->subjectState = state;}
	inline std::string GetState() const { return subjectState; }
};

//具体观察者，实现抽象观察者角色所要求的更新接口，以便使本身的状态与主题的状态相协调
class ConcreteObserver final :public Obsever
{
private:
	std::string name;
	std::string observerState;
	std::shared_ptr<ConcreteSubject> subject;

public:
	ConcreteObserver(std::shared_ptr<ConcreteSubject> subject, std::string name);
	void Update() override;
};