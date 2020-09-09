#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int mas[n][n];
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mas[i][j] = 0;
		}
	}
	int flag = 0;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		if (mas[x][y] == 1 || mas[y][x] == 1) flag = 1;
		mas[x][y] = 1;
		mas[y][x] = 1;
	}
	if (flag == 0) cout << "NO";
	else cout << "YES";
	return 0;
}
