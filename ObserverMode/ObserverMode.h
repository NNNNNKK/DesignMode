#pragma once
#include<list>
#include<memory>
#include<string>

//����۲�����
class Obsever
{
public:
	virtual void Update() = 0;
};

//����֪ͨ����
class Subject
{
private:
	using SpObserver = std::shared_ptr<Obsever>;
	std::list<SpObserver> observers;

public:
	//���ӹ۲���
	void Attach(SpObserver observer);
	//�Ƴ��۲���
	void Detach(SpObserver observer);
	//֪ͨ
	void Notify();
};

//����֪ͨ����,���й�״̬�������۲��߶���
class ConcreteSubject final : public Subject
{
private:
	std::string subjectState;
public:
	inline void SetState(std::string state) { this->subjectState = state;}
	inline std::string GetState() const { return subjectState; }
};

//����۲��ߣ�ʵ�ֳ���۲��߽�ɫ��Ҫ��ĸ��½ӿڣ��Ա�ʹ�����״̬�������״̬��Э��
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