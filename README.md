# HighSpeedChart-
VS2010，C
首先先下载相关的控件文件，下载地址：https://www.codeproject.com/Articles/14075/High-speed-Charting-Control
下载完成后新建mfc项目，导入现有项（文件夹ChartCtrl），导入后在其对话框中添加一个自定义控件（custom control）和一个按钮（用于控制自定义功能的实现）
之后在其头文件中导入chartCtrl中即将用到的头文件，再添加自定义控件的变量和按钮变量名，完成后在其资源文件中添加函数映射。并在初始化函数中添加画板的格式。完成后在按钮事件中添加绘图的功能。
