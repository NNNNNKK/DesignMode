#include "ChainofResponsibilityMode.h"
#include<iostream>

Manager::Manager(std::string name)
	:m_name(name)
{
}

CommonManager::CommonManager(std::string name)
	:Manager(name)
{
}

void CommonManager::RequestApplications(std::shared_ptr<Request> request)
{
	if ("请假" == request->GetRequestType() && request->GetNumber()<=2)
	{
		std::cout << m_name << ":" << request->GetRequestContent() <<"数量" 
			<< request->GetNumber() << "被批准" << std::endl;
	}
	else
	{
		if (nullptr!= m_superior)
		{
			m_superior->RequestApplications(request);
		}
	}
}

Majordomo::Majordomo(std::string name)
	:Manager(name)
{
}

void Majordomo::RequestApplications(std::shared_ptr<Request> request)
{
	if ("请假" == request->GetRequestType() && request->GetNumber() <= 5)
	{
		std::cout << m_name << ":" << request->GetRequestContent() << "数量"
			<< request->GetNumber() << "被批准" << std::endl;
	}
	else
	{
		if (nullptr != m_superior)
		{
			m_superior->RequestApplications(request);
		}
	}
}

GeneralManager::GeneralManager(std::string name)
	:Manager(name)
{
}

void GeneralManager::RequestApplications(std::shared_ptr<Request> request)
{
	if ("请假" == request->GetRequestType())
	{
		std::cout << m_name << ":" << request->GetRequestContent() << "数量"
			<< request->GetNumber() << "被批准" << std::endl;
	}
	else if("加薪" == request->GetRequestType() &&request->GetNumber()<=500)
	{
		std::cout << m_name << ":" << request->GetRequestContent() << "数量"
			<< request->GetNumber() << "被批准" << std::endl;
	}
	else if("加薪" == request->GetRequestType() && request->GetNumber() > 500)
	{
		std::cout << m_name << ":" << request->GetRequestContent() << "数量"
			<< request->GetNumber() << "再说吧" << std::endl;
	}
}