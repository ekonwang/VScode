#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a, b, c, pos = 0, gap = 'A' - 'a';
    string str;
    char cnt, head, rear, tmp;
    cin >> a >> b >> c >> str;
    
    cnt = str[pos];
    while((cnt = str[pos++]) != '\0'){
        if(cnt == '-'){
            rear = str[pos];
            if(rear <= head) {cout << cnt; continue;}

            if(a == 2 && islower(cnt)){
                if(c == 1)
                for(int i = head + 1; i < rear; i++){
                    cout << string((tmp = i + gap), b);
                }
                else
                for(int i = rear - 1; i > head; i--){
                    cout << string((tmp = i + gap), b);
                }
            }

            else{
                if(c == 1)
                for(int i = head + 1; i < rear; i++){
                    tmp = i + gap;
                    cout << string(tmp, b);
                }
                else
                for(int i = rear - 1; i > head; i--){
                    cout << string((tmp = i + gap), b);
                }
            }
        }else{
            cout << cnt;
            head = cnt;
        }
    }
}
int main(){
    solve();
    return 0;
}