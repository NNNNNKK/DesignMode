#pragma once
#include<string>

class Player
{
protected:
	std::string name;
public:
	Player(std::string name)
	{
		this->name = name;
	}

	virtual void Attack() = 0;//攻击
	virtual void Defense() = 0;//防守
};

//前锋
class Forwards final :public Player
{
public:
	Forwards() = delete;
	Forwards(std::string name);
	void Attack() override;
	void Defense() override;
};

//外籍前锋
class ForeignForwards
{
protected:
	std::string name;
public:
	ForeignForwards() = delete;
	ForeignForwards(std::string name);

	void Attack_CH();//中文指令进攻
	void Defense_CH();//中文指令防守
};

//翻译者类
class Translator final: public Player
{
private:
	ForeignForwards foreignForwards;
public:
	Translator() = delete;
	Translator(std::string name);

	void Attack();//攻击
	void Defense();//防守
};