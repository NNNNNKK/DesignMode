#include"FlyweightMode.h"
#include <iostream>

int main()
{
	WebSiteFactory f;
	auto fx = f.GetWebSiteCategory("产品展示");
	fx->Use(std::move(User("小菜")));

	auto fy = f.GetWebSiteCategory("产品展示");
	fx->Use(User("大鸟"));

	auto fz = f.GetWebSiteCategory("产品展示");
	fz->Use(User("娇娇"));

	auto f1 = f.GetWebSiteCategory("博客");
	f1->Use(User("老顽童"));

	auto fm = f.GetWebSiteCategory("博客");
	fm->Use(User("桃谷六仙"));

	auto fn = f.GetWebSiteCategory("博客");
	fn->Use(User("南海鳄神"));

	std::cout << "得到的网站分类总数为:" << f.GetWebSiteCount() << std::endl;
}
