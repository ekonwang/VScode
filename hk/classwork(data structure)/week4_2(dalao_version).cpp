#include <iostream>
#include <string>
using namespace std;
int decode_str_helper(const string& s, int times, string& res, int idx);
string decode_str(const string& s) {
    string res;
    decode_str_helper(s, 1, res, 0);
    return res;
}
int decode_str_helper(const string& s, int times, string& res, int idx) {
    int i = idx;
    string temp;
    if (i == s.length()) {
        return -1;
    }
    while (s[i] != ']' && i < s.length()) {
        if ('0' <= s[i] && s[i] <= '9') {
            int c_time = 0;
            while (s[i] != '[') {
                c_time *= 10;
                c_time += stoi(string(1, s[i]));
                i++;
            }
            i = decode_str_helper(s, c_time, temp, i + 1);
        } else {
            temp += string(1, s[i]);
            i++;
        }
    }
    for (int i = 0; i < times; i++) {
        res += temp;
    }
    return i + 1;
}
void test_decode_str() {
    string as1("3[a]2[bc]");
    string es1("aaabcbc");
    string as2("3[a2[c]]");
    string es2("accaccacc");
    string as3("2[abc]3[cd]ef");
    string es3("abcabccdcdcdef");
    string as4("abc3[cd]xyz");
    string es4("abccdcdcdxyz");
    if (es1 != decode_str(as1)) {
        cout << "Expected: " + es1 << " Actual: " + decode_str(as1);
        return;
    }
    if (es2 != decode_str(as2)) {
        cout << "Expected: " + es2 << " Actual: " + decode_str(as2);
        return;
    }
    if (es3 != decode_str(as3)) {
        cout << "Expected: " + es3 << " Actual: " + decode_str(as3);
        return;
    }
    if (es4 != decode_str(as4)) {
        cout << "Expected: " + es4 << " Actual: " + decode_str(as4);
        return;
    }
    cout << "PASS!";
}
int main() { test_decode_str(); system("pause"); return 0;}