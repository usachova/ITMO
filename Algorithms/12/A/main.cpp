#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> w;
vector<bool> vis;
int s, t;

int dfs(int v, int c) {
	if (v == t) return c;
	vis[v] = true;
	for (int u = 0; u < vis.size(); u++) {
		if (!vis[u] && w[v][u] > 0) {
			int r = dfs(u, min(c, w[v][u]));
			if (r > 0) {
				w[v][u] -= r;
				w[u][v] += r;
				return r;
			}
		}
	}
	return 0;	
}

int main() {
	freopen("maxflow.in", "r", stdin);
	freopen("maxflow.out", "w", stdout);
	int n, m, cnst = 100000001;
	cin >> n >> m;
	s = 0;
	t = n - 1;
	w.resize(n);
	for (int i = 0; i < n; i++) w[i].assign(n, 0);
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		w[x - 1][y - 1] = c;
	}
	int flow = 1, answer = 0;
	while (flow > 0) {
		vis.assign(n, false);
		flow = dfs(s, cnst);
		answer += flow;
	}
	cout << answer;
	return 0;
}
