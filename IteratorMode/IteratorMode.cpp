#include "IteratorMode.h"
#include<iostream>

Student::Student(std::string name, std::string stuNo, std::string college)
	:m_name(name),m_stuNo(stuNo),m_college(college)
{
}
void Student::ShowInfo()
{
	std::cout << "����: " << m_name << "\tѧ��: " << m_stuNo << "\tѧԺ: " << m_college << std::endl;
}

ComputerIterator::ComputerIterator(const std::vector<Student>& info)
: _info(info), _curPos(0)
{
}

bool ComputerIterator::hasNext()
{
	return _curPos < _info.size();
}

Student ComputerIterator::next()
{
	return _info[_curPos++];
}