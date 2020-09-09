#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<vector<long long>> cap, f, m_cap;
vector<int> pr;
int s, t;
int n;

long long bfs() {
	pr.assign(n, INT_MAX);
	pr[0] = 0;
	queue<int> q;
	q.push(0);
	while (q.size() > 0) {
		int u = q.front();
		q.pop();
		for (int v = 0; v < n; v++) {
			if (pr[v] == INT_MAX && cap[u][v] - f[u][v] > 0) {
				pr[v] = u;
				if (v == n - 1) {
					int w = v;
					long long flow = LLONG_MAX;
					for (u = pr[w]; v != 0; v = u, u = pr[u]) {
						flow = min(flow, cap[u][v] - f[u][v]);
					}
					for (u = pr[w], v = w; v != 0; v = u, u = pr[u]) {
						f[u][v] += flow;
						f[v][u] -= flow;
					}
					return flow;
				}
				q.push(v);
			}
		}
	}
	return 0;	
}



int main() {
	freopen("circulation.in", "r", stdin);
	freopen("circulation.out", "w", stdout);
	int m;
	cin >> n >> m;
	n += 2;
	s = 0;
	t = n - 1;
	cap.resize(n);
	for (int i = 0; i < n; i++) cap[i].assign(n, 0);
	m_cap.resize(n);
	for (int i = 0; i < n; i++) m_cap[i].assign(n, 0);
	f.resize(n);
	for (int i = 0; i < n; i++) f[i].assign(n, 0);
	vector<pair<int, int>> num;
	for (int i = 0; i < m; i++) {
		int x, y, c1, c2;
		cin >> x >> y >> c1 >> c2;
		m_cap[x][y] = c1;
		cap[s][y] += c1;
		cap[x][y] = c2 - c1;
		cap[x][t] += c1;
		num.push_back({x, y});
	}
	while (bfs() > 0) {}
	bool flag = false;
	for (int i = 1; i < n; i++) {
		if (f[s][i] < cap[s][i]) {
			flag = true;
			break;
		}
	}
	if (flag) cout << "NO";
	else { 
		cout << "YES" << endl;
		for (int i = 0; i < m; i++) {
			int x = num[i].first, y = num[i].second;
			cout << f[x][y] + m_cap[x][y] << endl;
		}
	}
	return 0;
}
