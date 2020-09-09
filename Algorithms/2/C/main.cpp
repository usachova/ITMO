#include <iostream>
#include <cstdio>

using namespace std;

long long cnt = 0;

void merge(int m[], int left, int mid, int right) {
  int temp[right - left];
  int pos1 = left, pos2 = mid, pos = 0;
  while (pos1 < mid && pos2 < right) {
  	if (m[pos1] <= m[pos2]) {
  	  temp[pos] = m[pos1];
  	  pos1++;
	}
	else {
	  temp[pos] = m[pos2];
	  pos2++;
	  cnt += mid - pos1;
	}
	pos++;
  }
  while (pos1 < mid) {
  	temp[pos] = m[pos1];
  	pos1++;
  	pos++;
  }
  while (pos2 < right) {
  	temp[pos] = m[pos2];
  	pos2++;
  	pos++;
  }
  for (int i = 0; i < pos; i++) {
  	m[i + left] = temp[i];
  }
  return;
}

void mergeSort(int m[], int left, int right) {
  if (left + 1 < right) {
  	int mid = (left + right) / 2;
  	mergeSort(m, left, mid);
  	mergeSort(m, mid, right);
  	merge(m, left, mid, right);
  }
}

int main()
{
  freopen("inversions.in", "r", stdin);
  freopen("inversions.out", "w", stdout);
  int n;
  cin >> n;  
  int mas[n];
  for (int i = 0; i < n; i++) {
    cin >> mas[i];
  }
  mergeSort(mas, 0, n);
  cout << cnt;
  fclose(stdin);
  fclose(stdout);
}

