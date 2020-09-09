#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> gr;
vector<bool> used;
vector<int> matching;

bool kuhn(int v) {
	if (used[v]) return false;
	used[v] = true;
	for (int u : gr[v]) {
		if (matching[u] == -1 || kuhn(matching[u])) {
			matching[u] = v;
			return true;
		}
	}
	return false;
}

int main() {
	freopen("matching.in", "r", stdin);
	freopen("matching.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	gr.resize(n + m);
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y += n - 1;
		gr[x].push_back(y);
	}
	int answer = 0;
	matching.assign(n + m, -1);
	for (int i = 0; i < n; i++) {
		used.assign(n + m, false);
		if (kuhn(i)) answer++;
	}
	cout << answer;
	//cout << endl;
	//for (int i = 0; i < n + m; i++) cout << matching[i] << " " << i << endl;
	return 0;
}
