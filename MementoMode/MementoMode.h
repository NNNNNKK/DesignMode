#pragma once
#include<iostream>
#include<string>
#include<memory>

//��Ϸ��ɫ����¼��,���ڴ洢��ɫ״̬
class RoleStateMemento
{
private:
	int vit;
	int atk;
	int def;
public:
	RoleStateMemento() = delete;
	RoleStateMemento(int vit, int atk, int def);
	//������
	inline void Setvit(int vit) { this->vit = vit; }
	inline int Getvit() const { return vit; }
	//������
	inline void Setatk(int atk) { this->atk = atk; }
	inline int Getatk() const { return atk; }
	//������
	inline void Setdef(int def) { this->def = def; }
	inline int Getdef() const { return def; }
};

//��Ϸ��ɫ��
class GameRole
{
private:
	int vit = 0;
	int atk = 0;
	int def = 0;
public:
	GameRole() = default;
	//�����ɫ״̬
	std::shared_ptr<RoleStateMemento> SaveState();
	//�ָ���ɫ״̬
	void RecoveryState(std::shared_ptr<RoleStateMemento> roleStateMemento);

	//��ʼ����ɫ����
	void InitRoleState();
	//��ɫս��������ֵ����
	void Fight();
	//չ�ֽ�ɫ����
	void StateDisplay();
};

//��ɫ״̬������
class RoleStateCaretake
{
private:
	std::shared_ptr<RoleStateMemento> memento;
public:
	RoleStateCaretake() = default;
	//����¼
	inline void SetMemento(std::shared_ptr<RoleStateMemento> memento) { this->memento = memento; }
	inline auto GetMemento() const { return memento; }
};
