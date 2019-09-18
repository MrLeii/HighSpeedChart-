
// 02Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "02.h"
#include "02Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMy02Dlg 对话框




CMy02Dlg::CMy02Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy02Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy02Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ChartCtrl1, m_ChartCtrl1); 
}

BEGIN_MESSAGE_MAP(CMy02Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Drawing, &CMy02Dlg::OnBnClickedDrawing)
END_MESSAGE_MAP()


// CMy02Dlg 消息处理程序

BOOL CMy02Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//绘制S21的显示界面
	CRect rect,rectChart;   
	GetDlgItem(IDC_ChartCtrl1)->GetWindowRect(&rect);  
	ScreenToClient(rect);  
	rectChart = rect;  
	rectChart.left = rect.right + 3;  
	rectChart.right = rectChart.left + rect.Width();  
	m_ChartCtrl2.Create(this,rectChart,IDC_ChartCtrl2);  
	m_ChartCtrl2.ShowWindow(SW_SHOWNORMAL);
	//设置S12的显示界面
	CRect rect1,rectChart1;   
	GetDlgItem(IDC_ChartCtrl1)->GetWindowRect(&rect1);  
	ScreenToClient(rect1);  
	rectChart1 = rect1;  
	rectChart1.top = rect1.bottom + 3;  
	rectChart1.bottom = rectChart1.top + rect1.Height();  
	m_ChartCtrl3.Create(this,rectChart1,IDC_ChartCtrl3);  
	m_ChartCtrl3.ShowWindow(SW_SHOWNORMAL);
	//设置S22的显示界面
	CRect rect2,rectChart2;   
	GetDlgItem(IDC_ChartCtrl3)->GetWindowRect(&rect2);  
	ScreenToClient(rect2);  
	rectChart2 = rect2;  
	rectChart2.left = rect2.right + 3;  
	rectChart2.right = rectChart2.left + rect2.Width();  
	m_ChartCtrl4.Create(this,rectChart2,IDC_ChartCtrl4);  
	m_ChartCtrl4.ShowWindow(SW_SHOWNORMAL);

	CChartAxis *pAxis= NULL;   
	pAxis = m_ChartCtrl1.CreateStandardAxis(CChartCtrl::BottomAxis);  
	pAxis->SetAutomatic(true);  
	pAxis = m_ChartCtrl1.CreateStandardAxis(CChartCtrl::LeftAxis);  
	pAxis->SetAutomatic(true);  
   
	pAxis = m_ChartCtrl2.CreateStandardAxis(CChartCtrl::BottomAxis);  
	pAxis->SetAutomatic(true);  
	pAxis = m_ChartCtrl2.CreateStandardAxis(CChartCtrl::LeftAxis);  
	pAxis->SetAutomatic(true);

	pAxis = m_ChartCtrl3.CreateStandardAxis(CChartCtrl::BottomAxis);  
	pAxis->SetAutomatic(true);  
	pAxis = m_ChartCtrl3.CreateStandardAxis(CChartCtrl::LeftAxis);  
	pAxis->SetAutomatic(true);

	pAxis = m_ChartCtrl4.CreateStandardAxis(CChartCtrl::BottomAxis);  
	pAxis->SetAutomatic(true);  
	pAxis = m_ChartCtrl4.CreateStandardAxis(CChartCtrl::LeftAxis);  
	pAxis->SetAutomatic(true);

	TChartString str1;  
	str1 = _T("S11");  
	m_ChartCtrl1.GetTitle()->AddString(str1);  
  
	CString str2(_T(""));  
	str2 = _T("S21");  
	m_ChartCtrl2.GetTitle()->AddString(TChartString(str2)); 

	CString str3(_T(""));  
	str3 = _T("S12");  
	m_ChartCtrl3.GetTitle()->AddString(TChartString(str3));

	CString str4(_T(""));  
	str4 = _T("S22");  
	m_ChartCtrl4.GetTitle()->AddString(TChartString(str4)); 

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy02Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy02Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy02Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy02Dlg::OnBnClickedDrawing()
{
	// TODO: 在此添加控件通知处理程序代码
	double X1Values[404], Y1Values[404], X2Values[404], Y2Values[404], X3Values[404], Y3Values[404], X4Values[404], Y4Values[404];
	double str[404],str2[404],str3[404],str4[404];

	FILE *ferf = fopen("E:\\S11.txt","r");
	for(int j = 0;j<802;j++)
	{
		fscanf(ferf,"%lf,",&str[j]);
	}
	fclose(ferf);

	FILE *f2 = fopen("E:\\S21.txt","r");
	for(int j = 0;j<802;j++)
	{
		fscanf(f2,"%lf,",&str2[j]);
	}
	fclose(f2);

	FILE *f3 = fopen("E:\\S12.txt","r");
	for(int j = 0;j<802;j++)
	{
		fscanf(f3,"%lf,",&str3[j]);
	}
	fclose(f3);

	FILE *f4 = fopen("E:\\S22.txt","r");
	for(int j = 0;j<802;j++)
	{
		fscanf(f4,"%lf,",&str4[j]);
	}
	fclose(f4);

	for (int i = 0; i<401; i++)

	{
		X1Values[i] = i;

		Y1Values[i] = str[i];

		X2Values[i] = i;

		Y2Values[i] = str2[i];

		X3Values[i] = i;

		Y3Values[i] = str3[i];

		X4Values[i] = i;

		Y4Values[i] = str4[i];
	}

	CChartLineSerie *pLineSerie2,*pLineSerie21,*pLineSerie12,*pLineSerie22;

	//S11
	m_ChartCtrl1.SetZoomEnabled(true);

	m_ChartCtrl1.RemoveAllSeries();//先清空

	pLineSerie2 = m_ChartCtrl1.CreateLineSerie();

	pLineSerie2->SetSeriesOrdering(poNoOrdering);//设置为无序

	pLineSerie2->SetPoints(X1Values, Y1Values, 401);
	//S21
	m_ChartCtrl2.SetZoomEnabled(true);

	m_ChartCtrl2.RemoveAllSeries();//先清空

	pLineSerie21 = m_ChartCtrl2.CreateLineSerie();

	pLineSerie21->SetSeriesOrdering(poNoOrdering);//设置为无序

	pLineSerie21->SetPoints(X2Values, Y2Values, 401);
	//S12
	m_ChartCtrl3.SetZoomEnabled(true);

	m_ChartCtrl3.RemoveAllSeries();//先清空

	pLineSerie12 = m_ChartCtrl3.CreateLineSerie();

	pLineSerie12->SetSeriesOrdering(poNoOrdering);//设置为无序

	pLineSerie12->SetPoints(X3Values, Y3Values, 401);

	//S22
	m_ChartCtrl4.EnableRefresh(false);

	m_ChartCtrl4.SetZoomEnabled(true);

	m_ChartCtrl4.RemoveAllSeries();//先清空

	pLineSerie22 = m_ChartCtrl4.CreateLineSerie();

	pLineSerie22->SetSeriesOrdering(poNoOrdering);//设置为无序

	pLineSerie22->SetPoints(X4Values, Y4Values, 401);

	m_ChartCtrl4.EnableRefresh(true);
	

}
