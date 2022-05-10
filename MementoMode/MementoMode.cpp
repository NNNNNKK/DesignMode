#include "MementoMode.h"

RoleStateMemento::RoleStateMemento(int vit, int atk, int def)
{
	this->vit = vit;
	this->atk = atk;
	this->def = def;
}

std::shared_ptr<RoleStateMemento> GameRole::SaveState()
{
	return std::make_shared<RoleStateMemento>(vit, atk, def);
}

void GameRole::RecoveryState(std::shared_ptr<RoleStateMemento> roleStateMemento)
{
	vit = roleStateMemento->Getvit();
	atk = roleStateMemento->Getatk();
	def = roleStateMemento->Getdef();
}

void GameRole::InitRoleState()
{
	vit = 100;
	atk = 100;
	def = 100;
}

void GameRole::Fight()
{
	vit -= 30;
	atk -= 35;
	def -= 15;
}

void GameRole::StateDisplay()
{
	std::cout << "��������" << vit <<std::endl;
	std::cout << "��������" << atk <<std::endl;
	std::cout << "��������" << def <<std::endl;
}