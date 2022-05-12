
#include <iostream>
#include"CommandMode.h"

int main()
{
	//开店前准备
	Barbecuer barbecuer;
	std::shared_ptr<Command> bakeMuttonCommand1 = std::make_shared<BakeMuttonCommand>(barbecuer);
	std::shared_ptr<Command> bakeChickenWingCommand1 = std::make_shared<BakeChickenWingCommand>(barbecuer);
	std::shared_ptr<Command> bakeMuttonCommand2 = std::make_shared<BakeMuttonCommand>(barbecuer);
	std::shared_ptr<Command> bakeMuttonCommand3 = std::make_shared<BakeMuttonCommand>(barbecuer);
	
	//顾客点餐
	Waiter waiter;
	waiter.SetOrder(bakeMuttonCommand1);
	waiter.SetOrder(bakeChickenWingCommand1);
	waiter.SetOrder(bakeMuttonCommand2);
	waiter.SetOrder(bakeMuttonCommand3);

	//点菜完毕，通知厨房
	waiter.Notify();
}
