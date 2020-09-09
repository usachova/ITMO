#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int mas[n + 1], prev[n + 1], vl[n + 1], vr[n + 1];
	int l, r, k;
	prev[0] = -1;
	if (n > 0) prev[1] = 0;
	for (int i = 0; i <= n; i++) {
		vr[i] = 0;
		vl[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> k >> l >> r;
		mas[l] = -1;
		prev[l] = i;
		mas[r] = 1;
		prev[r] = i;
		if (l == 0 && r == 0) {
			int pr = prev[i];
			int ii = i;
			while (pr != 0) {
				if (mas[ii] == -1) {
					int max = -1;
					if (vl[pr] == 0) {
						max = vl[ii] + 1;
						if (max < vr[ii] + 1) max = vr[ii] + 1;
					}
					else {
						max = vl[pr];
						if (max < vl[ii] + 1) max = vl[ii] + 1;
						if (max < vr[ii] + 1) max = vr[ii] + 1;
					}
					vl[pr] = max;
				}
				else {
					int max = -1;
					if (vr[pr] == 0) {
						max = vl[ii] + 1;
						if (max < vr[ii] + 1) max = vr[ii] + 1;
					}
					else {
						max = vr[pr];
						if (max < vl[ii] + 1) max = vl[ii] + 1;
						if (max < vr[ii] + 1) max = vr[ii] + 1;
					}
					vr[pr] = max;
				}
				ii = pr;
				pr = prev[pr];
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << vr[i] - vl[i] << endl;
	return 0;
}
