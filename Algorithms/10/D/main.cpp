#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

struct edge {
	int to;
	int from;
	long long cost;
};

void dfs1(int v, vector<edge> &edges, vector<int> &order, vector<int> &used) {
	used[v] = 1;
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i].from == v && used[edges[i].to] == 0)
			dfs1(edges[i].to, edges, order, used);
	}
	order.push_back(v);
}

void dfs2(int v, vector<edge> &edges, vector<int> &comp, vector<int> &used) {
	used[v] = 1;
	comp.push_back(v);
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i].to == v && used[edges[i].from] == 0)
			dfs2(edges[i].from, edges, comp, used);
	}
}

vector<int> cond(vector<edge> &zero, int k) {
	vector<int> result(k);
	vector<int> order, comp, used;
	used.assign(k, 0);
	for (int i = 0; i < k; i++) {
		if (used[i] == 0) dfs1(i, zero, order, used);
	}
	used.assign(k, 0);
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		int v = order[k - 1 - i];
		if (used[v] == 0) {
			comp.clear();
			dfs2(v, zero, comp, used);
			for (int j = 0; j < comp.size(); j++) result[comp[j]] = cnt;
			cnt++;
		}
	}
	return result;
}

void dfs(int v, vector<edge> &edges, vector<int> &used) {
	used[v] = 1;
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i].from == v && used[edges[i].to] == 0)
			dfs(edges[i].to, edges, used);
	}
}

bool check(int root, vector<edge> &edges, int k) {
	vector<int> used;
	used.assign(k, 0);
	dfs(root, edges, used);
	for (int i = 0; i < k; i++) {
		if (used[i] == 0) return false;
	}
	return true;
}

long long mst(vector<edge> &edges, int k, int root) {
	long long res = 0;
	vector<long long> min_e;
	min_e.assign(k, INT_MAX);
	for (int i = 0; i < edges.size(); i++) {
		min_e[edges[i].to] = min(min_e[edges[i].to], edges[i].cost);
	}
	for (int i = 0; i < k; i++) {
		if(i != root) res += min_e[i];
	}
	vector<edge> zero_e;
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i].cost == min_e[edges[i].to]) {
			edge e;
			e.from = edges[i].from;
			e.to = edges[i].to;
			e.cost = 0;
			zero_e.push_back(e);
		}
	}
	if (check(root, zero_e, k)) return res;
	vector<int> n_comps;
	n_comps = cond(zero_e, k);
	vector<edge> n_edges;
	for (int i = 0; i < edges.size(); i++) {
		if (n_comps[edges[i].from] != n_comps[edges[i].to]) {
			edge e;
			e.from = n_comps[edges[i].from];
			e.to = n_comps[edges[i].to];
			e.cost = edges[i].cost - min_e[edges[i].to];
			n_edges.push_back(e);
		}
	}
	int c_cnt = 0;
	for (int i = 0; i < n_comps.size(); i++) {
		if (n_comps[i] > c_cnt) c_cnt = n_comps[i];
	}
	res += mst(n_edges, c_cnt + 1, n_comps[root]);
	return res;
}

int main() {
	freopen("chinese.in", "r", stdin);
	freopen("chinese.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<edge> edges;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		edge e;
		e.from = x - 1;
		e.to = y - 1;
		e.cost = w;
		edges.push_back(e);
	}
	if (!check(0, edges, n)) cout << "NO";
	else cout << "YES\n" << mst(edges, n, 0);
	return 0;
}  
