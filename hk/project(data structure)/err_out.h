#ifndef _ERR_OUT_H_
#define _ERR_OUT_H_
#include <string>
#include "device.h"
#include "constant.h"

void overflow(std::string& str, int CityNum);
void time_overflow(std::string& str, Time& t);
void time_logical_error(std::string& str, Time& tA, Time& tB);
void input_format(std::string& str, std::string errorCH, std::string expectedCH);
void arg_error(std::string& str, int w_arg);

#endif //_ERR_OUT_H_#pragma once
