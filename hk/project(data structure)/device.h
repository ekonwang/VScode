#ifndef _DEVICE_H_
#define _DEVICE_H_
#include "constant.h"
#include <vector>
#include <string>
#include <map>
#include <iomanip>    //ios::setiosflags
#include <iostream>   //std cin,cout
#include <string>     //std string
#include <string.h>   //memset
#include <map>        //std map
#include <fstream>    //file read &write
#include <stdlib.h>   //exit

class FlightTrain;
class City;
class Graph;

class Time {
    friend FlightTrain;
    friend City;
    friend Graph;
private:
    int year;
    int month, date, hour, min;
    Time(int y, int m, int d, int h, int minute, int arg);
public:
    Time();
    Time(int m, int d, int h, int minute, int y = 2020);
    ~Time();
    void SetLarge();
    void Set(Time& t);
    bool set(int m, int d, int y, int h, int minute);
    void FormatShow(int arg = 0) const;          //output with '\t' when argument == 1, and output with '\n' when arg == 2.
    bool cmpg(Time& t) const;                    //比较时间是否更小
    bool cmpl(Time& t) const;                    //比较时间是否更大
    bool cmpe(Time& t) const;
};

class FlightTrain {
    friend City;
    friend Graph;
private:
    int from_station, dest_station, price;
    Time depart, arrive;
    FlightTrain* link;
public:
    FlightTrain(int p, Time& tA, Time& tB, int argA = 0, int argB = 0);
    ~FlightTrain();
    void show_info(int from, int dest);
};

class City {
    friend Graph;
private:
    std::string cityName;
    FlightTrain* info[2][MaxCityNum + 1];
    int FlightAdjNum, TrainAdjNum;
    City(std::string NameStr);
    ~City();
public:
    void deleteRe(FlightTrain* ptr);
    bool Delete(int CityID, Time& tA, Time& tB, int arg = 0);
    bool insert(int CityID, Time& tA, Time& tB, int Price, int arg = 0);
    int Show_info(int arg = 0);
};
class Graph {
private:
    City* CityTable[MaxCityNum + 1];
    int V[2][MaxCityNum + 1];                                    // Array that stores ancesters or Visited nodes.
    int C[2][MaxCityNum + 1];                                    // Array that stores Path for finding Cpath.
    int R[2][MaxCityNum + 1];                                    // Array that stores result of CPath.
    Time VPath[2][MaxCityNum + 1];                               // An array used in searching FASTEST & CHEAPEST path.储存航班次选择的数组
    Time Cpath[2][MaxCityNum + 1];                               // An array used in searching CHEAPEST path.
    int CityNum;                                                 // current number of cities.
    int Cheapest[2];
    void CPath(int from, int dest, Time departureTime, int arg); // 该函数选择一条最快的线路，并将结果储存在 VPath, V 中
    void CPath_helper(int dest, int cur, Time& CurTime, int arg);// 一个优化的递归算法，用于找到Cheapest Path，是CPath的辅助函数.
    void FPath(int from, int dest, Time departureTime, int arg); // 该函数选择一条最快的线路，并将结果储存至 VPath, V 中
    bool Load(int arg = 0);                                      // 用于加载数据，函数内部有对于数据文件严格的输入格式检验
public:
    Graph();
    ~Graph();
    bool Load_file();
    bool Insert();                                                  // 插入数据
    bool Delete();                                                  // 删除数据
    void ProperPath(int from, int dest, Time &departureTime, int arg, int tag);// The function shows Proper choices. Either Fastest or Cheapest.
    bool ShowCityInfo(int CityID);                                  // 显示该城市所有作为始发站的飞机火车信息
    int GetCityNum();                                               // Show Current city number.
    int GetID(std::string &NameStr);                                // 返回城市ID
    std::string GetName(int CityID);                                // 返回城市名字
};

#endif //_DEVICE_H_