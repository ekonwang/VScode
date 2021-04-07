#include "add.h"
int add(int s[], int n) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += s[i];
    }
    return ans;
}
