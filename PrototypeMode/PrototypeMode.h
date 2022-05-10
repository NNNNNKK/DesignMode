/**
 * demo 以复印简历为例，建立内容包括个人基本信息，工作经历等信息
 * 案例主要包含ICloneable，Resume，WorkExperience类
 */


#pragma once
#include <memory>
#include <string>

//原型模式抽象接口
class ICloneable
{
public:
	virtual ICloneable*  Clone() = 0;
};

//工作经历类
class WorkExperience final : public ICloneable
{
private:
	std::string m_WorkDate;
	std::string m_WorkComany;
public:
	WorkExperience() = default;
	WorkExperience(std::string workDate, std::string workComany);
	void SetWorkDate(const std::string  workDate);
	void SetWorkComany(const std::string  workComany);
	inline std::string GetWorkDate() const { return m_WorkDate; }
	inline std::string GetWorkComany() const { return m_WorkComany; }

	ICloneable*  Clone() override;
};

//简历原型类
class Resume final : public ICloneable
{
private:
	using string = std::string;
	string m_Name;
	string m_Sex;
	string m_Age;
	WorkExperience* m_pWork = nullptr;

public:
	Resume(std::string name);
	Resume(WorkExperience * pWork);
	//设置个人信息
	void SetPersonalInfo(string sex, string age);
	//设置工作经历
	void SetWorkExperience(string workDate,string company);

	void Display();

	//重载克隆方法
	ICloneable*  Clone() override;
};
