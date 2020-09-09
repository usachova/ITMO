#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main() {
	freopen("map.in", "r", stdin);
	freopen("map.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	vector<pair<string, string>> h[100000];
	string str;
	while (cin >> str) {
		string key;
		cin >> key;
		long long sum = 0, p = 3, y;
		for (int i = 0; i < key.length(); i++) {
			sum += key[i] * p;
			p *= 3;
		}
		y = sum % 99456;
		if (str == "put") {
			string val;
			cin >> val;
			int flag = -1;
			for (int i = 0; i < h[y].size(); i++) if (h[y][i].first == key) flag = i;
			if (flag == -1) h[y].push_back(make_pair(key, val));
			else h[y][flag].second = val;
		}
		if (str == "delete") {
			int flag = -1;
			for (int i = 0; i < h[y].size(); i++) if (h[y][i].first == key) flag = i;
			if (flag != -1) {
				swap(h[y][flag], h[y][h[y].size() - 1]);
				h[y].pop_back();
			}
		}
		if (str == "get") {
			int flag = -1;
			for (int i = 0; i < h[y].size(); i++) if (h[y][i].first == key) flag = i;
			if (flag == -1) cout << "none" << endl;
			else cout << h[y][flag].second << endl;
		}
	}
	return 0;
}
