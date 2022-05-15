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
	if ("���" == request->GetRequestType() && request->GetNumber()<=2)
	{
		std::cout << m_name << ":" << request->GetRequestContent() <<"����" 
			<< request->GetNumber() << "����׼" << std::endl;
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
	if ("���" == request->GetRequestType() && request->GetNumber() <= 5)
	{
		std::cout << m_name << ":" << request->GetRequestContent() << "����"
			<< request->GetNumber() << "����׼" << std::endl;
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
	if ("���" == request->GetRequestType())
	{
		std::cout << m_name << ":" << request->GetRequestContent() << "����"
			<< request->GetNumber() << "����׼" << std::endl;
	}
	else if("��н" == request->GetRequestType() &&request->GetNumber()<=500)
	{
		std::cout << m_name << ":" << request->GetRequestContent() << "����"
			<< request->GetNumber() << "����׼" << std::endl;
	}
	else if("��н" == request->GetRequestType() && request->GetNumber() > 500)
	{
		std::cout << m_name << ":" << request->GetRequestContent() << "����"
			<< request->GetNumber() << "��˵��" << std::endl;
	}
}