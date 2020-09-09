#include <iostream>
#include <cstdio>

using namespace std;

int lower_bnd (int m[], int n, int x) {
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (x <= m[mid]) r = mid;
		else l = mid + 1;
	}
	return l;
}

int upper_bnd (int m[], int n, int x) {
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (x >= m[mid]) l = mid + 1;
		else r = mid;
	}
	return r;
}

int main()
{
  freopen("binsearch.in", "r", stdin);
  freopen("binsearch.out", "w", stdout);
  int n, m;
  cin >> n;  
  int mas[n];
  for (int i = 0; i < n; i++) {
    cin >> mas[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    if (lower_bnd(mas, n, x) == upper_bnd(mas, n, x)) cout << "-1 -1" << endl;
    else cout << lower_bnd(mas, n, x) + 1 << " " << upper_bnd(mas, n, x) << endl;
  }
  fclose(stdin);
  fclose(stdout);
}

