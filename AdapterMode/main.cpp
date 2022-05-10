
#include <iostream>
#include"AdapterMode.h"
#include<memory>

int main()
{
	std::shared_ptr<Player> player = std::make_shared<Forwards>("巴蒂尔");
	player->Attack();
	player->Defense();

	player.reset(new Translator("姚明"));
	player->Attack();
	player->Defense();
}
