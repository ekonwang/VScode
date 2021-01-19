#include "bits/stdcpp.h"
using namespace std;

typedef long long ll;
ll hashTableA[26] = {1, 16, 256, 4096, 65536, 1048576, 16777216, 268435456, 4294967296, 68719473736, 1099511627776, 17592186044416, 281474976710656, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
ll hashTableB[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 16, 256, 4096, 65536, 1048576, 16777216, 268435456, 4294967296, 68719473736, 1099511627776, 17592186044416, 281474976710656};

ll HashA(string str){
    ll res = 0;
    for(int i = 0; i < str.size(); i++) res += hashTableA[str[i] - 'a'];
    return res;
}
ll HashB(string str){
    ll res = 0;
    for(int i = 0; i < str.size(); i++) res += hashTableB[str[i] - 'a'];
    return res;
}
vector<int> stringAnagram(vector<string> dictionary, vector<string> query) {
    int i, n = query.size(), m = dictionary.size();
    vector<int> res(n);
    vector<ll> hashA(n), hashB(n);
    //dual hash(str)
    for(int i = 0; i < n; i++){
        res[i] = 0;
        hashA[i] = HashA(query[i]);
        hashB[i] = HashB(query[i]);
    }
    for(int j = 0; j < m; ++j){
        ll ha = HashA(dictionary[j]);
        ll hb = HashB(dictionary[j]);
        for(int k = 0; k < n; ++k){
            if(ha == hashA[k] && hb == hashB[k]) res[k]++;
        }
    }
    return res;
}
void transfer(vector <string> &vec, string a[], int n){
    for(int i = 0; i < n; i++) vec[i] = a[i];
}
int main()
{
    string strA[5] = {"heater", "cold", "clod", "reheat", "docl"};
    string strB[3] = {"codl", "heater", "abcd"};
    vector <int> res;
    vector <string> dic(5);
    vector <string> qr(3);
    transfer(dic, strA, 5);
    transfer(qr, strB, 3);
    res = stringAnagram(dic, qr);
    for(int elem: res) cout << elem << '\t';
    system("pause");
    return 0;
}
