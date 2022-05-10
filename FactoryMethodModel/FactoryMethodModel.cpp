#include "FactoryMethodModel.h"

std::shared_ptr<Leifeng> UndergraduateFactory::CreateLeiFeng()
{
	return std::move(std::make_shared<Undergraduate>());
}

std::shared_ptr<Leifeng> VolunteerFactory::CreateLeiFeng()
{
	return std::move(std::make_shared<Volunteer>());
}
