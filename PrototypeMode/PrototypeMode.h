/**
 * demo �Ը�ӡ����Ϊ�����������ݰ������˻�����Ϣ��������������Ϣ
 * ������Ҫ����ICloneable��Resume��WorkExperience��
 */


#pragma once
#include <memory>
#include <string>

//ԭ��ģʽ����ӿ�
class ICloneable
{
public:
	virtual ICloneable*  Clone() = 0;
};

//����������
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

//����ԭ����
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
	//���ø�����Ϣ
	void SetPersonalInfo(string sex, string age);
	//���ù�������
	void SetWorkExperience(string workDate,string company);

	void Display();

	//���ؿ�¡����
	ICloneable*  Clone() override;
};
