#include "SingletonMode.h"
#include<iostream>

std::mutex SingletonModeSlacker::m_mutex;
SingletonModeSlacker* SingletonModeSlacker::m_instance = nullptr;

SingletonModeSlacker* SingletonModeSlacker::GetInstance()
{
	//双检锁机制
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
	std::lock_guard<std::mutex> lock(m_mutex); // 加锁
	if (m_instance)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}

SingletonModeSlacker::SingletonModeSlacker()
{
	std::cout << "构造函数!" << std::endl;
}

SingletonModeSlacker::~SingletonModeSlacker()
{
	std::cout << "析构函数!" << std::endl;
}

SingletonModeStaticSlacker &SingletonModeStaticSlacker::GetInstance()
{
	// 局部静态特性的方式实现单实例
	static SingletonModeStaticSlacker signal;
	return signal;
}

SingletonModeStaticSlacker::SingletonModeStaticSlacker()
{
	std::cout << "构造函数!" << std::endl;
}

SingletonModeStaticSlacker::~SingletonModeStaticSlacker()
{
	std::cout << "析构函数!" << std::endl;
}


// 代码一运行就初始化创建实例 ，本身就线程安全
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
	std::cout << "构造函数!" << std::endl;
}

Singleton::~Singleton()
{
	std::cout << "析构函数!" << std::endl;
}