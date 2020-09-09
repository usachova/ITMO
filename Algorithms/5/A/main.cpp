#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	vector<int> h[1000000];
	string str;
	while (cin >> str) {
		int x, y;
		cin >> x;
		y = ((x % 994567) + 994567) % 994567;
		if (str == "insert") {
			int flag = 0;
			for (int i = 0; i < h[y].size(); i++) if (h[y][i] == x) flag = 1;
			if (flag == 0) h[y].push_back(x);
		}
		if (str == "delete") {
			int flag = -1;
			for (int i = 0; i < h[y].size(); i++) if (h[y][i] == x) flag = i;
			if (flag != -1) {
				swap(h[y][flag], h[y][h[y].size() - 1]);
				h[y].pop_back();
			}
		}
		if (str == "exists") {
			int flag = 0;
			for (int i = 0; i < h[y].size(); i++) if (h[y][i] == x) flag = 1;
			if (flag == 0) cout << "false" << endl;
			else cout << "true" << endl;
		}
	}
	return 0;
}
