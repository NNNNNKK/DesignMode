// main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "PrototypeMode.h"

int main()
{
	Resume a("大鸟");
	a.SetPersonalInfo("男", "29");
	a.SetWorkExperience("1998-2000", "XX公司");

	auto b =(Resume*)a.Clone();
	b->SetWorkExperience("1998-2006", "YY企业");

	auto c = (Resume*)a.Clone();
	c->SetPersonalInfo("男", "24");
	c->SetWorkExperience("1998-2003", "ZZ企业");

	a.Display();
	b->Display();
	c->Display();

}

