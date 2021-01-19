#include <iostream>
#include <string>
#include "err_out.h"
#include "constant.h"
using namespace std;

void overflow(string& str, int CityNum) {
    cerr << str << " : " << "overflow." << endl;
    cerr << "Now city number is : " << CityNum << " , while limit is " << MaxCityNum << endl;
    exit(1);
}
void time_overflow(string& str, Time& t) {
    Time Ltime; Ltime.SetLarge();
    cerr << str << " : " << "timeflow." << endl;
    cerr << "Input time is: ";
    t.FormatShow();
    cerr << " , while limit is: ";
    Ltime.FormatShow();
    cerr << endl;
    exit(1);
}
void time_logical_error(string& str, Time& tA, Time& tB) {
    cerr << str << " : " << "time logical error." << endl;
    cerr << "First time you input :"; tA.FormatShow(2);
    cerr << "Then you input : "; tB.FormatShow(2);
    exit(1);
}
void input_format(string& str, string errorCH, string expectedCH) {
    cerr << str << " : " << "input_format_error." << endl;
    cerr << "detected " << "'" << errorCH << "' in input, while expects " << "'" << expectedCH << "'" << endl;
    exit(1);
}
void arg_error(string& str, int w_arg) {
    cerr << str << " : " << "inout_arg_error." << endl;
    cerr << "arg input: " << w_arg << endl;
    exit(1);
}
