#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int gr[105][105];
int n, m, xs, xt, ys, yt;

void bfs() {
	queue<int> qx, qy;
	qx.push(xs);
	qy.push(ys);
	gr[xs][ys] = 1;
	while(qx.size() != 0) {
		int ux = qx.front(), uy = qy.front();
		qx.pop();
		qy.pop();
		if (gr[ux + 1][uy] == 0) {
			qx.push(ux + 1);
			qy.push(uy);
			gr[ux + 1][uy] = gr[ux][uy] + 1;
		}
		if (gr[ux - 1][uy] == 0) {
			qx.push(ux - 1);
			qy.push(uy);
			gr[ux - 1][uy] = gr[ux][uy] + 1;
		}
		if (gr[ux][uy + 1] == 0) {
			qx.push(ux);
			qy.push(uy + 1);
			gr[ux][uy + 1] = gr[ux][uy] + 1;
		}
		if (gr[ux][uy - 1] == 0) {
			qx.push(ux);
			qy.push(uy - 1);
			gr[ux][uy - 1] = gr[ux][uy] + 1;
		}	
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n + 2; i++) gr[i][0] = gr[i][m + 1] = -2; 
	for (int i = 0; i < m + 2; i++) gr[0][i] = gr[n + 1][i] = -2;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			gr[i + 1][j + 1] = 0; 
			if (str[j] == '#') gr[i + 1][j + 1] = -1;
			if (str[j] == 'S') {
				xs = i + 1;
				ys = j + 1;
			}
			if (str[j] == 'T') {
				xt = i + 1;
				yt = j + 1;
			}
		}
	}
	bfs();
	if (gr[xt][yt] == 0) cout << "-1";
	else {
		cout << gr[xt][yt] - 1 << endl;
		int x = xt, y = yt;
		vector<char> ans;
		while(gr[x][y] != 1) {
			if (gr[x - 1][y] == gr[x][y] - 1) {
				x = x - 1;
				ans.push_back('D');
			}
			else if (gr[x + 1][y] == gr[x][y] - 1) {
				x = x + 1;
				ans.push_back('U');
			}
			else if (gr[x][y - 1] == gr[x][y] - 1) {
				y = y - 1;
				ans.push_back('R');
			}
			else if (gr[x][y + 1] == gr[x][y] - 1) {
				y = y + 1;
				ans.push_back('L');
			}
		}	
		for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
	}
	return 0;
}
