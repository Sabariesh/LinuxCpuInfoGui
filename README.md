# LinuxCpuInfoGui
==================

CPUInfoGui is a gui tool to display the CPU information content in the linux system that can be found in /proc/cpuinfo.

The application is built in C++ with Qt(QtQuick).


The application on launch shows the basic information of the processor, through the tab view any needed processor information can be seen.

<img src="https://raw.githubusercontent.com/Sabariesh/LinuxCpuInfoGui/master/WebGuiImg/CpuInfo.png"/>


On clicking "Detailed Info" button more detailed information of the selected processor is displayed.

<img src="https://raw.githubusercontent.com/Sabariesh/LinuxCpuInfoGui/master/WebGuiImg/CpuDetailedInfo.png"/>



Requirement:
------------

- C++ 11
- Qt version minimum: 5.8
- Boost library



Known bug:
----------
- Table view in QtQuick.Controls has the following issue: 
  "QML : Binding loop detected for property "width""
  Bug report can be found here: https://bugreports.qt.io/browse/QTBUG-50605
