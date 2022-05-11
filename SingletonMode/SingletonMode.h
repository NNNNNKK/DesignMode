#pragma once
#include<mutex>

//加锁的懒汉式单例（线程安全）
class SingletonModeSlacker
{
private:
	SingletonModeSlacker();
	~SingletonModeSlacker();

	// 将其拷贝构造和赋值构造成为私有函数, 禁止外部拷贝和赋值
	SingletonModeSlacker(const SingletonModeSlacker &signal);
	const SingletonModeSlacker &operator=(const SingletonModeSlacker &signal);
private:
	static SingletonModeSlacker* m_instance;
	static std::mutex m_mutex;
public:
	static SingletonModeSlacker* GetInstance();
	static void deleteInstance();
};

//内部静态变量的懒汉单例(C++11 线程安全),推荐
class SingletonModeStaticSlacker
{
public:
	// 获取单实例对象
	static SingletonModeStaticSlacker &GetInstance();
private:
	// 禁止外部构造
	SingletonModeStaticSlacker();
	// 禁止外部析构
	~SingletonModeStaticSlacker();
	// 禁止外部复制构造
	SingletonModeStaticSlacker(const SingletonModeStaticSlacker &signal);
	// 禁止外部赋值操作
	const SingletonModeStaticSlacker &operator=(const SingletonModeStaticSlacker &signal);
};


//饿汉式单例模式
class Singleton
{
public:
	// 获取单实例
	static Singleton* GetInstance();

	// 释放单实例，进程退出时调用
	static void deleteInstance();
private:
	// 将其构造和析构成为私有的, 禁止外部构造和析构
	Singleton();
	~Singleton();

	// 将其拷贝构造和赋值构造成为私有函数, 禁止外部拷贝和赋值
	Singleton(const Singleton &signal);
	const Singleton &operator=(const Singleton &signal);

private:
	// 唯一单实例对象指针
	static Singleton *g_pSingleton;
};