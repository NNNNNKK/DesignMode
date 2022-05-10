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

	virtual void Attack() = 0;//����
	virtual void Defense() = 0;//����
};

//ǰ��
class Forwards final :public Player
{
public:
	Forwards() = delete;
	Forwards(std::string name);
	void Attack() override;
	void Defense() override;
};

//�⼮ǰ��
class ForeignForwards
{
protected:
	std::string name;
public:
	ForeignForwards() = delete;
	ForeignForwards(std::string name);

	void Attack_CH();//����ָ�����
	void Defense_CH();//����ָ�����
};

//��������
class Translator final: public Player
{
private:
	ForeignForwards foreignForwards;
public:
	Translator() = delete;
	Translator(std::string name);

	void Attack();//����
	void Defense();//����
};