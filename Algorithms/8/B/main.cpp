#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int mas[n][n];
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mas[i][j];
		}
	}
	int flag = 1;
	for(int i = 0; i < n; i++) {
		if (mas[i][i] == 1) flag = 0;
		for (int j = 0; j < n; j++) {
			if (i != j && mas[i][j] != mas[j][i]) flag = 0;
		}
	}
	if (flag == 0) cout << "NO";
	else cout << "YES";
	return 0;
}
