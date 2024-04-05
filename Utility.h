#pragma once
//======================================
//	ユーティリティ
//======================================

enum eKey {
	ARROW_U = 0xe048,
	ARROW_L = 0xe04b,
	ARROW_D = 0xe050,
	ARROW_R = 0xe04d,
	DECIDE = 0x0d,
};

void InitRand();
void WaitKey();
eKey GetKey();
void ClearScreen();

