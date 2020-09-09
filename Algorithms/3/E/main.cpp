#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main() {
  freopen("radixsort.in", "r", stdin);
  freopen("radixsort.out", "w", stdout);
  int n, m, k;
  cin >> n >> m >> k; 
  string mas[n];
  for (int i = 0; i < n; i++) {
    cin >> mas[i];
  }
  for (int j = 1; j <= k; j++) {
  	int cnt['z' - 'a' + 1];
	for (int i = 0; i < 'z' - 'a' + 1; i++) cnt[i] = 0;
	for (int i = 0; i < n; i++) cnt[int(mas[i][m - j]) - 'a']++;	
	int c = 0;
	for (int i = 0; i < 'z' - 'a' + 1; i++) {
		int tmp = cnt[i];
		cnt[i] = c;
		c += tmp;
	}
	string temp[n];
	for (int i = 0; i < n; i++) {
		temp[cnt[int(mas[i][m - j]) - 'a']] = mas[i];
		cnt[int(mas[i][m - j]) - 'a']++;
	}
	for (int i = 0; i < n; i++) mas[i] = temp[i];
  }
  for (int i = 0; i < n; i++) {
  	cout << mas[i] << endl;
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}

