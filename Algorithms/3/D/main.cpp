#include <iostream>
#include <cstdio>

using namespace std;

void siftdown(int i, int n, int m[]) {
	while (true) {
		int j = 2 * i + 1;
		if (j + 1 <= n - 1 && m[j] > m[j + 1]) j++;
		if (!(j <= n - 1 && m[i] > m[j])) break;
		swap(m[j], m[i]);
		i = j;
	}
}

void build(int n, int m[]) {
	for (int i = n - 1; i >= 0; i--) siftdown(i, n, m);
}

void delmin(int m[], int n) {
	cout << m[0] << " ";
	swap(m[0], m[n]);
	siftdown(0, n, m);
}

int main() {
  freopen("sort.in", "r", stdin);
  freopen("sort.out", "w", stdout);
  int n;
  cin >> n;  
  int mas[n];
  for (int i = 0; i < n; i++) {
    cin >> mas[i];
  }
  build(n, mas);
  for (int i = n - 1; i >= 0; i--) {
  	delmin(mas, i);
  }
  fclose(stdin);
  fclose(stdout);
}

