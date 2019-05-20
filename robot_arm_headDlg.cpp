
// robot_arm_headDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "robot_arm_head.h"
#include "robot_arm_headDlg.h"
#include "afxdialogex.h"
#include <conio.h>
#include <windows.h> 
#include <stdio.h> 

#include "opencv2/opencv.hpp"//OpenCV
#include "DXLIB/dxlib.h"//サーボモータ（ダイナミクセル）用

	uint16_t ShoulderUpPosition=1700,ShoulderDownPosition=2500,ArmExtendPosition=2200,ArmBendPosition=1900;
	uint16_t HeadFront=2200,HeadLeft=3500,HeadRight=1100;

	//TDeviceID DeviceID1;
	//TErrorCode err = 0;
	//DeviceID1 = DX_OpenPort ("\\\\.\\COM3", 57143);

/*
//////////////マルチスレッド用////////////////
#include <boost/thread.hpp>
using namespace std;
using namespace boost;
//////////////////////////////////////////////
*/
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Crobot_arm_headDlg ダイアログ




Crobot_arm_headDlg::Crobot_arm_headDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Crobot_arm_headDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Crobot_arm_headDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Crobot_arm_headDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Crobot_arm_headDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Crobot_arm_headDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Crobot_arm_headDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Crobot_arm_headDlg::OnBnClickedButton4)
	
	
END_MESSAGE_MAP()


// Crobot_arm_headDlg メッセージ ハンドラー

BOOL Crobot_arm_headDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}



// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。



//TOUCH
void Crobot_arm_headDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	TErrorCode err = 0;
	//uint16_t	initialPosition = 2200,goalPosition=3000;

	TDeviceID DeviceID1;

	//uint16_t ShoulderUpPosition=1000,ShoulderDownPosition=2000,ArmExtendPosition=2200,ArmBendPosition=3000;

	//ポートを開ける
	DeviceID1 = DX_OpenPort("\\\\.\\COM3", 1000000);

		if(DeviceID1){//if文の処理について　http://hmu29.hatenablog.com/entry/2013/08/22/203452
			

				// 動く範囲指定
				DX_WriteWordData(DeviceID1, 1, 6, 0, 100, &err);
				DX_WriteWordData(DeviceID1, 1, 8, 4095, 100, &err);
				// トルクを位置制御モードのために指定
				DX_WriteWordData (DeviceID1, 1, 24, 1, 100, &err);
				// 回転スピードを指定
				DX_WriteWordData (DeviceID1, 1, 32, 20, 100, &err);

				//　サーボを目標位置(GoalPosition)まで移動
				DX_WriteWordData (DeviceID1, 1, 30, 1300, 100, &err);
		}else{
			DX_ClosePort(DeviceID1);
			exit(0);
		}

		DX_ClosePort(DeviceID1);
}

//BALL
void Crobot_arm_headDlg::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	TErrorCode err = 0;
	//uint16_t	initialPosition = 2200,goalPosition=3000;

	TDeviceID DeviceID1;

	//uint16_t ShoulderUpPosition=1000,ShoulderDownPosition=2000,ArmExtendPosition=2200,ArmBendPosition=3000;

		//ポートを開ける
		DeviceID1 = DX_OpenPort("\\\\.\\COM3", 57143);

		if(DeviceID1){//if文の処理について　http://hmu29.hatenablog.com/entry/2013/08/22/203452
			


			// 初期化モードにする
			DX_WriteWordData(DeviceID1, 3, 6, 2000, 100, &err);
			DX_WriteWordData(DeviceID1, 3, 8, 3200, 100, &err);
			DX_WriteWordData(DeviceID1, 1, 6, 1267, 100, &err);
			DX_WriteWordData(DeviceID1, 1, 8, 2200, 100, &err);
			// トルクを位置制御モードのために指定
			DX_WriteWordData (DeviceID1, 3, 24, 1, 100, &err);
			DX_WriteWordData (DeviceID1, 1, 24, 1, 100, &err);
			//
			DX_WriteWordData (DeviceID1, 3, 36, 2500, 100, &err);
			DX_WriteWordData (DeviceID1, 1, 36, 1900, 100, &err);
			// 回転スピードを指定
			DX_WriteWordData (DeviceID1, 3, 32, 450, 100, &err);
			DX_WriteWordData (DeviceID1, 1, 32, 450, 100, &err);
			//　サーボを目標位置(GoalPosition)まで移動
			DX_WriteWordData (DeviceID1, 3, 30, 3100, 100, &err);
			DX_WriteWordData (DeviceID1, 1, 30, 1400, 100, &err);//2000
		}else{
			DX_ClosePort(DeviceID1);
			exit(0);
		}

		DX_ClosePort(DeviceID1);

}

