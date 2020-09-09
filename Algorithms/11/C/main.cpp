#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<unsigned long> d;
int n, m;

int main() {
	freopen("pathbgep.in", "r", stdin);
	freopen("pathbgep.out", "w", stdout);
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin >> n >> m;
	vector<vector<pair<int, int>>> mat(n);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		mat[a - 1].push_back({b - 1, w});
		mat[b - 1].push_back({a - 1, w});
	}
	vector<bool> vis;
	vis.assign(n, false);
	d.assign(n, ULONG_MAX);
	d[0] = 0; 
	/*for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && (v == -1 || d[j] < d[v])) v = j;
		}
		if (d[v] == ULONG_MAX) break;
		vis[v] = true;
		for (int j = 0; j < mat[v].size(); j++) {
            if (d[mat[v][j].first] > d[v] + mat[v][j].second) 
				d[mat[v][j].first] = d[v] + mat[v][j].second;
        }
	}*/
	priority_queue<pair<int,int>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
    	long long dist = -q.top().first;
        int v = q.top().second;
        q.pop();
        if (dist <= d[v]) {
            for (int j = 0; j < mat[v].size(); j++) {
                if (d[mat[v][j].first] > d[v] + mat[v][j].second) {
                    d[mat[v][j].first] = d[v] + mat[v][j].second;
                    q.emplace(-d[mat[v][j].first], mat[v][j].first);
                }
            }
        }
    }
	for (int i = 0; i < n; i++) {
		if (d[i] < ULONG_MAX) cout << d[i] << " ";
		else cout << "-1 ";
	}
	return 0;
}
