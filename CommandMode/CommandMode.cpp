#include "CommandMode.h"
#include<iostream>
#include<algorithm>

void Barbecuer::BakeMutton()
{
	std::cout << "ը���⴮!" << std::endl;
}

void Barbecuer::BakeChickenWing()
{
	std::cout << "ը����!" << std::endl;
}

BakeMuttonCommand::BakeMuttonCommand(Barbecuer barbecuer)
	: Command(barbecuer)
{
}

void BakeMuttonCommand::ExcuteCommand()
{
	m_barbecuer.BakeMutton();
}

BakeChickenWingCommand::BakeChickenWingCommand(Barbecuer barbecuer)
	: Command(barbecuer)
{
}

void BakeChickenWingCommand::ExcuteCommand()
{
	m_barbecuer.BakeChickenWing();
}

void Waiter::SetOrder(std::shared_ptr<Command> command)
{
	if (command)
	{
		orders.push_back(command);
	}
}

void Waiter::CancleOrder(std::shared_ptr<Command> command)
{
	orders.remove(command);
}

void Waiter::Notify()
{
	std::for_each(orders.cbegin(), orders.cend(), [](std::shared_ptr<Command> command)
	{
		command->ExcuteCommand();
	});
}