#pragma once
#include<string>
#include<memory>

//����
class Request
{
private:
	std::string m_requestType;//��������
	std::string m_requestContent;//��������
	int m_number;//����
public:
	Request() = default;
	inline void SetRequestType(std::string requestType) { m_requestType = requestType; }
	inline std::string GetRequestType() const {return m_requestType ; }

	inline void SetRequestContent(std::string requestContent) { m_requestContent = requestContent; }
	inline std::string GetRequestContent() const {return m_requestContent; }

	inline void SetNumber(int number) { m_number = number; }
	inline int GetNumber() const { return m_number; }
};

//��������
class Manager
{
protected:
	std::string m_name;
	//�ϼ�������
	std::shared_ptr<Manager> m_superior;

public:
	Manager(std::string name);
	//�����ϼ�������
	void SetSuperior(std::shared_ptr<Manager> superior) { m_superior = superior; }
	//��������
	virtual void RequestApplications(std::shared_ptr<Request> superior) = 0;
}; 

//�ܾ�����
class CommonManager final :public Manager
{
public:
	CommonManager(std::string name);
	void RequestApplications(std::shared_ptr<Request> request) override;
};

//�ܼ���
class Majordomo final :public Manager
{
public:
	Majordomo(std::string name);
	void RequestApplications(std::shared_ptr<Request> request) override;
};

//�ܾ�����
class GeneralManager final :public Manager
{
public:
	GeneralManager(std::string name);
	void RequestApplications(std::shared_ptr<Request> request) override;
};