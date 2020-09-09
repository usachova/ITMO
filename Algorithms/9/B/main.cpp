#include <iostream>
#include <vector>

using namespace std;

vector<int> reb[100000];
vector<int> color, p;
int c_s = -1, c_e;
int n, m;

void dfs(int v) {
	color[v] = 1;
	for (int i = 0; i < reb[v].size(); i++) {
		if (color[reb[v][i]] == 1) {
			c_s = reb[v][i];
			c_e = v;
		}
		if (color[reb[v][i]] == 0) {
			p[reb[v][i]] = v;
			dfs(reb[v][i]);
		}
	}
	color[v] = 2;
}

int main() {
	freopen("cycle.in", "r", stdin);
	freopen("cycle.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		reb[a].push_back(b);
	}
	p.assign(n, -1);
	color.assign(n, 0);
	for (int i = 0; i < n; i++) {
		if (color[i] == 0) dfs(i);
	}
	if (c_s != -1) {
		cout << "YES" << endl;
		vector<int> ans;
		ans.push_back(c_s);
		for (int i = c_e; i != c_s; i = p[i]) ans.push_back(i);
		for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] + 1 << " ";
	}
	else cout << "NO" << endl;
	return 0;
}
