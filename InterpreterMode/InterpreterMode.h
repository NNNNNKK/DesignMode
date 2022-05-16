#pragma once
#include<string>
#include<iostream>

using namespace std;
class Context
{
private:
	string input;

public:
	string get()
	{
		return input;
	}

	string set(string input)
	{
		this->input = input;
	}
};

class AbstractExpression
{
public:
	virtual void Interpret(Context * context) = 0;
};


class TerminalExpression : public AbstractExpression
{
public:
	void Interpret(Context * context) override
	{
		cout << "ÖÕ¶Ë½âÊÍÆ÷" << endl;
	}
};

class NoterminalExpression : public AbstractExpression
{
public:
	void Interpret(Context * context) override
	{
		cout << "·ÇÖÕ¶Ë½âÊÍÆ÷" << endl;
	}
};



