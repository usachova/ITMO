#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dracula[100000]; //graph

int main() {
	freopen("bipartite.in", "r", stdin);
	freopen("bipartite.out", "w", stdout);
	vector<int> color;
	bool flag = true;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		dracula[a].push_back(b);
		dracula[b].push_back(a);
	}
	color.assign(n, 0);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (color[i] == 0) {
			q.push(i);
			color[i] = 1;
			while(q.size() != 0) {
				int v = q.front();
				q.pop();
				for (int j = 0; j < dracula[v].size(); j++) {
					int to = dracula[v][j];
					if (color[to] == 0) {
						color[to] = -color[v];
						q.push(to);
					}
					else if (color[to] == color[v]) flag = false;
				}	
			}
		}
	}
	if (flag) cout << "YES";
	else cout << "NO";
	return 0;
}
