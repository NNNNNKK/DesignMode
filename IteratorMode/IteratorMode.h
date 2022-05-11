#pragma once
#include<string>
#include<vector>
#include<list>

//学生类，聚合对象中存储的元素
class Student
{
public:
	std::string m_name;//姓名
	std::string m_stuNo;//学号
	std::string m_college;//学院
public:
	Student() = delete;
	explicit Student(std::string name, std::string stuNo, std::string college);//禁止隐式转换
    //展示学生信息
	void ShowInfo();
};

//抽象迭代器类
class Iterator
{
public:
	//下一个位置是否有元素
	virtual bool hasNext() = 0;
	//返回当前元素，并且走到下一个位置
	virtual Student next() = 0;
};

//计算机学院迭代器
class ComputerIterator : public Iterator
{
private:
	std::vector<Student> _info;		//迭代器访问的数据集合
	int _curPos;				//当前访问的下标位置
public:
	ComputerIterator(const std::vector<Student>& info);
	//下一个位置是否有元素
	bool hasNext() override;
	
	//返回当前元素，并且走到下一个位置
	Student next() override;
};

//体育学院迭代器
//因为内部存储数据的容器是list
//为了不使用STL提供的迭代器，所以遍历的顺序是从链表的头部到尾部
//每次访问元素之后会删除链表头部元素
class SportIterator : public Iterator
{
private:
	std::list<Student> _info;		//迭代器访问的数据集合
public:
	//下一个位置是否有元素
	virtual bool hasNext()
	{
		return !_info.empty();
	}
	//返回当前元素，并且走到下一个位置
	virtual Student next()
	{
		Student front = _info.front();
		_info.pop_front();
		return front;
	}

	SportIterator(const std::list<Student>& info)
		:_info(info)
	{}
};

//抽象聚合类
class Aggregate
{
public:
	//添加学生信息
	virtual void addStudent(const Student& stu) = 0;
	//删除学生信息
	virtual void deleteStudent(const Student& stu) = 0;
	//创建迭代器
	virtual Iterator* createIterator() = 0;
};

//计算机学院聚合类
class ComputerAggregate : public Aggregate
{
private:
	std::vector<Student> _info;		//学生信息数据管理器

public:
	//添加学生信息
	virtual void addStudent(const Student& stu)
	{
		_info.emplace_back(stu);
	}

	//删除学生信息
	virtual void deleteStudent(const Student& stu)
	{
		auto it = _info.begin();
		while (it != _info.end())
		{
			if (it->m_name == stu.m_name && it->m_stuNo == stu.m_stuNo && it->m_college == stu.m_college)
			{
				break;
			}
			++it;
		}
		_info.erase(it);
	}

	//创建迭代器
	virtual Iterator* createIterator()
	{
		return new ComputerIterator(_info);
	}
};

//体育学院聚合类
class SportAggregate : public Aggregate
{
private:
	std::list<Student> _info;		//存储学生对象的集合
public:
	//添加学生信息
	virtual void addStudent(const Student& stu)
	{
		_info.push_back(stu);
	}
	//删除学生信息
	virtual void deleteStudent(const Student& stu)
	{
		auto it = _info.begin();
		while (it != _info.end())
		{
			if (it->m_name == stu.m_name && it->m_stuNo == stu.m_stuNo && it->m_college == stu.m_college)
			{
				break;
			}
			++it;
		}
		_info.erase(it);
	}
	//创建迭代器
	virtual Iterator* createIterator()
	{
		return new SportIterator(_info);
	}
};