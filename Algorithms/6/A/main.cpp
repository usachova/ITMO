#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
	int n;
	int cnt = 0;
	cin >> n;
	int mas[n + 1];
	int l, r, k;
	if (n > 0) {
		mas[1] = 1;
		cnt = 1;
	}
	for (int i = 1; i <= n; i++) {
		cin >> k >> l >> r;
		mas[l] = mas[i] + 1;
		mas[r] = mas[i] + 1;
		if (r != 0 && mas[r] > cnt) cnt = mas[r];
		if (l != 0 && mas[l] > cnt) cnt = mas[l];
	}
	cout << cnt;
	return 0;
}
