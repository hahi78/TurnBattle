#pragma once
//===========================================
//	バトル本体
//===========================================
#include "Character.h"

enum eBattleStatus
{
	IN_BATTLE,     // バトル中
	PLAYER_WIN,    // プレーヤ勝利
	PLAYER_LOSE,   // プレーヤ敗北
	PLAYER_ESCAPE, // プレーヤ逃走
};


class TurnBattle
{
private:
	int m_turn;
	eBattleStatus m_status;
	Character* m_player;
	Character* m_enemy;
public:
	// コンストラクタ
	TurnBattle(Character* player, Character* enemy);
	// 戦闘初期化
	void InitBattle();
	// イントロ表示
	void Intro();
	// プレーヤのターン処理
	void ProcPlayerTurn();
	// エネミーのターン処理
	void ProcEnemyTurn();
	// 終了?
	bool IsEnd();
protected:
	void DrawBattleScene();
	void ProcBattle(Character* offense, Character* defense);
	void ProcAttack(Character* offense, Character* defense);
	void ProcMagic(Character* offense, Character* defense);
	void ProcEscape(Character* offense, Character* defense);
	eCommand SelectCommand();

};