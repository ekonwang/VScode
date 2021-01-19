#include<stack>
#include<iostream>
/* 最近很常见的问题：在声明库之后没有声明标准命名空间 */
#define MAXN 100
class Expression{
private:
    char mid_e[MAXN], pos_e[MAXN];
    float v[26];
public:
    int evaluate(float *p_y){
        float i, j, k, x, y, z;
        std::stack<float> s;
        char c;
        i = 0;
        c = pos_e[0];

        while(c != '\0'){
            if(islower(c)) s.push(v[c - 'a']);
            else switch(c){
                case '+':
                    x = s.top(); s.pop();
                    y = s.top(); s.pop();
                    s.push(x + y);
                    break;
                case '-':
                    x = s.top(); s.pop();
                    y = s.top(); s.pop();
                    s.push(y - x);
                    break;
                case '*':
                    x = s.top(); s.pop();
                    y = s.top(); s.pop();
                    s.push(x * y);
                    break;
                case '/':
                    x = s.top(); s.pop();
                    y = s.top(); s.pop();
                    if(!x) return 1;
                    s.push(y/x);
                    break;
                case '^':
                    x = s.top(); s.pop();
                    y = s.top(); s.pop();
                    if(!y) return 1;
                    if(x == 0) s.push(1);
                    else{
                        if(x > 0)j = x;
                        else j = -x;
                        for(z = 1, k = 1; k <= j; k++) z *= y;
                        if(x < 0) z = 1/z;
                        s.push(z);
                    }
                    break;
                default:
                    return 1;
            }
        }
        *p_y = s.top(); s.pop();
        if(s.empty()) return 0;
        else return 1;
    }
};
class Mid2Pos{
public:
    int icp(char c){
        switch(c){
            case '^': return 4;
            case '*':
            case '/': return 2;
            case '+':
            case '-': return 1;
        }
    }
    int isp(char c){
        switch(c){
            case '^': return 3;
            case '*':
            case '/': return 2;
            case '+':
            case '-': return 1;
            case '(': return 0;
            case '$': return -1;
        }
    }
    int mid2pos(char mid_e[], char pos_e[]){
        std::stack<char> s;
        char c;
        int i, j;
        j = 0;
        i = 0;
        c = mid_e[0];
        while(c != '\0'){
            if(islower(c)) pos_e[j++] = c;         //中缀改后缀不改变变量的相对位置
            else switch(c){
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while(icp(c) <= isp(s.top())) { pos_e[j++] = s.top(); s.pop(); }
                    s.push(c);
                    break; 
                case '(':
                    s.push(c);
                    break;
                case ')':
                    while( s.top() != '(') { pos_e[j++] = s.top(); s.pop(); }
                    s.pop();
                    break;
                default:
                    return 1;
            }
            c = mid_e[++i];
        }
        while(!s.empty()) {pos_e[j++] = s.top(); s.pop();}
        pos_e[j] = '\0';
        return 0;
    }
};