#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;

const int MAXINT = 0x7fffffff;
const int MAXTIMES = 4e7; 

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

clock_t my_clock(){return clock();}
clock_t c_s, c_e;

int main(){
    vi v;
    int l = 0, r = MAXINT, *a, *b;

    a = new int[MAXTIMES];
    b = new int[MAXTIMES];
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    c_s = my_clock();
    for(int i = 0; i < MAXTIMES; ++i) 
        a[i] = uniform_int_distribution<int>(l, r)(rng);
    c_e = my_clock();
    cout << "init time : " << c_e - c_s << endl;

    c_s = my_clock();
    for(int i = 0; i < MAXTIMES; ++i)
        b[i] = a[i];
    c_e = my_clock();
    cout << "test #1: " << c_e - c_s << endl;

    c_s = my_clock();
    for(int i = 0; i < MAXTIMES; ++i)
        v.push_back(a[i]);
    c_e = my_clock();
    cout << "test #2: " << c_e - c_s << endl;

    delete []a;
    delete []b;

    exit(0);
}
