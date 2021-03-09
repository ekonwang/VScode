#include<bits/stdc++.h> 
long long res = 1, n, p; int main(){ std::cin >> n >> p;long long i = 0, t = 1; 
for(i = p; i >= 1; i--) { t *= i; t %= n; res += t;} res %= n;
std::cout << res << std::endl; system("pause");return 0;}