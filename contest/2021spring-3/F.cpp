#include <bits/stdc++.h>                                                     //*
#define il inline                                                            //*
#define ll long long                                                         //*
#define INT __int64                                                          //*
#define usn unsigned                                                         //*
#define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)              //*
#define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)              //*
ll const MAXLL = 0x7fffffffffffffffLL;                                       //*
int const MAXINT = 0x7fffffff;                                               //*
const int INF = 0x3f3f3f3f;                                                  //*
const double E = exp(1.0);                                                   //*
const double PI = acos(-1.0);                                                //*
ll gcd(ll a,ll b){while(b^=a^=b^=a%=b);return a;}                            //*
ll lcd(ll a , ll b){return a * b / gcd(a,b);}                                //*
inline void write(ll x)                                                      //*
{                                                                            //*
    if(x<0) {                                                                //*
        putchar('-');                                                        //*
        x = -x;                                                              //*
    }                                                                        //*
    if(x>9) write(x / 10);                                                   //*
    putchar(x % 10 + '0');                                                   //*
}                                                                            //*
void init_cin(){                                                             //*
  std::ios::sync_with_stdio(false);                                          //*
  std::cin.tie(nullptr);                                                     //*
  std::cout.tie(nullptr);                                                    //*
}                                                                            //*
using namespace std;                                                         //*

int cmp(pair<int,int>a,pair<int,int>b){
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}
//---------------------------------------------------------------------------//*

/* 
divide and conquer
dp
math

so not a easy stuff 

the conclusion is that k is always 2's power
*/

/* const int N = 100000 + 5;
int a[N], b[N], h1, h2, n, m, tp[N << 1];

int help(int r1, int r2) {
    int p = 0;
    FOR(i, 1, n) {
        if(a[i] % 4 == r1) tp[++p] = a[i];
    }
    FOR(i, 1, m) {
        if(b[i] % 4 == r2) tp[++p] = b[i];
    }
    sort(tp + 1, tp + p + 1);
    return unique(tp + 1, tp + p + 1) - tp - 1;
}

// 使用unique常犯的错误： 当起始位置为1时应该将 返回值减去tp + 1而非tp

void solve() {
    //r1 : all odd
    //r2 : all even
    //r3 : up odd down even
    //r4 : up even down odd
    int res = 0, r1 = 0, r2 = 0, r3 = 0, r4 = 0;
    cin >> n >> h1;
    FOR(i, 1, n) cin >> a[i];
    cin >> m >> h2;
    FOR(i, 1, m) cin >> b[i];

    FOR(i, 1, n) {
        if(a[i] % 2) r4 ++;
        else r3 ++;
    }
    FOR(i, 1, m) {
        if(b[i] % 2) r3++;
        else r4++;
    }

    r1 = max(help(1, 3) , help(3, 1)); 
    r2 = max(help(0, 2), help(2, 0));

    res = max(max(max(max(res, r1), r2), r3), r4);

    cout << res << endl;
} */

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)


const int N = 100 * 1000 + 555;

int n[2], y[2];
int x[2][N];

inline bool read() {
	fore(k, 0, 2) {
		if(!(cin >> n[k] >> y[k]))
			return false;
		fore(i, 0, n[k])
			assert(scanf("%d", &x[k][i]) == 1);
            //这里的断言很有意思，它解决了什么问题？
	}
	return true;
}

inline void solve() {
	int ans = 2;
	for(int dx = 1; dx < int(1e9); dx *= 2) {
		int mod = 2 * dx;
		map<int, int> cnt;
		
		int add[2] = {0, dx};
		fore(k, 0, 2) {
			fore(i, 0, n[k])
				cnt[(x[k][i] + add[k]) & (mod - 1)]++;
		}
        //完美地解决了我的问题：
        //使用map储存结果，而不用枚举情况，做到了O(nlogn的复杂度)
        //使用位与运算而非求余运算，这是一个重要的优化
        //数组储存在一个二维数组中，巧妙的书写提高了代码复用度
        //非常值得学习
		
		for(auto curAns : cnt)
			ans = max(ans, curAns.second);
	}
	cout << ans << endl;
}


int main() {
    if(read()){
        solve();
    }
    
    return 0;
}