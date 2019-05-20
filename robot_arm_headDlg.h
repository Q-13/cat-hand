
// robot_arm_headDlg.h : ヘッダー ファイル
//

#pragma once


// Crobot_arm_headDlg ダイアログ
class Crobot_arm_headDlg : public CDialogEx
{
// コンストラクション
public:
	Crobot_arm_headDlg(CWnd* pParent = NULL);	// 標準コンストラクター

// ダイアログ データ
	enum { IDD = IDD_ROBOT_ARM_HEAD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	
};
