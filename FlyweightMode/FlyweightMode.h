#pragma once
#include<string>
#include<memory>
#include<map>

//�û���
class User
{
private:
	std::string m_name;
public:
	User(std::string name);
	inline std::string GetName() { return m_name; }
};

//��վ������
class WebSite
{
public:
	virtual void Use(User && user) = 0;
};

//������վ��
class ConcreteWebSite final :public WebSite
{
private:
	std::string m_name = "";
public:
	ConcreteWebSite(std::string name);
	void Use(User && user) override;
};

//��վ������
class WebSiteFactory
{
private:
	std::map<std::string, std::shared_ptr<WebSite>> flyweights;
public:
	//�����վ����
	std::shared_ptr<WebSite> GetWebSiteCategory(std::string key);
	//�����վ��������
	const int GetWebSiteCount();
};