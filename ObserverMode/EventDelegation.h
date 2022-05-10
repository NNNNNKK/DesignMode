#pragma once
#include<iostream>
#include<string>
#include<functional>
#include<list>
#include<algorithm>

//֪ͨ�߽ӿ�
class SubjectDeleGate 
{
protected:
	std::list<std::function<void()>> delegates;//�洢������ĺ���ָ�룬������ԭ�ͱ�����ͬ
public:
	void Notify()
	{
		std::for_each(delegates.cbegin(), 
			delegates.cend(), [](std::function<void()> f){f();});
	}

	//״̬�ֶεĶ�д
	virtual void SetState(std::string state) = 0;
	virtual std::string GetSate() const = 0;
	//����������֪ͨ����
	void AddDelegate(std::function<void()> delegate)
	{
		delegates.emplace_back(delegate);
	}
};

//�鿴��Ʊ��
class StockObserver
{
private:
	std::string name;
	std::shared_ptr<SubjectDeleGate> subject;
public:
	StockObserver(std::string name, std::shared_ptr<SubjectDeleGate> subject);

	//�رչ�Ʊ����
	void CloseStockMarket();
};

//��NBA��ͬ����
class NBAObserver
{
private:
	std::string name;
	std::shared_ptr<SubjectDeleGate> subject;
public:
	NBAObserver(std::string name, std::shared_ptr<SubjectDeleGate> subject);

	//�ر�NBAֱ��
	void CloseNBADirectSeeding();
};

//�ϰ���
class Boss final : public SubjectDeleGate
{
private:
	std::string action;
public:
	inline void SetState(std::string state) override { this->action = state; }
	inline std::string GetSate() const override { return action; }
};