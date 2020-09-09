#include <iostream>
#include <vector>

using namespace std;

const long long inf = 8e18;

struct edge {
	int a;
	int b;
	long long cost;
};

vector<long long> d;
vector<edge> reb;
vector<vector<int>> reb_v;
int n, m, s;

void dfs(int v, vector<bool> &vis) {
	vis[v] = true;
	for (int i = 0; i < reb_v[v].size(); i++) {
		if (!vis[reb_v[v][i]]) dfs(reb_v[v][i], vis);
	}  
}

int main() {
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	cin >> n >> m >> s;
	reb_v.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		long long w;
		cin >> a >> b >> w;
		edge e;
		e.a = a - 1;
		e.b = b - 1;
		e.cost = w;
		reb.push_back(e);
		reb_v[a - 1].push_back(b - 1);	
	}
	d.assign(n, inf + 1e17);
	d[s - 1] = 0;
	vector<bool> vis1;
	vis1.assign(n, false);
	dfs(s - 1, vis1);
	for (int t = 0; t < n; t++)	{
		for (int j = 0; j < m; j++) {
			if (vis1[reb[j].b] && d[reb[j].a] < inf && d[reb[j].b] > d[reb[j].a] + reb[j].cost) {
				d[reb[j].b] = max(-inf, d[reb[j].a] + reb[j].cost);
			}
		}
	}
	vector<long long> order(n);
	for (int i = 0; i < n; i++) order[i] = d[i];
	for (int i = 0; i < m; i++) {
		if (vis1[reb[i].b] && order[reb[i].a] < inf && order[reb[i].b] > order[reb[i].a] + reb[i].cost) {
			order[reb[i].b] = order[reb[i].a] + reb[i].cost;
		}
	}
	vector<bool> vis2;
	vis2.assign(n, false);
	for (int i = 0; i < n; i++) {
		if (vis1[i] && order[i] != d[i]) dfs(i, vis2);
	}
	for (int i = 0; i < n; i++) {
		if (d[i] >= inf) cout << "*" << endl;
		else if (vis2[i]) cout << "-" << endl;
		else cout << d[i] << endl;
	}
	return 0;
}
