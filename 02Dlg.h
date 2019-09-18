
// 02Dlg.h : 头文件
//
#include "f:\chartdemo\chartctrl\chartctrl.h"
#include "f:\chartdemo\chartctrl\charttitle.h"
#include "f:\chartdemo\chartctrl\ChartLineSerie.h"
#include "f:\chartdemo\chartctrl\ChartMouseListener.h"
#pragma once


// CMy02Dlg 对话框
class CMy02Dlg : public CDialogEx
{
// 构造
public:
	CMy02Dlg(CWnd* pParent = NULL);	// 标准构造函数

	CChartCtrl m_ChartCtrl1;
	CChartCtrl m_ChartCtrl2; 
	CChartCtrl m_ChartCtrl3; 
	CChartCtrl m_ChartCtrl4; 
	CChartCtrl m_ChartCtrl5; 
	CChartCtrl m_ChartCtrl6; 
	CChartCtrl m_ChartCtrl7; 
	
// 对话框数据
	enum { IDD = IDD_MY02_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDrawing();
};
