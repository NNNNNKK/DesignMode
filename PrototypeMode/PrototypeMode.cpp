#include "PrototypeMode.h"
#include <iostream>

WorkExperience::WorkExperience(std::string workDate, std::string workComany)
	:m_WorkDate(workDate),m_WorkComany(workComany)
{
}

void WorkExperience::SetWorkDate(const std::string  workDate)
{
	m_WorkDate = workDate;
}

void WorkExperience::SetWorkComany(const std::string workComany)
{
	m_WorkComany = workComany;
}

ICloneable* WorkExperience::Clone()
{
	return new WorkExperience(m_WorkDate, m_WorkComany);
}

Resume::Resume(std::string name)
{
	m_Name = name;
	m_pWork = new WorkExperience;
}

Resume::Resume(WorkExperience *pWork)
{
	//reinterpret_cast 转换不安全
	this->m_pWork = reinterpret_cast<WorkExperience *>(pWork->Clone());
}

void Resume::SetPersonalInfo(string sex, string age)
{
	m_Sex = sex;
	m_Age = age;
}

void Resume::SetWorkExperience(string workDate, string company)
{
	m_pWork->SetWorkDate(workDate);
	m_pWork->SetWorkComany(company);
}

void Resume::Display()
{
	std::cout << m_Name << " " << m_Sex << " " << m_Age << std::endl;
	std::cout << "工作经历：" << m_pWork->GetWorkDate()<<" "<< m_pWork->GetWorkComany()<< std::endl;
} 

ICloneable* Resume::Clone()
{
	auto pResume = new Resume(m_pWork);
	pResume->m_Name = m_Name;
	pResume->m_Sex = m_Sex;
	pResume->m_Age = m_Age;
	return pResume;
}
