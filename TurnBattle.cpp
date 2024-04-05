//===========================================
//	バトル本体
//===========================================
#include "TurnBattle.h"
#include "Utility.h"
#include <stdio.h> // printf()


TurnBattle::TurnBattle(Character* player, Character* enemy)
{
	m_player = player;
	m_enemy = enemy;
}

void TurnBattle::InitBattle()
{
	m_turn = 0;
	m_status = IN_BATTLE;
	m_player->InitBattle();
	m_enemy->InitBattle();
}

bool TurnBattle::IsEnd()
{
	return m_status != IN_BATTLE;
}

void TurnBattle::DrawBattleScene()
{
	ClearScreen();

	m_player->Indicate(true);
	printf("\n");
	m_enemy->Indicate(false);
	printf("\n");
}

void TurnBattle::ProcPlayerTurn()
{
	eCommand cmd = SelectCommand();
	m_player->SetCommand(cmd);

	ProcBattle(m_player, m_enemy);
	if (m_enemy->IsDead()) {
		m_enemy->SetDisappear(true);
		DrawBattleScene();
		printf("%sを　たおした!\n", m_enemy->GetName());
		WaitKey();
		m_status = PLAYER_WIN;
	}
}
void TurnBattle::ProcEnemyTurn()
{
	m_player->SetCommand(COMMAND_FIGHT);

	ProcBattle(m_enemy, m_player);
	if (m_player->IsDead()) {
		printf("あなたは　しにました\n");
		WaitKey();
		m_status = PLAYER_LOSE;
	}
}

void TurnBattle::ProcAttack(Character* offense, Character* defense)
{
	DrawBattleScene();
	printf("%sの こうげき!\n", offense->GetName());
	WaitKey();

	int dmg = offense->GetAttackDamage();
	defense->TakeDamage(dmg);

	DrawBattleScene();
	printf("%sに %dの　ダメージ!\n", defense->GetName(), dmg);
	WaitKey();

}
void TurnBattle::ProcMagic(Character* offense, Character* defense)
{
	if (offense->IsAbleMagic() == false) {
		DrawBattleScene();
		printf("MPが たりない!\n");
		WaitKey();
	}
	else {
		DrawBattleScene();
		printf("%sは　ヒールをとなえた!\n", offense->GetName());
		WaitKey();

		offense->UseMagic();

		DrawBattleScene();
		printf("%sのきずが　かいふくした!\n", offense->GetName());
		WaitKey();
	}
}

void TurnBattle::ProcEscape(Character* offense, Character* defense)
{
	printf("%sは　にげだした!\n", offense->GetName());
	WaitKey();
	m_status = PLAYER_ESCAPE;
}

void TurnBattle::ProcBattle(Character* offense, Character* defense)
{
	switch (offense->GetCommand()){
	case eCommand::COMMAND_FIGHT:
		ProcAttack(offense, defense);
		break;
	case eCommand::COMMAND_SPELL:
		ProcMagic(offense, defense);
		break;
	case eCommand::COMMAND_RUN:
		ProcEscape(offense, defense);
		break;
	}
}

eCommand TurnBattle::SelectCommand()
{
	const char* CommandNames[] = {
		"たたかう",
		"じゅもん",
		"にげる",
	};

	int sel = 0;
	while (true) {
		DrawBattleScene();
		for (int i = 0; i < COMMAND_MAX; i++) {
			const char *cursor = i == sel ? ">" : " ";
			printf("%s%s\n", cursor, CommandNames[i]);
		}
		eKey key = GetKey();
		switch (key) {
		case ARROW_U:
			sel--;
			if (sel < 0) {
				sel = COMMAND_MAX - 1;
			}
			break;
		case ARROW_D:
			sel++;
			if (sel >= COMMAND_MAX) {
				sel = 0;
			}
			break;
		case DECIDE:
			return (eCommand)sel;
		}
	}
}

void TurnBattle::Intro()
{
	DrawBattleScene();
	printf("%sが　あらわれた!\n", m_enemy->GetName());
	WaitKey();
}
