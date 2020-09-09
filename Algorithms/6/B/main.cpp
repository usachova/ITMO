#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    ios_base::sync_with_stdio(false);
	int n, flag = 0;
	cin >> n;
	int prev[n + 1], mas[n + 1], zn[n + 1], mmin[n + 1], mmax[n + 1];
	int l, r, k;
	int min = -1000000001, max = 1000000001;
	if (n > 0) {
		prev[1] = 0;
		zn[1] = -1;
		mmin[1] = min;
		mmax[1] = max;
	}
	for (int i = 1; i <= n; i++) {
		cin >> k >> l >> r;
		mas[i] = k;
		prev[l] = i;
		zn[l] = 0;
		mmin[l] = mmin[i];
		mmax[l] = mas[i];
		prev[r] = i;
		zn[r] = 1;
		mmin[r] = mas[i];
		mmax[r] = mmax[i];
		if (mas[i] <= mmin[i] || mas[i] >= mmax[i]) flag = 1;
		/*int pr = i;
		while (pr > 1 && flag == 0) {
			if (zn[pr] == 0) {
				if (mas[i] >= mas[prev[pr]]) flag = 1;
			}
			else {
				if (mas[i] <= mas[prev[pr]]) flag = 1;
			}
			pr = prev[pr];
		}
		if (flag == 1) break;*/
	}
	if (flag == 0) cout << "YES";
	else cout << "NO";
	return 0;
}
