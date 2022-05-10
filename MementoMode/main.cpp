#include <iostream>
#include"MementoMode.h"

int main()
{
    //大战前Boss
	auto lixiyao = std::make_shared<GameRole>();
	lixiyao->InitRoleState();
	lixiyao->StateDisplay();
	
	//保存进度
	RoleStateCaretake stateAdmin;
	stateAdmin.SetMemento(lixiyao->SaveState());

	//大战Boss时，属性消耗
	lixiyao->Fight();
	lixiyao->StateDisplay();

	//恢复之前的状态
	lixiyao->RecoveryState(stateAdmin.GetMemento());
	lixiyao->StateDisplay();
}

