#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main() {
	freopen("multimap.in", "r", stdin);
	freopen("multimap.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	vector<pair<string, vector<string>[100]>> h[100000];
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
			int z;
			sum = 0;
			p = 3;
			for (int i = 0; i < val.length(); i++) {
				sum += val[i] * p;
				p *= 3;
			}
			z = sum % 94;
			int flag = -1;
			for (int i = 0; i < h[y].size(); i++) if (h[y][i].first == key) flag = i;
			if (flag == -1) {
				vector<string> vec[100];
				pair<string, vector<string>[100]> my_pair;
				my_pair.first = key;
				h[y].push_back(my_pair);
				h[y][h[y].size() - 1].second[z].push_back(val);
			}
			else {
				int flag2 = -1;
				for (int i = 0; i < h[y][flag].second[z].size(); i++) if (h[y][flag].second[z][i] == val) flag2 = i;
				if (flag2 == -1) h[y][flag].second[z].push_back(val);
			}
		}
		if (str == "delete") {
			string val;
			cin >> val;
			int z;
			sum = 0;
			p = 3;
			for (int i = 0; i < val.length(); i++) {
				sum += val[i] * p;
				p *= 3;
			}
			z = sum % 94;
			int flag = -1;
			for (int i = 0; i < h[y].size(); i++) if (h[y][i].first == key) flag = i;
			if (flag != -1) {
				int flag2 = -1;
				for (int i = 0; i < h[y][flag].second[z].size(); i++) if (h[y][flag].second[z][i] == val) flag2 = i;
				if (flag2 != -1) {
					swap(h[y][flag].second[z][flag2], h[y][flag].second[z][h[y][flag].second[z].size() - 1]);
					h[y][flag].second[z].pop_back();
				}
			}
		}
		if (str == "deleteall") {
			int flag = -1;
			for (int i = 0; i < h[y].size(); i++) if (h[y][i].first == key) flag = i;
			if (flag != -1) {
				for (int i = 0; i < 100; i++) {
					while (h[y][flag].second[i].size()) h[y][flag].second[i].pop_back();
				}
			}
		}
		if (str == "get") {
			int flag = -1;
			for (int i = 0; i < h[y].size(); i++) if (h[y][i].first == key) flag = i;
			vector<string> ans;
			if (flag != -1) {
				for (int i = 0; i < 100; i++) {
					for (int j = 0; j < h[y][flag].second[i].size(); j++) {
						ans.push_back(h[y][flag].second[i][j]);
					}
				}
			}
			cout << ans.size() << " ";
			for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
			cout << endl;
		}
	}
	return 0;
}
