#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> get_ip_address_helper(string str, int n);
vector<string> get_ip_address(string s) { return get_ip_address_helper(s, 4); }
vector<string> get_ip_address_helper(string str, int n) {
    vector<string> res;
    if (n == 1) {
        if (stoi(str) <= 255) {
            res.push_back(str);
        };
        return res;
    } else {
        int min_length =
            str.length() - (n - 1) * 3 > 1 ? str.length() - (n - 1) * 3 : 1;
        int max_length =
            str.length() - (n - 1) < 3 ? str.length() - (n - 1) : 3;
        for (int i = min_length; i <= max_length; i++) {
            string current = str.substr(0, i);
            auto temp = get_ip_address_helper(str.substr(i), n - 1);
            if (temp.size() == 0) {
                continue;
            } else if (stoi(current) > 255) {
                continue;
            }
            for (string s : temp) {
                res.push_back(current + '.' + s);
            }
        }
        return res;
    }
}
void test_get_ip_address() {
    string ip1 = "25525512211";
    for (string s : get_ip_address(ip1)) {
        cout << s << endl;
    }
    string ip2 = "2222222222";
    for (string s : get_ip_address(ip2)) {
        cout << s << endl;
    }
}
int main() { test_get_ip_address(); system("pause"); return 0;}