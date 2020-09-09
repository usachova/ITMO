#include <iostream>
#include <vector>

using namespace std;

vector<int> reb[100000];
vector<int> ans;
int mas[100000], color[100000];
int n, m, k = 0;

void aldfs(int v) {
	color[v] = 1;
	for (int i = 0; i < reb[v].size(); i++) {
		if (color[reb[v][i]] == 1) k = 1;
		if (color[reb[v][i]] == 0) aldfs(reb[v][i]);
	}
	color[v] = 2;
}

void dfs(int v) {
	mas[v] = 1;
	for (int i = 0; i < reb[v].size(); i++) {
		if (mas[reb[v][i]] != 1) dfs(reb[v][i]);
	}
	ans.push_back(v);
}

void top_sort() {
	for (int i = 0; i < n; i++) color[i] = 0;
	for (int i = 0; i < n; i++) {
		if (color[i] == 0) aldfs(i);
	}
	for (int i = 0; i < n; i++) mas[i] = 0;
	ans.clear();
	for (int i = 0; i < n; i++) {
		if (mas[i] == 0) dfs(i);
	}
}

int main() {
	freopen("topsort.in", "r", stdin);
	freopen("topsort.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		reb[a].push_back(b);
	}
	top_sort();
	if (k == 0) for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] + 1 << " ";
	else cout << "-1" << endl;
	return 0;
}
