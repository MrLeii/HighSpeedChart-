#include "f:\chartdemo\chartctrl\chartctrl.h"
#include "f:\chartdemo\chartctrl\charttitle.h"
#include "f:\chartdemo\chartctrl\ChartLineSerie.h"
// drawtestDlg.h : ͷ�ļ�
//

#pragma once


// CdrawtestDlg �Ի���
class CdrawtestDlg : public CDialogEx
{
// ����
public:
	CdrawtestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DRAWTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CChartCtrl m_chartctrl;
	afx_msg void OnBnClickedButton1();
};
