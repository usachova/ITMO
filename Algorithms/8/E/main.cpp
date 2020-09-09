#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dracula[30000]; //граф
int ans[30000];
int used[30000];
int n;

void bfs(int v) {
	queue<int> q;
	q.push(v);
	used[v] = 1;
	while(q.size() != 0) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < dracula[u].size(); i++) {
			int to = dracula[u][i];
			if (used[to] == 0) {
				used[to] = 1;
				q.push(to);
				ans[to] = ans[u] + 1;
			}
		}		
	}
}

int main() {
	freopen("pathbge1.in", "r", stdin);
	freopen("pathbge1.out", "w", stdout);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		dracula[a].push_back(b);
		dracula[b].push_back(a);
	}
	ans[0] = 0;
	for (int i = 1; i < n; i++) ans[i] = -1;
	for (int i = 0; i < n; i++) used[i] = 0;
	bfs(0);
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	return 0;
}
