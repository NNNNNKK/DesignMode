#pragma once
#include<string>
#include<memory>


class Country;
//���Ϲ�������
class UnitedNations
{
public:
	virtual void Declare(std::string name, Country const* colleague) = 0;
};

//���ҳ�����
class Country
{
protected:
	std::weak_ptr<UnitedNations> m_mediator;
public:
	Country(std::shared_ptr<UnitedNations> mediator);
	~Country();
};

//������
class USA final :public Country
{
public:
	USA(std::shared_ptr<UnitedNations> mediator);
	//����
	void Declare(std::string message);
	//�����Ϣ
	void GetMessage(std::string message);
};

//��������
class Iraq final :public Country
{
public:
	Iraq(std::shared_ptr<UnitedNations> mediator);
	//����
	void Declare(std::string message);
	//�����Ϣ
	void GetMessage(std::string message);
};

//���Ϲ������
class UnitedNationsSecurityCouncil final :public UnitedNations
{
private:
	std::weak_ptr<USA> m_usa;
	std::weak_ptr<Iraq> m_iraq;
public:
	inline void SetUSA(std::shared_ptr<USA> usa) { m_usa = usa; }
	inline void SetIraq(std::shared_ptr<Iraq> iraq) { m_iraq = iraq; }

	void Declare(std::string name, Country const* colleague) override;
};