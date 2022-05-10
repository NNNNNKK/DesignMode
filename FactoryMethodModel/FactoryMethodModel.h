#pragma once
#include <iostream>
#include <memory>

class Leifeng
{
public:
	virtual void Sweep()
	{
		std::cout << "扫地" << std::endl;
	}

	virtual void Wash()
	{
		std::cout << "洗衣" << std::endl;
	}

	virtual void BuyRice()
	{
		std::cout << "买米" << std::endl;
	}
};

class Undergraduate final : public Leifeng{};
class Volunteer final : public Leifeng{};

//工厂虚基类
class IFactory
{
public:
	virtual std::shared_ptr<Leifeng> CreateLeiFeng() = 0;
};

//学雷锋的大学生工厂
class UndergraduateFactory final : public IFactory
{
public:
	std::shared_ptr<Leifeng> CreateLeiFeng() override;
};

//社区志愿者工厂
class VolunteerFactory final :public IFactory
{
public:
	std::shared_ptr<Leifeng> CreateLeiFeng() override;
};