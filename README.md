# Random-Rollcall-System-RRS
本项目成功开发了一个基于MFC的随机点名系统，实现了学生信息的灵活管理，包括从文件导入和手动新建功能；通过随机算法实现了公平的随机点名功能，并支持多次点名；能够详细记录学生的出勤情况，如按时到课、请假和缺勤，并自动统计请假次数和缺勤次数；还支持将点名记录保存到.txt和.dat文件中，方便后续查询和分析。系统采用MFC框架开发，界面友好，布局合理，操作便捷，响应迅速，能够处理大量数据且稳定性良好。
This project has successfully developed a random roll-call system based on MFC. It has realized the flexible management of student information, including importing from files and manual creation. Through random algorithms, the system has achieved a fair random roll-call function and supports multiple roll-calls. It can also record students' attendance status in detail, such as being on time, asking for leave, and being absent, and automatically count the number of times students ask for leave and are absent. Moreover, the system can save the roll-call records to .txt and .dat files for convenient subsequent queries and analysis. Developed with the MFC framework, the system has a friendly interface, rational layout, convenient operation, quick response, and good stability in handling large amounts of data.
使用方法：
  启动系统：双击可执行文件，进入主界面。
  导入学生信息：点击“导入数据”按钮，选择“从文件导入”可加载.dat文件中的学生信息，选择“新建数据”则手动输入学生姓名并添加到列表中。
  随机点名：点击“随机点名”按钮，系统从学生列表中随机抽取一名学生，并在列表框中显示其姓名，可多次点击进行多次点名。
  记录出勤情况：点名后点击“记录点名情况”按钮，弹出对话框选择出勤状态（按时到课、请假或缺勤），点击“确定”完成记录。
  保存和读取记录：点击“保存数据”按钮，将点名记录保存为.txt和.dat文件；点击“读取点名列表”按钮，选择.dat文件即可查看历史记录。
Usage:
Launch the System: Double-click the executable file to enter the main interface.
Import Student Information: Click the "Import Data" button. Select "Import from File" to load student information from a .dat file, or choose "New Data" to manually enter student names and add them to the list.
Random Roll Call: Click the "Random Roll Call" button. The system will randomly select a student from the list and display their name in the list box. You can click this button multiple times for multiple roll calls.
Record Attendance: After a roll call, click the "Record Roll Call" button. A dialog box will pop up for you to select the attendance status (on time, leave, or absent). Click "OK" to complete the record.
Save and Retrieve Records: Click the "Save Data" button to save the roll-call records as .txt and .dat files. To view historical records, click the "Read Roll Call List" button and select a .dat file.
