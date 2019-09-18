# HighSpeedChart-
VS2010，C
首先先下载相关的控件文件，下载地址：https://www.codeproject.com/Articles/14075/High-speed-Charting-Control
下载完成后新建mfc项目，导入现有项（文件夹ChartCtrl），导入后在其对话框中添加一个自定义控件（custom control）（修改控件id，style和class）和一个按钮（用于控制自定义功能的实现）
之后在其头文件中导入chartCtrl中即将用到的头文件，再添加自定义控件的变量和按钮变量名，完成后在其资源文件中添加函数映射。并在初始化函数中添加画板的格式。完成后在按钮事件中添加绘图的功能。


如果要实现自动添加控件并实现绘图，则需要首先在对话框中添加一个主控件，将其id设置为1，并设置其变量为m_chartctrl1,为主体。并为其设置风格（具体步骤和上述基本一致）。完成后，在其.h文件中添加其他变量名，来对应相应的子窗体的变量，如m_chartctrl2,m_chartctrl3等，并在source.h文件中添加对应的控件ID，如ID_ChartCtrl2,ID_ChartCtrl3等。设置完成后，在.cpp文件中的初始化代码中添加其他子窗体的坐标轴和绘画风格。同时还要定义其他子窗体的位置。例如将窗体2放置于主窗体的下方，则需要将窗体2的top = m_chartctrl1.bootom+3,bottom = m_chartctrl2.top + m_chartctrl.Height.左右已是如此。这样就绘制出其他子窗体。之后可以按照第一步一样添加按钮及响应事件来实现绘图。
