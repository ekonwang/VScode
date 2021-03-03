#include <bits/stdc++.h>
using namespace std;

#define il inline
#define For(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

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
}

const LL N = 1000010;

/////////////////////////////////////////////////////////////////////////////////////////
// greedy algorithm.
// greedy doesn't work.

// il void solve() {
//     cin >> n >> m;
//     vector<vector<LL>> arr(n, vector<LL>(m, 0));
//     vector<LL> ctr(n, 0);
//     vector<LL> res;
//     For(i, 0, n-1) cin >> arr[i];
//     For(j, 0, m-1){
//         LL tmp = 0, elem;
//         set<LL> maxs;
//         multiset<LL> Maxs;
//         auto max_ctr = *max_element(all(ctr));
        
//         if(max_ctr > 2) break;

//         For(i, 0, n-1) if(ctr[i] == max_ctr) maxs.insert(arr[i][j]);
//         For(i, 0, n-1) if(maxs.count(arr[i][j]) != 0) Maxs.insert(arr[i][j]);
//         for(multiset<LL>::iterator iter = Maxs.begin(); iter != Maxs.end(); iter++){
//             tmp = max(tmp, (LL)Maxs.count(*iter));
//         }
//         for(multiset<LL>::iterator iter = Maxs.begin(); iter != Maxs.end(); iter++){
//             if((LL)Maxs.count(*iter) == tmp) {elem = *iter; break;}
//         }
//         res.push_back(elem);
//         For(i, 0, n-1){
//             if(arr[i][j] != elem) ctr[i]++; 
//         }
//     }

//     if(res.size() == m) {
//         cout << "Yes" << endl;
//         for(auto ele: res) cout << ele << " ";
//         cout << endl;
//     }else cout << "No" << endl;
// }
LL n, m;
vector<vector<LL>> arr(n, vector<LL>(m, 0));
vector<LL> mod;
set<LL> choice;

il vector<LL> count(){
    
    // update
    vector<LL> ctr(n, 0);
    For(i, 1, n-1) {

        ctr[i] = 0;
        For(j, 0, m-1)

            if(arr[i][j] != arr[0][j]) ctr[i]++;
    }

    return ctr;

}

il bool rec(int used = 0){


    vector<LL> ctr = count();
    LL max = *max_element( all(ctr) );

    if(max <= 2) {
        
        return true;

    }
    
    if(used == 2) 

        return false;

    else if(used == 1){

        if (max > 3) 

            return false;
        
        else {

            For(i, 1, n-1) if(ctr[i] == 3) {

                

            }

        }

    }else {



    }
    

}

il void solve(){
    
    For(i, 0, n-1) cin >> arr[i];
    for(auto elem: arr[0]) mod.push_back(elem); 

    count();
    LL max = *max_element( all(ctr) );
    
    if(max <= 2) {

        cout << "Yes" << endl;
        for(auto elem: arr[0]) cout << elem << " ";
        cout << endl;

    }
    else if(max >= 5) {

        cout << "No" << endl;

    }
    else {

        rec();

    }

}

int main() {

    ios::sync_with_stdio(0);
    solve();
    return 0;

}