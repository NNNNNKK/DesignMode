#pragma once
#include<string>
#include<memory>
#include<map>

//用户类
class User
{
private:
	std::string m_name;
public:
	User(std::string name);
	inline std::string GetName() { return m_name; }
};

//网站抽象类
class WebSite
{
public:
	virtual void Use(User && user) = 0;
};

//具体网站类
class ConcreteWebSite final :public WebSite
{
private:
	std::string m_name = "";
public:
	ConcreteWebSite(std::string name);
	void Use(User && user) override;
};

//网站工厂类
class WebSiteFactory
{
private:
	std::map<std::string, std::shared_ptr<WebSite>> flyweights;
public:
	//获得网站分类
	std::shared_ptr<WebSite> GetWebSiteCategory(std::string key);
	//获得网站分类数量
	const int GetWebSiteCount();
};