
// 02Dlg.h : ͷ�ļ�
//
#include "f:\chartdemo\chartctrl\chartctrl.h"
#include "f:\chartdemo\chartctrl\charttitle.h"
#include "f:\chartdemo\chartctrl\ChartLineSerie.h"
#include "f:\chartdemo\chartctrl\ChartMouseListener.h"
#pragma once


// CMy02Dlg �Ի���
class CMy02Dlg : public CDialogEx
{
// ����
public:
	CMy02Dlg(CWnd* pParent = NULL);	// ��׼���캯��

	CChartCtrl m_ChartCtrl1;
	CChartCtrl m_ChartCtrl2; 
	CChartCtrl m_ChartCtrl3; 
	CChartCtrl m_ChartCtrl4; 
	CChartCtrl m_ChartCtrl5; 
	CChartCtrl m_ChartCtrl6; 
	CChartCtrl m_ChartCtrl7; 
	
// �Ի�������
	enum { IDD = IDD_MY02_DIALOG };

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
	afx_msg void OnBnClickedDrawing();
};
