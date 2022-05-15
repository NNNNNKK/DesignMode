#include "FlyweightMode.h"
#include<iostream>

User::User(std::string name)
	:m_name(name)
{
}

ConcreteWebSite::ConcreteWebSite(std::string name)
	: m_name(name)
{
}

void ConcreteWebSite::Use(User&& user)
{
	std::cout << "��վ����:" + m_name + "�û�:" + user.GetName() << std::endl;
}

std::shared_ptr<WebSite> WebSiteFactory::GetWebSiteCategory(std::string key)
{
	if (!flyweights[key])
	{
		flyweights[key] = std::make_shared<ConcreteWebSite>(key);
		//������룬��ʱԪ�ؽ������Զ���ʧ��valueΪ��
		//flyweights.emplace(key, std::forward<std::shared_ptr<ConcreteWebSite>>(std::make_shared<ConcreteWebSite>(key)));
	}
	return flyweights[key];
}

const int WebSiteFactory::GetWebSiteCount()
{
	return flyweights.size();
}