#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> gr[100000], color, iswin;
int n, m, st;

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> m >> st;
	st--;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		gr[a].push_back(b);
	}
	color.assign(n, 0);
	iswin.assign(n, 0);
	stack<int> s;
	s.push(st);
	while (s.size() > 0) {
		int cur = s.top();
		if (color[cur] == 1) {
			int tmp = 0;
			for (int i = 0; i < gr[cur].size(); i++) {
				if (iswin[gr[cur][i]] == 0) tmp = 1;
			}
			iswin[cur] = tmp;
			color[cur] = 2;
			s.pop();
			continue;
		}
		else if (color[cur] == 2) {
			s.pop();
			continue;
		}
		color[cur] = 1;
		for (int i = 0; i < gr[cur].size(); i++) {
			if (color[gr[cur][i]] == 0) s.push(gr[cur][i]);
		}
	}
	if (iswin[st] == 1) cout << "First player wins";
	else cout << "Second player wins";
	return 0;
}
