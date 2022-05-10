#pragma once
#include <iostream>
#include <memory>

class Leifeng
{
public:
	virtual void Sweep()
	{
		std::cout << "ɨ��" << std::endl;
	}

	virtual void Wash()
	{
		std::cout << "ϴ��" << std::endl;
	}

	virtual void BuyRice()
	{
		std::cout << "����" << std::endl;
	}
};

class Undergraduate final : public Leifeng{};
class Volunteer final : public Leifeng{};

//���������
class IFactory
{
public:
	virtual std::shared_ptr<Leifeng> CreateLeiFeng() = 0;
};

//ѧ�׷�Ĵ�ѧ������
class UndergraduateFactory final : public IFactory
{
public:
	std::shared_ptr<Leifeng> CreateLeiFeng() override;
};

//����־Ը�߹���
class VolunteerFactory final :public IFactory
{
public:
	std::shared_ptr<Leifeng> CreateLeiFeng() override;
};