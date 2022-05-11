#pragma once
#include<mutex>

//����������ʽ�������̰߳�ȫ��
class SingletonModeSlacker
{
private:
	SingletonModeSlacker();
	~SingletonModeSlacker();

	// ���俽������͸�ֵ�����Ϊ˽�к���, ��ֹ�ⲿ�����͸�ֵ
	SingletonModeSlacker(const SingletonModeSlacker &signal);
	const SingletonModeSlacker &operator=(const SingletonModeSlacker &signal);
private:
	static SingletonModeSlacker* m_instance;
	static std::mutex m_mutex;
public:
	static SingletonModeSlacker* GetInstance();
	static void deleteInstance();
};

//�ڲ���̬��������������(C++11 �̰߳�ȫ),�Ƽ�
class SingletonModeStaticSlacker
{
public:
	// ��ȡ��ʵ������
	static SingletonModeStaticSlacker &GetInstance();
private:
	// ��ֹ�ⲿ����
	SingletonModeStaticSlacker();
	// ��ֹ�ⲿ����
	~SingletonModeStaticSlacker();
	// ��ֹ�ⲿ���ƹ���
	SingletonModeStaticSlacker(const SingletonModeStaticSlacker &signal);
	// ��ֹ�ⲿ��ֵ����
	const SingletonModeStaticSlacker &operator=(const SingletonModeStaticSlacker &signal);
};


//����ʽ����ģʽ
class Singleton
{
public:
	// ��ȡ��ʵ��
	static Singleton* GetInstance();

	// �ͷŵ�ʵ���������˳�ʱ����
	static void deleteInstance();
private:
	// ���乹���������Ϊ˽�е�, ��ֹ�ⲿ���������
	Singleton();
	~Singleton();

	// ���俽������͸�ֵ�����Ϊ˽�к���, ��ֹ�ⲿ�����͸�ֵ
	Singleton(const Singleton &signal);
	const Singleton &operator=(const Singleton &signal);

private:
	// Ψһ��ʵ������ָ��
	static Singleton *g_pSingleton;
};