#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;
int a[N], d1[N], d2[N], n;
int main() {
    cout << n << endl;
	while (cin >> a[++n]); n--;	
    cout << n << endl;	
	int len1 = 1, len2 = 1;		
	d1[1] = a[1];		
	d2[1] = a[1];	
	for (int i=2; i<=n; i++) {	
		if (d1[len1] >= a[i]) d1[++len1] = a[i];	
		else {		
			int p1 = upper_bound(d1 + 1, d1 + 1 + len1, a[i], greater<int>()) - d1;
			d1[p1] = a[i]; 
		}
		if (d2[len2] < a[i]) d2[++len2] = a[i];	
		else {
			int p2 = lower_bound(d2 + 1, d2 + 1 + len2, a[i]) - d2;
			d2[p2] = a[i];
		}
	}
	cout << len1 << endl << len2;	
    system("pause");	
	return 0;		
}