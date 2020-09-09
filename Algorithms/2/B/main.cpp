#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

void merge(pair< string, string > m[], int left, int mid, int right) {
  pair< string, string > temp[right - left];
  int pos1 = left, pos2 = mid, pos = 0;
  while (pos1 < mid && pos2 < right) {
  	//if (m[pos1] <= m[pos2]) {
  	if (m[pos1].first <= m[pos2].first) {
  	  temp[pos] = m[pos1];
  	  pos1++;
	}
	else {
	  temp[pos] = m[pos2];
	  pos2++;
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

void mergeSort(pair< string, string > m[], int left, int right) {
  if (left + 1 < right) {
  	int mid = (left + right) / 2;
  	mergeSort(m, left, mid);
  	mergeSort(m, mid, right);
  	merge(m, left, mid, right);
  }
}

int main()
{
  freopen("race.in", "r", stdin);
  freopen("race.out", "w", stdout);
  int n;
  cin >> n;  
  pair< string, string > mas[n];
  for (int i = 0; i < n; i++) {
  	cin >> mas[i].first >> mas[i].second;
  }
  mergeSort(mas, 0, n);
  int cnt = 0;
  cout << "=== " << mas[0].first << " ===" << endl;
  cout << mas[0].second << endl;
  while (cnt < n - 1) {
  	cnt++;
    if (mas[cnt].first == mas[cnt - 1].first) {
    	cout << mas[cnt].second << endl;
	}
	else {
		cout << "=== " << mas[cnt].first << " ===" << endl;
        cout << mas[cnt].second << endl;
	}
  }
  fclose(stdin);
  fclose(stdout);
}

