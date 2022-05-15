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
	std::cout << "网站分类:" + m_name + "用户:" + user.GetName() << std::endl;
}

std::shared_ptr<WebSite> WebSiteFactory::GetWebSiteCategory(std::string key)
{
	if (!flyweights[key])
	{
		flyweights[key] = std::make_shared<ConcreteWebSite>(key);
		//下面代码，临时元素结束后，自动消失，value为空
		//flyweights.emplace(key, std::forward<std::shared_ptr<ConcreteWebSite>>(std::make_shared<ConcreteWebSite>(key)));
	}
	return flyweights[key];
}

const int WebSiteFactory::GetWebSiteCount()
{
	return flyweights.size();
}