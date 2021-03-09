#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int a[N], d1[N], d2[N], n;
int main() {
    /* way 1 */
	//while (cin >> a[n++]); n--;
    /* way 2 */
    while (cin >> a[n++]){if (cin.get() == '\n') break;} 
	int len1 = 0, len2 = 0;	
	d1[0] = a[0];		
	d2[0] = a[0];		
	for (int i=1; i<n; i++) {		
		if (d1[len1] >= a[i]) d1[++len1] = a[i];	
		else {		
			int p1 = upper_bound(d1, d1 + len1 + 1, a[i], greater<int>()) - d1;
			d1[p1] = a[i]; 
		}
		if (d2[len2] < a[i]) d2[++len2] = a[i];	
		else {
			int p2 = lower_bound(d2, d2 + 1 + len2, a[i]) - d2;
			d2[p2] = a[i];
		}
	}
	cout << len1 + 1 << endl << len2 + 1;	
    //system("pause");
	return 0;	
}