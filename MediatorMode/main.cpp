#include"MediatorMode.h"
#include <iostream>

int main()
{
	auto UNSC = std::make_shared<UnitedNationsSecurityCouncil>();
	auto c1 = std::make_shared<USA>(UNSC);
	auto c2 = std::make_shared<Iraq>(UNSC);

	UNSC->SetUSA(c1);
	UNSC->SetIraq(c2);

	c1->Declare("不准研究核武器，否则要发动战争!");
	c2->Declare("我们没有研究核武器，也不怕侵略!");
}

