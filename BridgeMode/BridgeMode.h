#pragma once
#include<memory>

//手机软件类
class HandsetSoft
{
public:
	virtual void Run() = 0;
};

//手机游戏软件
class HandsetGame final :public HandsetSoft
{
public:
	void Run() override;
};

//手机通讯录软件
class HandsetAddress final :public HandsetSoft
{
public:
	void Run() override;
};

//手机品牌类
class HandsetBrand
{
protected:
	std::shared_ptr<HandsetSoft> soft;
public:
	//设置手机软件
	void SetHandsetSoft(std::shared_ptr<HandsetSoft> soft)
	{
		this->soft = soft;
	}
	//运行手机软件
	virtual void Run() = 0;
};

//手机品牌N
class HandsetBrandN final :public HandsetBrand
{
public:
	void Run() override;
};

//手机品牌M
class HandsetBrandM final :public HandsetBrand
{
public:
	void Run() override;
};