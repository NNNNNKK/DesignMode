#pragma once
#include<string>
#include<memory>

//申请
class Request
{
private:
	std::string m_requestType;//请求类型
	std::string m_requestContent;//请求数量
	int m_number;//数量
public:
	Request() = default;
	inline void SetRequestType(std::string requestType) { m_requestType = requestType; }
	inline std::string GetRequestType() const {return m_requestType ; }

	inline void SetRequestContent(std::string requestContent) { m_requestContent = requestContent; }
	inline std::string GetRequestContent() const {return m_requestContent; }

	inline void SetNumber(int number) { m_number = number; }
	inline int GetNumber() const { return m_number; }
};

//管理者类
class Manager
{
protected:
	std::string m_name;
	//上级管理者
	std::shared_ptr<Manager> m_superior;

public:
	Manager(std::string name);
	//设置上级管理者
	void SetSuperior(std::shared_ptr<Manager> superior) { m_superior = superior; }
	//申请请求
	virtual void RequestApplications(std::shared_ptr<Request> superior) = 0;
}; 

//总经理类
class CommonManager final :public Manager
{
public:
	CommonManager(std::string name);
	void RequestApplications(std::shared_ptr<Request> request) override;
};

//总监类
class Majordomo final :public Manager
{
public:
	Majordomo(std::string name);
	void RequestApplications(std::shared_ptr<Request> request) override;
};

//总经理类
class GeneralManager final :public Manager
{
public:
	GeneralManager(std::string name);
	void RequestApplications(std::shared_ptr<Request> request) override;
};