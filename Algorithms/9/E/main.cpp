#include <iostream>
#include <vector>

using namespace std;

vector<int> reb[100000];
vector<int> ans;
int mas[100000];
int n, m, k = 0;

void dfs(int v) {
	mas[v] = 1;
	for (int i = 0; i < reb[v].size(); i++) {
		if (mas[reb[v][i]] != 1) dfs(reb[v][i]);
	}
	ans.push_back(v);
}

void top_sort() {
	for (int i = 0; i < n; i++) mas[i] = 0;
	ans.clear();
	for (int i = 0; i < n; i++) {
		if (mas[i] == 0) dfs(i);
	}
}

int main() {
	freopen("hamiltonian.in", "r", stdin);
	freopen("hamiltonian.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		reb[a].push_back(b);
	}
	top_sort();
	int flag = 0;
	for (int i = ans.size() - 1; i > 0; i--) {
		int fl = 0;
		for (int j = 0; j < reb[ans[i]].size(); j++) {
			if (reb[ans[i]][j] == ans[i - 1]) {
				fl = 1;
				break;
			}
		}
		if (fl != 1) {
			flag = 1;
			break;
		} 
	}
	if (flag == 0) cout << "YES";
	else cout << "NO";
	return 0;
}
