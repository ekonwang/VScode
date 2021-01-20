//#pragma comment(linker,"/STACK:1024000000,1024000000") 
#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<map>
#include<queue>
#include<random>
#include<set>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const int mod = 128;
const int maxn = 200010;
const int maxm = 2010;

const int charset = 26, base = 'a', maxnode = 10000;
struct trie {
 int tot, root, child[maxnode][charset];//child[i][j]:以i为根的子树，字符j连向的节点(==0 则不存在)
 int flag[maxnode];//节点i是不是单词结尾
 trie() {
  memset(child[1], 0, sizeof(child[1]));
  flag[1] = 0;
  root = tot = 1;
 }
 void insert(const char* str) {
  int* cur = &root;
  for (const char* p = str; *p; ++p) {
   cur = &child[*cur][*p - base];
   if (*cur == 0) {
    *cur = ++tot;
    memset(child[tot], 0, sizeof(child[tot]));
    flag[tot] = 0;
   }
  }
  flag[*cur]++;
 }
 int ask(const char* str) {
  int* cur = &root;
  for (const char* p = str; *p && *cur; ++p)
   cur = &child[*cur][*p - base];

  if (*cur != 0)
   return flag[*cur];
 }
};

char str[maxn];
int dp[maxn];

int main() {
 int t; cin >> t;
 int n, m;
 while (t--) {
  scanf("%d%d", &n, &m);
  trie tree;
  for (int i = 1; i <= m; ++i) {
   char a; char s[10];
   scanf_s("%c%s", &a, 1, s, 5);
   tree.insert(s);
  }
  scanf_s("%s", str + 1, n + 1);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
   dp[i] = 0;
   for (int j = max(0, i - 5); j < i; ++j) {
    char s[5];
    memcpy(str + j, s, i - j);
    dp[i] += dp[j] * tree.ask(s);
   }
  }
  if (dp[n] == 0)
   printf("nonono\n");
  else if (dp[n] == 1)
   printf("happymorsecode\n");
  else
   printf("puppymousecat %d\n", dp[n]);
 }
}