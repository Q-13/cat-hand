
// robot_arm_headDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once


// Crobot_arm_headDlg �_�C�A���O
class Crobot_arm_headDlg : public CDialogEx
{
// �R���X�g���N�V����
public:
	Crobot_arm_headDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^�[

// �_�C�A���O �f�[�^
	enum { IDD = IDD_ROBOT_ARM_HEAD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g


// ����
protected:
	HICON m_hIcon;

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	
};