//CAT TEASER
void Crobot_arm_headDlg::OnBnClickedButton3()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	TErrorCode err = 0;
	//uint16_t	initialPosition = 2200,goalPosition=3000;

	TDeviceID DeviceID1;

	//uint16_t ShoulderUpPosition=1000,ShoulderDownPosition=2000,ArmExtendPosition=2200,ArmBendPosition=3000;

		//ポートを開ける
		DeviceID1 = DX_OpenPort("\\\\.\\COM3", 1000000);

		if(DeviceID1){//if文の処理について　http://hmu29.hatenablog.com/entry/2013/08/22/203452
			


			// 初期化モードにする
			DX_WriteWordData(DeviceID1, 1, 6, 0, 100, &err);
			DX_WriteWordData(DeviceID1, 1, 8, 4095, 100, &err);
			// トルクを位置制御モードのために指定
			DX_WriteWordData (DeviceID1, 1, 24, 1, 100, &err);
			//現在の角度
			uint16_t n;
			DX_ReadWordData(DeviceID1,1,36,&n,100,&err);
			//　サーボを目標位置(GoalPosition)まで移動（その場）
			DX_WriteWordData (DeviceID1, 1, 30, n, 100, &err);


			//トルク初期値
			DX_WriteWordData(DeviceID1, 2, 14, 800, 100, &err);
			// 初期化モードにする
			DX_WriteWordData(DeviceID1, 2, 6, 0, 100, &err);
			DX_WriteWordData(DeviceID1, 2, 8, 4095, 100, &err);
			// トルクを位置制御モードのために指定
			DX_WriteWordData (DeviceID1, 2, 24, 1, 100, &err);
			//現在の角度
			uint16_t m;
			DX_ReadWordData(DeviceID1,2,36,&m,100,&err);
			//　サーボを目標位置(GoalPosition)まで移動（その場）
			DX_WriteWordData (DeviceID1, 2, 30, m, 100, &err);

		}else{
			DX_ClosePort(DeviceID1);
			exit(0);
		}

		DX_ClosePort(DeviceID1);

}



//STOP
void Crobot_arm_headDlg::OnBnClickedButton4()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	TErrorCode err = 0;
	//uint16_t	initialPosition = 2200,goalPosition=3000;

	TDeviceID DeviceID1;

	//uint16_t ShoulderUpPosition=1000,ShoulderDownPosition=2000,ArmExtendPosition=2200,ArmBendPosition=3000;

		//ポートを開ける
		DeviceID1 = DX_OpenPort("\\\\.\\COM3", 1000000);

		if(DeviceID1){//if文の処理について　http://hmu29.hatenablog.com/entry/2013/08/22/203452
			

			//トルク初期値
			DX_WriteWordData(DeviceID1, 2, 14, 800, 100, &err);
			// 初期化モードにする
			DX_WriteWordData(DeviceID1, 2, 6, 0, 100, &err);
			DX_WriteWordData(DeviceID1, 2, 8, 4095, 100, &err);
			// トルクを位置制御モードのために指定
			DX_WriteWordData (DeviceID1, 2, 24, 1, 100, &err);

			// 回転スピードを指定
			DX_WriteWordData (DeviceID1, 2, 32, 20, 100, &err);
			//　サーボを目標位置(GoalPosition)まで移動
			DX_WriteWordData (DeviceID1, 2, 30, 950, 100, &err);//2000
		}else{
			DX_ClosePort(DeviceID1);
			exit(0);
		}

		DX_ClosePort(DeviceID1);

}



