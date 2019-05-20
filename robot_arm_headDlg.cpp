
// robot_arm_headDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "robot_arm_head.h"
#include "robot_arm_headDlg.h"
#include "afxdialogex.h"
#include <conio.h>
#include <windows.h> 
#include <stdio.h> 

#include "opencv2/opencv.hpp"//OpenCV
#include "DXLIB/dxlib.h"//�T�[�{���[�^�i�_�C�i�~�N�Z���j�p

	uint16_t ShoulderUpPosition=1700,ShoulderDownPosition=2500,ArmExtendPosition=2200,ArmBendPosition=1900;
	uint16_t HeadFront=2200,HeadLeft=3500,HeadRight=1100;

	//TDeviceID DeviceID1;
	//TErrorCode err = 0;
	//DeviceID1 = DX_OpenPort ("\\\\.\\COM3", 57143);

/*
//////////////�}���`�X���b�h�p////////////////
#include <boost/thread.hpp>
using namespace std;
using namespace boost;
//////////////////////////////////////////////
*/
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// �A�v���P�[�V�����̃o�[�W�������Ɏg���� CAboutDlg �_�C�A���O

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

// ����
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


// Crobot_arm_headDlg �_�C�A���O




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


// Crobot_arm_headDlg ���b�Z�[�W �n���h���[

