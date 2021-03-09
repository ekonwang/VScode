#include<set>
#include<vector>
#include<iostream>
using namespace std;
vector<set<int>*> T;
set<int>* operator+(const set<int> &s1, const set<int> &s2 ){
    set<int>* s3;
    set<int>::iterator iter;
    for(iter = s1.begin(); iter != s1.end(); iter ++) s3 -> insert(*iter);
    for(iter = s2.begin(); iter != s2.end(); iter ++) s3 -> insert(*iter);
    return s3;
}
void read(int m){
    int p1, p2, flag, f1, f2;
    set<int>* s, *s2;
    for(int i = 0; i < m; i++){
        f1 = f2 = -1;
        cin >> p1 >> p2;
        for(int j = 0; j < T.size(); j++){
            s = T[j];
            if(s -> count(p1)) f1 = j;
            if(s -> count(p2)) f2 = j;
            if(f1 > 0 && f2 > 0) break;
        }
        if(f1 >= 0 && f2 == -1){
            s = T[f1];
            s -> insert(p2);
        }else if(f2 >= 0 && f1 == -1){
            s = T[f2];
            s -> insert(p1);
        }else if(f1 == -1 && f2 == -1){
            s = new set<int>;
            T.push_back(s);
            s -> insert(p1); s -> insert(p2);
        }else{
            s = T[f1];
            s2 = T[f2];
            s = *s + *s2; 
            T.erase(T.begin() + f2);
        }
    }
    set<int>:: iterator iter;
    cout << T.size() << endl;
    /* for(set<int>* t :T){
        for(iter = t -> begin(); iter != t -> end(); iter++) cout << *iter << '\t';
        cout << endl;
    } */
}
void verify(int p){
    set<int> *s;
    int v[p];
    int size = T.size(), p1, p2, flag;
    for(int i = 0; i < p; i++){
        cin >> p1 >> p2;
        flag = 0;
        for(int j = 0; j < size; j++){
            s = T[j];
            if(s -> count(p1) && s -> count(p2)){
                flag ++;
                v[i] = 1;
                break;
            }
        }
        if(!flag) v[i] = 0;
    }
    for(int k = 0; k < p; k++){
        if(v[k]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
int main(){
    int n, m, p;
    cin >> n >> m >> p;
    read(m);
    verify(p);
    system("pause");
    return 0;
}
//log1 (read)s not push_back into T's back.
//log2 (verify) output instantly.
//log3 (read)set construction bug.
//log4 (read)'=' overload bug.