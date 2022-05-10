#include <iostream>
#include "FactoryMethodModel.h"

int main()
{
	IFactory * factory = new UndergraduateFactory();
	 auto leifeng1 = factory->CreateLeiFeng();
	 leifeng1->BuyRice();
	 leifeng1->Sweep();
	 leifeng1->Wash();
    //std::cout << "Hello World!\n";
}

