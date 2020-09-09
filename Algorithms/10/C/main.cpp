#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> p, s;

int get(int v) {
	if (v == p[v]) return v;
	return p[v] = get(p[v]);
}

void unite(int a, int b) {
	a = get(a);
	b = get(b);
	if (a != b) {
		if (s[a] < s[b]) 
			swap(a, b);
		p[b] = a;
		s[a] += s[b];
	}
}

int main() {
	freopen("spantree3.in", "r", stdin);
	freopen("spantree3.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> reb;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		reb.push_back(make_pair(w, make_pair(x - 1, y - 1)));
	}
	long long res = 0;
	sort(reb.begin(), reb.end());
	p.resize(n);
	s.resize(n);
	for (int i = 0; i < n; i++) {
		p[i] = i;
		s[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int w = reb[i].first, a = reb[i].second.first, b = reb[i].second.second;
		if (get(a) != get(b)) {
			res += w;
			unite(a, b);
		}
	}
	cout << res;
	return 0;
}
