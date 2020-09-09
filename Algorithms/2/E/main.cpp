#include <iostream>
#include <cstdio>
#include <utility>

using namespace std;

pair< int, int > partition(long m[], int l, int r) {
	long mid = m[(l + r) / 2];
	int i = l, j = r;
	while (i <= j) {
		while (m[i] < mid) i++;
		while (m[j] > mid) j--;
		if (i <= j) {
			swap(m[i], m[j]);
			i++;
			j--;
		}
	}
	return make_pair(i, j);
}

void quickSort(long m[], int l, int r) {
	if (l >= r) return;
	pair< int, int > p = partition(m, l, r);
	quickSort(m, l, p.second);
	quickSort(m, p.first, r);
	
}

int stat(long m[], int l, int r, int k) {
	pair< int, int > p = partition(m, l, r);
	if (p.second < k && k < p.first) return m[k];
	if (k <= p.second) return stat(m, l, p.second, k);
	else return stat(m, p.first, r, k); 
}

int main()
{
  freopen("kth.in", "r", stdin);
  freopen("kth.out", "w", stdout);
  int n, k;
  cin >> n >> k;  
  long mas[n];
  int A, B, C;
  cin >> A >> B >> C >> mas[0] >> mas[1];
  for (int i = 2; i < n; i++) {
    mas[i] = A * mas[i - 2] + B * mas[i - 1] + C;
  }
  cout << stat(mas, 0, n - 1, k - 1);
  fclose(stdin);
  fclose(stdout);
}

