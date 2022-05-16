#include"InterpreterMode.h"
#include <iostream>
#include<list>

int main()
{
	Context * context = new Context();
	list<AbstractExpression * > List;
	List.push_back(new TerminalExpression());
	List.push_back(new NoterminalExpression());
	List.push_back(new TerminalExpression());
	List.push_back(new TerminalExpression());

	for (auto exp : List)
	{
		exp->Interpret(context);
	}
}
