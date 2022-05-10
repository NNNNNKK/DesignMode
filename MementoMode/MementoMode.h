#pragma once
#include<iostream>
#include<string>
#include<memory>

//游戏角色备忘录类,用于存储角色状态
class RoleStateMemento
{
private:
	int vit;
	int atk;
	int def;
public:
	RoleStateMemento() = delete;
	RoleStateMemento(int vit, int atk, int def);
	//生命力
	inline void Setvit(int vit) { this->vit = vit; }
	inline int Getvit() const { return vit; }
	//攻击力
	inline void Setatk(int atk) { this->atk = atk; }
	inline int Getatk() const { return atk; }
	//防御力
	inline void Setdef(int def) { this->def = def; }
	inline int Getdef() const { return def; }
};

//游戏角色类
class GameRole
{
private:
	int vit = 0;
	int atk = 0;
	int def = 0;
public:
	GameRole() = default;
	//保存角色状态
	std::shared_ptr<RoleStateMemento> SaveState();
	//恢复角色状态
	void RecoveryState(std::shared_ptr<RoleStateMemento> roleStateMemento);

	//初始化角色属性
	void InitRoleState();
	//角色战斗，属性值消耗
	void Fight();
	//展现角色属性
	void StateDisplay();
};

//角色状态管理者
class RoleStateCaretake
{
private:
	std::shared_ptr<RoleStateMemento> memento;
public:
	RoleStateCaretake() = default;
	//备忘录
	inline void SetMemento(std::shared_ptr<RoleStateMemento> memento) { this->memento = memento; }
	inline auto GetMemento() const { return memento; }
};
