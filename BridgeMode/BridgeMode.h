#pragma once
#include<memory>

//�ֻ������
class HandsetSoft
{
public:
	virtual void Run() = 0;
};

//�ֻ���Ϸ���
class HandsetGame final :public HandsetSoft
{
public:
	void Run() override;
};

//�ֻ�ͨѶ¼���
class HandsetAddress final :public HandsetSoft
{
public:
	void Run() override;
};

//�ֻ�Ʒ����
class HandsetBrand
{
protected:
	std::shared_ptr<HandsetSoft> soft;
public:
	//�����ֻ����
	void SetHandsetSoft(std::shared_ptr<HandsetSoft> soft)
	{
		this->soft = soft;
	}
	//�����ֻ����
	virtual void Run() = 0;
};

//�ֻ�Ʒ��N
class HandsetBrandN final :public HandsetBrand
{
public:
	void Run() override;
};

//�ֻ�Ʒ��M
class HandsetBrandM final :public HandsetBrand
{
public:
	void Run() override;
};