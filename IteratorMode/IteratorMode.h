#pragma once
#include<string>
#include<vector>
#include<list>

//ѧ���࣬�ۺ϶����д洢��Ԫ��
class Student
{
public:
	std::string m_name;//����
	std::string m_stuNo;//ѧ��
	std::string m_college;//ѧԺ
public:
	Student() = delete;
	explicit Student(std::string name, std::string stuNo, std::string college);//��ֹ��ʽת��
    //չʾѧ����Ϣ
	void ShowInfo();
};

//�����������
class Iterator
{
public:
	//��һ��λ���Ƿ���Ԫ��
	virtual bool hasNext() = 0;
	//���ص�ǰԪ�أ������ߵ���һ��λ��
	virtual Student next() = 0;
};

//�����ѧԺ������
class ComputerIterator : public Iterator
{
private:
	std::vector<Student> _info;		//���������ʵ����ݼ���
	int _curPos;				//��ǰ���ʵ��±�λ��
public:
	ComputerIterator(const std::vector<Student>& info);
	//��һ��λ���Ƿ���Ԫ��
	bool hasNext() override;
	
	//���ص�ǰԪ�أ������ߵ���һ��λ��
	Student next() override;
};

//����ѧԺ������
//��Ϊ�ڲ��洢���ݵ�������list
//Ϊ�˲�ʹ��STL�ṩ�ĵ����������Ա�����˳���Ǵ������ͷ����β��
//ÿ�η���Ԫ��֮���ɾ������ͷ��Ԫ��
class SportIterator : public Iterator
{
private:
	std::list<Student> _info;		//���������ʵ����ݼ���
public:
	//��һ��λ���Ƿ���Ԫ��
	virtual bool hasNext()
	{
		return !_info.empty();
	}
	//���ص�ǰԪ�أ������ߵ���һ��λ��
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

//����ۺ���
class Aggregate
{
public:
	//���ѧ����Ϣ
	virtual void addStudent(const Student& stu) = 0;
	//ɾ��ѧ����Ϣ
	virtual void deleteStudent(const Student& stu) = 0;
	//����������
	virtual Iterator* createIterator() = 0;
};

//�����ѧԺ�ۺ���
class ComputerAggregate : public Aggregate
{
private:
	std::vector<Student> _info;		//ѧ����Ϣ���ݹ�����

public:
	//���ѧ����Ϣ
	virtual void addStudent(const Student& stu)
	{
		_info.emplace_back(stu);
	}

	//ɾ��ѧ����Ϣ
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

	//����������
	virtual Iterator* createIterator()
	{
		return new ComputerIterator(_info);
	}
};

//����ѧԺ�ۺ���
class SportAggregate : public Aggregate
{
private:
	std::list<Student> _info;		//�洢ѧ������ļ���
public:
	//���ѧ����Ϣ
	virtual void addStudent(const Student& stu)
	{
		_info.push_back(stu);
	}
	//ɾ��ѧ����Ϣ
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
	//����������
	virtual Iterator* createIterator()
	{
		return new SportIterator(_info);
	}
};