#include <iostream>
#include <vector>

using namespace std;

vector<int> reb[100000];
vector<int> comp;
int mas[100000];
int c = 0;

void dfs(int v) {
	mas[v] = 1;
	comp.push_back(v);
	for (int i = 0; i < reb[v].size(); i++) {
		if (mas[reb[v][i]] != 1) dfs(reb[v][i]);
	}
}

int main() {
	freopen("components.in", "r", stdin);
	freopen("components.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		reb[a].push_back(b);
		reb[b].push_back(a);
	}
	for (int i = 0; i < n; i++) mas[i] = 0;
	int cnt = 0;
	int ans[n];
	for (int i = 0; i < n; i++) {
		if (mas[i] == 0) {
			cnt++;
			comp.clear();
			dfs(i);
			for (int j = 0; j < comp.size(); j++) ans[comp[j]] = cnt;
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	return 0;
}
