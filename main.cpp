//===========================================
//	メイン
//===========================================
#include "Character.h"
#include "TurnBattle.h"
#include "Utility.h"

int main()
{
	Character* player = new Character(100, 15, 30, "勇者", "");
	Character* boss = new Character(255, 0, 50, "魔王",
		"　　Ａ＠Ａ\n"	/*"　　Ａ＠Ａ\n"*/
		"ψ（▼皿▼）ψ");
	Character* zako = new Character(3, 0, 2, "スライム",
		"／・Д・＼\n"
		"〜〜〜〜〜");

	InitRand();

	TurnBattle* battle = new TurnBattle(player, boss);

	battle->InitBattle();
	battle->Intro();
	while (true)
	{
		battle->ProcPlayerTurn();
		if (battle->IsEnd()) {
			break;
		}
		battle->ProcEnemyTurn();
		if (battle->IsEnd()) {
			break;
		}
	}

	delete battle;
	delete player;
	delete zako;
	delete boss;
	return 0;
}



