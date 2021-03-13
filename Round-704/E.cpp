#include <bits/stdc++.h>
using namespace std;

/* #define il inline
#define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)
#define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)
#define all(x) = (x).begin(),(x).end()
#define rall(x) = (x).rbegin(),(x).rend()

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

template<class T> ostream &operator << (ostream& out, const vector<T>& arr) {
    cout << "{"; for (int i = 0; i < arr.size(); i++)cout << (!i ? "" : ", ") << arr[i]; cout << "}";
    return out;
}
template<class T> ostream &operator << (ostream& out, const vector<vector<T> >& arr) {
    cout << "{\n"; for (auto& vec : arr)cout << "  " << vec << ",\n"; cout << "}";
    return out;
}
template<class S,class T> ostream &operator << (ostream& out, const pair<S,T>& p){
    cout << "{" << p.first << "," << p.second << "}" << '\n';
    return out;
}
template<class T> istream &operator >> (istream& in, vector<T>& arr) {
    for (auto& i : arr)cin >> i; return in;
}
template<class S,class T> istream &operator >> (istream& in,pair<S,T>& p){
    cin >> p.first >> p.second; return in;
} */
/* 
const LL N = 501, M = 501;
LL a[N][M], r[N][M], t, n, m;
char s[N][N];
string str;

il void qwq0(){
    memset(r, 0, sizeof(r));
    LL tp = m/3;
    // FOR(i, 0, tp-1) {
    //     FOR(j, 1, m-2) {
    //         r[3*i+2][j] = 1;
    //         r[3*i+1][j] = a[3*i+1][j];
    //         r[3*i+3][j] = a[3*i+3][j];
    //     }
    //     r[3*i+2][m-1] = 1;
    // }
    FOR(i, 0, tp-1) {
        FOR(j, 1, n-2) {
            r[j][3*i+2] = 1;
            r[j][3*i+1] = a[j][3*i+1];
            r[j][3*i+3] = a[j][3*i+3];
        }
        r[n-1][3*i+2] = r[n][3*i+2]= 1;
    }

    if(a[n-1][1]) r[n-1][1] = 1;
    else if(a[n][1]) r[n][1] = 1;
    if(a[n-1][m]) r[n-1][m] = 1;
    else if(a[n][m]) r[n][m] = 1;

    FOR(i, 1, tp-1) {
        if(a[n-1][3*i] || a[n-1][3*i+1]) r[n-1][3*i] = r[n-1][3*i+1] = 1;
        else r[n][3*i] = r[n][3*i+1] = 1;
    }
}
il void qwq1(){
    memset(r, 0, sizeof(r));
    LL tp = m/3;

    FOR(i, 0, tp-1) {
        FOR(j, 1, n-2) {
            r[j][3*i+2] = 1;
            r[j][3*i+1] = a[j][3*i+1];
            if(i != tp-1)
            r[j][3*i+3] = a[j][3*i+3];
            else {
                if(a[j][3*i+3] || a[j][3*i+4]) r[j][3*i+3] = r[j][3*i+4] = 1;
            }
        }
        r[n-1][3*i+2] = r[n][3*i+2]= 1;
    }

    if(a[n-1][1]) r[n-1][1] = 1;
    else if(a[n][1]) r[n][1] = 1;
    if(a[n-1][m-1] || a[n-1][m]) r[n-1][m-1] = r[n-1][m] = 1;
    else r[n][m-1] = r[n][m] = 1;

    FOR(i, 1, tp-1) {
        if(a[n-1][3*i] || a[n-1][3*i+1]) r[n-1][3*i] = r[n-1][3*i+1] = 1;
        else r[n][3*i] = r[n][3*i+1] = 1;
    }
}
il void qwq2(){
    memset(r, 0, sizeof(r));
    LL tp = m/3 + 1;

    FOR(i, 0, tp-1) {
        FOR(j, 1, n-2) {
            r[j][3*i+2] = 1;
            r[j][3*i+1] = a[j][3*i+1];            /* so many unnecessary multiply operation. */
           /*  if(i != tp-1)
            r[j][3*i+3] = a[j][3*i+3];
        }
        r[n-1][3*i+2] = r[n][3*i+2]= 1;
    }

    if(a[n-1][1]) r[n-1][1] = 1;
    else if(a[n][1]) r[n][1] = 1;

    FOR(i, 1, tp-1) {
        if(a[n-1][3*i] || a[n-1][3*i+1]) r[n-1][3*i] = r[n-1][3*i+1] = 1;
        else r[n][3*i] = r[n][3*i+1] = 1;
    }
}

il void solve() {
    char ch;
    cin >> t;
    while(t--) {
        // cin >> n >> m;
        // FOR(i, 1, n){
        //     FOR(j, 1, m) {
        //         cin >> ch;
        //         if(ch == '.') a[i][j] = 0;
        //         else a[i][j] = 1;
        //         if(j == m) cin >> ch;
        //     }
        // }
        cin >> n >> m;
        memset(a, 0, sizeof(a));                  /* using of memset of a */
/* 		for (int i=1;i<=n;i++)scanf("%s",s[i]+1);
        FOR(i, 1, n) FOR(j, 1, m) if(s[i][j] == 'X') a[i][j] = 1;

        if(n == 1) {
            FOR(i, 1, m) printf("X"); printf("\n");
            continue;
        }
        if(m == 1) {                             /* code that lack of locality */
/*             FOR(i, 1, n) printf("X\n");
            continue;                              
        }
        if(m % 3 == 0) {qwq0();}
        else if (m % 3 == 2) { qwq2(); }
        else if(m % 3 == 1) {qwq1(); }

        FOR(i, 1, n) FOR(j, 1, m) {
            if(r[i][j]) printf("X");                  
            else printf(".");
            if(j == m) printf("\n");
        }
    }
}
// right algorithm...but of so low efficiency. so sad.
int main() {
    solve();
    return 0;
} 
*/ 
/* reference code. */

const int N=505;
char s[N][N];
int n,m,T;
int main(){
    ios::sync_with_stdio(0);
	cin>>T;
	while (T--){
        string str[N];
		cin>>n>>m;
		for (int i=1;i<=n;i++) cin >> str[i]; 
		for (int i=1;i<=n;i++)
			if (i%3==1){
				for (int j=0;j<m;j++)str[i][j]='X';
			}
			else if (i%3==0){
				int flag=0;
				for (int j=0;j<m;j++)
					if (str[i][j]=='X'){
						str[i-1][j]='X';
						flag=1;
						break;
					}
				if (!flag){
					for (int j=0;j<m;j++)
						if (str[i-1][j]=='X'){
							str[i][j]='X';
							flag=1;
							break;
						}
					if (!flag)str[i][0]=str[i-1][0]='X';
				}
			}
		if (n%3==0)for (int j=0;j<m;j++)
			if (str[n][j]=='X')str[n-1][j]='X';
		for (int i=1;i<=n;i++) cout << str[i] << endl;
	}
}
// C++ 的STL库使用相比较c并没有明显的性能下降，可以完全不用回避；
// 对于算法的优化应该从算法本身入手