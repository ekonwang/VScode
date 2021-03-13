#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
map<string, int> m, mn;
string s[maxn];
int v[maxn], r = -1001;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> v[i];
        m[s[i]] += v[i];
    }
    for(int i = 0; i < n; i++) r = m[s[i]] > r? m[s[i]] : r;
    for(int i = 0; i < n; i++){
        mn[s[i]] += v[i];
        if(m[s[i]] == r&& mn[s[i]] >= r) {
            cout << s[i] << endl;
            break;
        }
    }
    /* map<string, int> :: reverse_iterator iter;
    for(iter = m.rbegin(); iter != m.rend(); iter++)
        cout << iter -> first << " " << iter -> second << endl ; 
    cin >> r; */
    return 0;
}
//log1 忘记给participate 加上名字
//log2 情况二输出错误
//log3 exception recurred.
//log4 vector储放指针正常运行
//log5 忽略一些选手开始得分很高，但最后得分变得不再领先的情况，对题目的理解不深刻




/* struct participate{
    string name;
    int score = -1000;
};
vector<participate*> ps;
int find(string str){
    for(int i = 0; i < ps.size(); i++){
        if (ps[i] -> name == str) return i;
    }
    return -1;
}
int main(){
    int n, value, pos; 
    string str;
    participate *wr = new participate, *cur = wr;
    cin >> n;
    for(int j = 0; j < n ; j++){
        cin >> str >> value;
        if ((pos = find(str)) == -1){
            cur = new participate;
            cur -> name = str;
            cur -> score = value;
            ps.push_back(cur);
        }else{
            cur = ps[pos];
            cur -> score += value;
        }
        if (cur -> score > wr -> score) {
            wr = cur;
        }
    }
    cout << wr -> name;
    system("pause");
    return 0;
} */