#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> mas;
	mas.assign(n, 0);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		mas[x]++;
		mas[y]++;
	}
	for (int i = 0; i < n; i++) cout << mas[i] << " ";
	return 0;
}
