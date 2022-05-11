#include "BridgeMode.h"
#include<iostream>

void HandsetGame::Run()
{
	std::cout << "运行手机游戏!" << std::endl;
}

void HandsetAddress::Run()
{
	std::cout << "运行手机通讯录!" << std::endl;
}

void HandsetBrandN::Run()
{
	soft->Run();
}

void HandsetBrandM::Run()
{
	soft->Run();
}