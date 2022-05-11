#include "SingletonMode.h"
#include<iostream>

std::mutex SingletonModeSlacker::m_mutex;
SingletonModeSlacker* SingletonModeSlacker::m_instance = nullptr;

SingletonModeSlacker* SingletonModeSlacker::GetInstance()
{
	//˫��������
	if (nullptr == m_instance)
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		if (nullptr == m_instance)
		{
			m_instance = new (std::nothrow) SingletonModeSlacker;
		}
	}
	return m_instance;
}

void SingletonModeSlacker::deleteInstance()
{
	std::lock_guard<std::mutex> lock(m_mutex); // ����
	if (m_instance)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}

SingletonModeSlacker::SingletonModeSlacker()
{
	std::cout << "���캯��!" << std::endl;
}

SingletonModeSlacker::~SingletonModeSlacker()
{
	std::cout << "��������!" << std::endl;
}

SingletonModeStaticSlacker &SingletonModeStaticSlacker::GetInstance()
{
	// �ֲ���̬���Եķ�ʽʵ�ֵ�ʵ��
	static SingletonModeStaticSlacker signal;
	return signal;
}

SingletonModeStaticSlacker::SingletonModeStaticSlacker()
{
	std::cout << "���캯��!" << std::endl;
}

SingletonModeStaticSlacker::~SingletonModeStaticSlacker()
{
	std::cout << "��������!" << std::endl;
}


// ����һ���оͳ�ʼ������ʵ�� ��������̰߳�ȫ
Singleton* Singleton::g_pSingleton = new (std::nothrow) Singleton;

Singleton* Singleton::GetInstance()
{
	return g_pSingleton;
}

void Singleton::deleteInstance()
{
	if (g_pSingleton)
	{
		delete g_pSingleton;
		g_pSingleton = NULL;
	}
}

Singleton::Singleton()
{
	std::cout << "���캯��!" << std::endl;
}

Singleton::~Singleton()
{
	std::cout << "��������!" << std::endl;
}