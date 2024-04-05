#pragma once
//===========================================
//	キャラクター(プレーヤ、エネミー)
//===========================================

enum eCommand
{
	COMMAND_FIGHT,	// こうげき
	COMMAND_SPELL,	// じゅもん
	COMMAND_RUN,	// にげる
	COMMAND_MAX,
};

class Character
{
	const int SPELL_COST = 3;
private:
	int m_hp;
	int m_maxHp;
	int m_mp;
	int m_maxMp;
	int m_attack;
	const char* m_name;
	const char* m_aa;
	eCommand m_cmd;
	bool m_isDisappear;
public:
	// コンストラクタ
	Character(int maxHp, int maxMp, int attack, const char* name, const char* aa);
	// バトル初期化
	void InitBattle();
	// 表示
	void Indicate(bool isPlayer);
	// 攻撃ダメージ取得
	int GetAttackDamage();
	// ダメージを受ける
	void TakeDamage(int damage);
	// 死んだか?
	bool IsDead();
	// コマンド設定
	void SetCommand(eCommand cmd);
	// コマンド取得
	eCommand GetCommand();
	// じゅもんは可能か?
	bool IsAbleMagic();
	// じゅもんを使用する
	void UseMagic();
	// 名前を取得する
	const char* GetName();
	// 姿をけす
	void SetDisappear(bool isDisappear);
};