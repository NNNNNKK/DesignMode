
#include <iostream>
#include"BridgeMode.h"

int main()
{
	std::shared_ptr<HandsetBrand> ab = std::make_shared<HandsetBrandM>();
	ab->SetHandsetSoft(std::make_shared<HandsetGame>());
	ab->Run();
	ab->SetHandsetSoft(std::make_shared<HandsetAddress>());
	ab->Run();

	ab.reset(new HandsetBrandN);
	ab->SetHandsetSoft(std::make_shared<HandsetGame>());
	ab->Run();
	ab->SetHandsetSoft(std::make_shared<HandsetAddress>());
	ab->Run();
}
