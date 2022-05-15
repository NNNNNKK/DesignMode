#pragma once
#include<string>
#include<memory>


class Country;
//联合国抽象类
class UnitedNations
{
public:
	virtual void Declare(std::string name, Country const* colleague) = 0;
};

//国家抽象类
class Country
{
protected:
	std::weak_ptr<UnitedNations> m_mediator;
public:
	Country(std::shared_ptr<UnitedNations> mediator);
	~Country();
};

//美国类
class USA final :public Country
{
public:
	USA(std::shared_ptr<UnitedNations> mediator);
	//声明
	void Declare(std::string message);
	//获得消息
	void GetMessage(std::string message);
};

//伊拉克类
class Iraq final :public Country
{
public:
	Iraq(std::shared_ptr<UnitedNations> mediator);
	//声明
	void Declare(std::string message);
	//获得消息
	void GetMessage(std::string message);
};

//联合国安理会
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