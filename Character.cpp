//===========================================
//	キャラクター(プレーヤ、エネミー)
//===========================================
#include "Character.h"
#include <stdlib.h> // rand() 
#include <stdio.h> // printf()

Character::Character(int maxHp, int maxMp, int attack,const char* name,const char* aa)
{
	m_maxHp = maxHp;
	m_maxMp = maxMp;
	m_attack = attack;
	m_name = name;
	m_aa = aa;
}
void Character::InitBattle()
{
	m_hp = m_maxHp;
	m_mp = m_maxMp;
	m_cmd = COMMAND_FIGHT;
	m_isDisappear = false;
}
void Character::TakeDamage(int damage)
{
	if (m_hp > damage) {
		m_hp -= damage;
	}
	else {
		m_hp = 0;
	}
}
int Character::GetAttackDamage()
{
	int dmg=1 + rand() % m_attack;
	return dmg;
}
bool Character::IsDead()
{
	return m_hp <= 0;
}

void Character::SetCommand(eCommand cmd)
{
	m_cmd = cmd;
}
eCommand Character::GetCommand()
{
	return m_cmd;
}
bool Character::IsAbleMagic()
{
	return m_mp >= SPELL_COST;
}
void Character::UseMagic()
{
	if (m_mp > SPELL_COST) {
		m_mp -= SPELL_COST;
	}
	else {
		m_mp = 0;
	}
	m_hp = m_maxHp;
}
const char* Character::GetName()
{
	return m_name;
}
void Character::SetDisappear(bool isDisappear)
{
	m_isDisappear = isDisappear;
}
void Character::Indicate(bool isPlayer)
{
	if (isPlayer) {
		printf("%s\n", m_name);
		printf("ＨＰ：%d／%d　ＭＰ：%d／%d\n", m_hp, m_maxHp, m_mp, m_maxMp);
	}
	else {
		if (m_isDisappear == false) {
			printf("%s", m_aa);
		}
		printf("（ＨＰ：%d／%d）\n", m_hp, m_maxHp);
	}
}