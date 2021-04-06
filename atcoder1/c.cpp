#include <bits/stdc++.h>
int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int main() {
	int n = ri();
	int a[n];
	for (auto &i : a) i = ri();
	
	int res = 2000000000;
	for (int i = 0; i < 1 << (n - 1); i++) {
		int xored = 0;
		int ored = 0;
		for (int j = 0; j <= n; j++) {
			if (j < n) ored |= a[j];
			if (j == n || (i >> j & 1)) xored ^= ored, ored = 0;
            // i >> j & 1
            // what does this mean?
		}
		res = std::min(res, xored);
        printf("\nxor: %d", xored);
	}
	
	printf("%d\n", res);
	return 0;
}