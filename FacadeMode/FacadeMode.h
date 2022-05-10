#pragma once

class SubSystemOne
{
public:
	SubSystemOne() = default;
	~SubSystemOne() = default;

	void MethodOne();
};

class SubSystemTwo
{
public:
	SubSystemTwo() = default;
	~SubSystemTwo() = default;

	void MethodTwo();
};

class SubSystemThree
{
public:
	SubSystemThree() = default;
	~SubSystemThree() = default;

	void MethodThree();
};

class SubSystemFour
{
public:
	SubSystemFour() = default;
	~SubSystemFour() = default;

	void MethodFour();
};

//Õ‚π€¿‡
class Facade
{
private:
	SubSystemOne one;
	SubSystemTwo two;
	SubSystemThree three;
	SubSystemFour four;

public:
	void MethodA();
	void MethodB();
};