#include "MediatorMode.h"
#include<iostream>

Country::Country(std::shared_ptr<UnitedNations> mediator)
	:m_mediator(mediator)
{
}

Country::~Country()
{
}

USA::USA(std::shared_ptr<UnitedNations> mediator)
	: Country(mediator)
{
}

void USA::Declare(std::string message)
{
	m_mediator.lock()->Declare(message, this);
}

void USA::GetMessage(std::string message)
{
	std::cout << "美国获得对方的消息：" << message << std::endl;
}

Iraq::Iraq(std::shared_ptr<UnitedNations> mediator)
	: Country(mediator)
{
}

void Iraq::Declare(std::string message)
{
	m_mediator.lock()->Declare(message, this);
}

void Iraq::GetMessage(std::string message)
{
	std::cout << "伊拉克获得对方的消息：" << message << std::endl;
}

void UnitedNationsSecurityCouncil::Declare(std::string name, Country const* colleague)
{
	if (m_usa.lock().get() == colleague)
	{
		m_usa.lock()->GetMessage(name);
	}
	else
	{
		m_iraq.lock()->GetMessage(name);
	}
}