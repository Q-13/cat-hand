
// robot_arm_head.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// Crobot_arm_headApp:
// このクラスの実装については、robot_arm_head.cpp を参照してください。
//

class Crobot_arm_headApp : public CWinApp
{
public:
	Crobot_arm_headApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern Crobot_arm_headApp theApp;