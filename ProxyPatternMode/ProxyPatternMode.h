#pragma once
#include <string>
#include <memory>

class IGiveGift
{
public:
	virtual void GiveDolls() = 0;
	virtual void GiveFlowers() = 0;
	virtual void GiveChocolate() = 0;
};

class SchoolGirl
{
	std::string name;
public:
	SchoolGirl(const std::string _name);
	SchoolGirl(const SchoolGirl & girl);
	SchoolGirl() = default;

	SchoolGirl & operator = (const SchoolGirl & girl);
	const std::string GetName() const & ;
	void  SetName(const std::string name);
};


class Pursuit final : public IGiveGift
{
	SchoolGirl mm;
public:
	Pursuit(SchoolGirl mm);
	void GiveDolls() override;
	void GiveFlowers() override;
	void GiveChocolate() override;
};
class Proxy final : IGiveGift
{
	std::shared_ptr <IGiveGift> gg;
public:
	Proxy(SchoolGirl mm);
	void GiveDolls() override;
	void GiveFlowers() override;
	void GiveChocolate() override;
};