BOOL Crobot_arm_headDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "�o�[�W�������..." ���j���[���V�X�e�� ���j���[�ɒǉ����܂��B

	// IDM_ABOUTBOX �́A�V�X�e�� �R�}���h�͈͓̔��ɂȂ���΂Ȃ�܂���B
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

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}



// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B



//TOUCH
void Crobot_arm_headDlg::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	TErrorCode err = 0;
	//uint16_t	initialPosition = 2200,goalPosition=3000;

	TDeviceID DeviceID1;

	//uint16_t ShoulderUpPosition=1000,ShoulderDownPosition=2000,ArmExtendPosition=2200,ArmBendPosition=3000;

	//�|�[�g���J����
	DeviceID1 = DX_OpenPort("\\\\.\\COM3", 1000000);

		if(DeviceID1){//if���̏����ɂ��ā@http://hmu29.hatenablog.com/entry/2013/08/22/203452
			

				// �����͈͎w��
				DX_WriteWordData(DeviceID1, 1, 6, 0, 100, &err);
				DX_WriteWordData(DeviceID1, 1, 8, 4095, 100, &err);
				// �g���N���ʒu���䃂�[�h�̂��߂Ɏw��
				DX_WriteWordData (DeviceID1, 1, 24, 1, 100, &err);
				// ��]�X�s�[�h���w��
				DX_WriteWordData (DeviceID1, 1, 32, 20, 100, &err);

				//�@�T�[�{��ڕW�ʒu(GoalPosition)�܂ňړ�
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
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	TErrorCode err = 0;
	//uint16_t	initialPosition = 2200,goalPosition=3000;

	TDeviceID DeviceID1;

	//uint16_t ShoulderUpPosition=1000,ShoulderDownPosition=2000,ArmExtendPosition=2200,ArmBendPosition=3000;

		//�|�[�g���J����
		DeviceID1 = DX_OpenPort("\\\\.\\COM3", 57143);

		if(DeviceID1){//if���̏����ɂ��ā@http://hmu29.hatenablog.com/entry/2013/08/22/203452
			


			// ���������[�h�ɂ���
			DX_WriteWordData(DeviceID1, 3, 6, 2000, 100, &err);
			DX_WriteWordData(DeviceID1, 3, 8, 3200, 100, &err);
			DX_WriteWordData(DeviceID1, 1, 6, 1267, 100, &err);
			DX_WriteWordData(DeviceID1, 1, 8, 2200, 100, &err);
			// �g���N���ʒu���䃂�[�h�̂��߂Ɏw��
			DX_WriteWordData (DeviceID1, 3, 24, 1, 100, &err);
			DX_WriteWordData (DeviceID1, 1, 24, 1, 100, &err);
			//
			DX_WriteWordData (DeviceID1, 3, 36, 2500, 100, &err);
			DX_WriteWordData (DeviceID1, 1, 36, 1900, 100, &err);
			// ��]�X�s�[�h���w��
			DX_WriteWordData (DeviceID1, 3, 32, 450, 100, &err);
			DX_WriteWordData (DeviceID1, 1, 32, 450, 100, &err);
			//�@�T�[�{��ڕW�ʒu(GoalPosition)�܂ňړ�
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
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	TErrorCode err = 0;
	//uint16_t	initialPosition = 2200,goalPosition=3000;

	TDeviceID DeviceID1;

	//uint16_t ShoulderUpPosition=1000,ShoulderDownPosition=2000,ArmExtendPosition=2200,ArmBendPosition=3000;

		//�|�[�g���J����
		DeviceID1 = DX_OpenPort("\\\\.\\COM3", 1000000);

		if(DeviceID1){//if���̏����ɂ��ā@http://hmu29.hatenablog.com/entry/2013/08/22/203452
			


			// ���������[�h�ɂ���
			DX_WriteWordData(DeviceID1, 1, 6, 0, 100, &err);
			DX_WriteWordData(DeviceID1, 1, 8, 4095, 100, &err);
			// �g���N���ʒu���䃂�[�h�̂��߂Ɏw��
			DX_WriteWordData (DeviceID1, 1, 24, 1, 100, &err);
			//���݂̊p�x
			uint16_t n;
			DX_ReadWordData(DeviceID1,1,36,&n,100,&err);
			//�@�T�[�{��ڕW�ʒu(GoalPosition)�܂ňړ��i���̏�j
			DX_WriteWordData (DeviceID1, 1, 30, n, 100, &err);


			//�g���N�����l
			DX_WriteWordData(DeviceID1, 2, 14, 800, 100, &err);
			// ���������[�h�ɂ���
			DX_WriteWordData(DeviceID1, 2, 6, 0, 100, &err);
			DX_WriteWordData(DeviceID1, 2, 8, 4095, 100, &err);
			// �g���N���ʒu���䃂�[�h�̂��߂Ɏw��
			DX_WriteWordData (DeviceID1, 2, 24, 1, 100, &err);
			//���݂̊p�x
			uint16_t m;
			DX_ReadWordData(DeviceID1,2,36,&m,100,&err);
			//�@�T�[�{��ڕW�ʒu(GoalPosition)�܂ňړ��i���̏�j
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
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	TErrorCode err = 0;
	//uint16_t	initialPosition = 2200,goalPosition=3000;

	TDeviceID DeviceID1;

	//uint16_t ShoulderUpPosition=1000,ShoulderDownPosition=2000,ArmExtendPosition=2200,ArmBendPosition=3000;

		//�|�[�g���J����
		DeviceID1 = DX_OpenPort("\\\\.\\COM3", 1000000);

		if(DeviceID1){//if���̏����ɂ��ā@http://hmu29.hatenablog.com/entry/2013/08/22/203452
			

			//�g���N�����l
			DX_WriteWordData(DeviceID1, 2, 14, 800, 100, &err);
			// ���������[�h�ɂ���
			DX_WriteWordData(DeviceID1, 2, 6, 0, 100, &err);
			DX_WriteWordData(DeviceID1, 2, 8, 4095, 100, &err);
			// �g���N���ʒu���䃂�[�h�̂��߂Ɏw��
			DX_WriteWordData (DeviceID1, 2, 24, 1, 100, &err);

			// ��]�X�s�[�h���w��
			DX_WriteWordData (DeviceID1, 2, 32, 20, 100, &err);
			//�@�T�[�{��ڕW�ʒu(GoalPosition)�܂ňړ�
			DX_WriteWordData (DeviceID1, 2, 30, 950, 100, &err);//2000
		}else{
			DX_ClosePort(DeviceID1);
			exit(0);
		}

		DX_ClosePort(DeviceID1);

}



