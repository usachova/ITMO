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
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		mas[x][y] = 1;
	}
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
