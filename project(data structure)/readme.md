#The App based on 3 header files(constant.h, device.h and err_out.h)
#and 3 src files(device.cpp, err_out.cpp and console.cpp)

Compiling environment：
此程序经实测在Visual Studio 2019 C++ 环境下能够编译运行，但在运行前需要修改 device.cpp 文件中Load函数输入文件的路径，
以适配当前计算机中 Flight.txt 以及 Train.txt 文件的具体路径，否则将出现程序不能正常读取文件中航班信息的情况.
此外一些IDE不能够适配VS2019的中文环境，注释及输出显示为乱码，此种情况用VS2019打开即可解决

Abstract：
device.h : 声明了程序的全部用到的class及其接口，定义了程序的总体架构
device.cpp : device.h的实现文件，定义了全部的接口，涵盖主要算法
err_out.h : 声明了程序中的几个错误类型函数的接口
err_out.cpp : err_out.h 的实现文件
constant.h : 定义常数宏
console.cpp : 定义了用户与程序进行交互的 main 函数，并对常见的异常情况进行了处理
