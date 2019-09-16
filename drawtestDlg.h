#include "f:\chartdemo\chartctrl\chartctrl.h"
#include "f:\chartdemo\chartctrl\charttitle.h"
#include "f:\chartdemo\chartctrl\ChartLineSerie.h"
// drawtestDlg.h : 头文件
//

#pragma once


// CdrawtestDlg 对话框
class CdrawtestDlg : public CDialogEx
{
// 构造
public:
	CdrawtestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DRAWTEST_DIALOG };

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
	CChartCtrl m_chartctrl;
	afx_msg void OnBnClickedButton1();
};
