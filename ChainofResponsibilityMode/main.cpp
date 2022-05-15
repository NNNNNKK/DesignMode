#include <iostream>
#include"ChainofResponsibilityMode.h"

int main()
{
	std::shared_ptr<Manager> jingli = std::make_shared<CommonManager>("金利");
	std::shared_ptr<Manager> zongjian = std::make_shared<Majordomo>("宗键");
	std::shared_ptr<Manager> zongjingli = std::make_shared<GeneralManager>("宗井里");

	jingli->SetSuperior(zongjian);
	zongjian->SetSuperior(zongjingli);

	auto request = std::make_shared<Request>();
	request->SetRequestType("请假");
	request->SetRequestContent("小菜请假");
	request->SetNumber(1);
	jingli->RequestApplications(request);

	request->SetRequestType("请假");
	request->SetRequestContent("小菜请假");
	request->SetNumber(4);
	jingli->RequestApplications(request);

	request->SetRequestType("加薪");
	request->SetRequestContent("小菜请求加薪");
	request->SetNumber(500);
	jingli->RequestApplications(request);

	request->SetNumber(1000);
	jingli->RequestApplications(request);
}
