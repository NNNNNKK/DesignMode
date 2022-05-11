#include <iostream>
#include"IteratorMode.h"
#include<iostream>

int main()
{
#pragma region ComputerCollegeTest
	Aggregate* computerCollege = new ComputerAggregate();
	computerCollege->addStudent(Student("索隆", "11", "计算机"));
	computerCollege->addStudent(Student("红发香克斯", "12", "计算机"));
	computerCollege->addStudent(Student("路飞", "13", "计算机"));
	computerCollege->addStudent(Student("娜美", "14", "计算机"));
	computerCollege->addStudent(Student("山治", "15", "计算机"));

	Iterator* itcomputerCollege = computerCollege->createIterator();
	std::cout << "*************   计算机学院   **************" << std::endl;
	while (itcomputerCollege->hasNext())
	{
		itcomputerCollege->next().ShowInfo();
	}
#pragma endregion

#pragma region SportCollegeTest
	Aggregate* sportCollege = new SportAggregate();
	sportCollege->addStudent(Student("白胡子", "0", "体育"));
	sportCollege->addStudent(Student("雷利", "1", "体育"));
	sportCollege->addStudent(Student("罗杰", "2", "体育"));
	sportCollege->addStudent(Student("凯多", "3", "体育"));
	sportCollege->addStudent(Student("黑胡子", "4", "体育"));
	sportCollege->addStudent(Student("BigMom", "5", "体育"));

	Iterator* itsportCollege = sportCollege->createIterator();
	std::cout << "*************   体育学院   **************" << std::endl;
	while (itsportCollege->hasNext())
	{
		itsportCollege->next().ShowInfo();
	}
#pragma endregion
}
