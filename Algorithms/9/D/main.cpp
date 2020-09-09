#include <iostream>
#include <vector>

using namespace std;

vector<int> reb[20000], tr[20000];
vector<int> ans, comp, res;
vector<int> used;
int n, m, cnt = 0;;

void dfs(int v) {
	used[v] = 1;
	for (int i = 0; i < reb[v].size(); i++) {
		if (used[reb[v][i]] != 1) dfs(reb[v][i]);
	}
	ans.push_back(v);
}

void c_dfs(int v) {
	used[v] = 1;
	comp.push_back(v);
	for (int i = 0; i < tr[v].size(); i++) {
		if (used[tr[v][i]] != 1) c_dfs(tr[v][i]);
	}
}

void top_sort() {
	used.assign(n, 0);
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) dfs(i);
	}
	used.assign(n, 0);
	res.assign(n, 0);
	for (int i = 0; i < n; i++) {
		int v = ans[n - 1 - i];
		if (used[v] == 0) {
			cnt++;
			c_dfs(v);
			for (int j = 0; j < comp.size(); j++) res[comp[j]] = cnt;
			comp.clear();
		}
	}
}

int main() {
	//freopen("cond.in", "r", stdin);
	//freopen("cond.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		reb[a].push_back(b);
		tr[b].push_back(a);
	}
	top_sort();
	cout << cnt << endl;
	for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
	return 0;
}
