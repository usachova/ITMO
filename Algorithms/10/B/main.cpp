#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>

using namespace std;

//vector< pair < double, pair< int, int > > > reb;
vector<pair<int, int>> ver;

int main() {
	freopen("spantree.in", "r", stdin);
	freopen("spantree.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ver.push_back({x, y});
	}
	/*for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			if (i != j) {
				double w = sqrt((ver[i].first - ver[j].first) * (ver[i].first - ver[j].first) + (ver[i].second - ver[j].second) * (ver[i].second - ver[j].second));
				reb.push_back(make_pair(w, make_pair(i, j)));
			}
		}*/
	double res = 0;
	//sort(reb.begin(), reb.end());
	vector<int> comp(n), d(n);
	for (int i = 0; i < n; i++) comp[i] = 0;
	for (int i = 1; i < n; i++) d[i] = (ver[i].first - ver[0].first) * (ver[i].first - ver[0].first) + (ver[i].second - ver[0].second) * (ver[i].second - ver[0].second);
	int cnt = 1;
	while (cnt != n) {
		int min = INT_MAX, v;
		for (int i = 1; i < n; i++)
			if (d[i] < min && comp[i] == 0) {
				min = d[i];
				v = i;
			}
		res += sqrt(min);
		cnt++;
		comp[v]++;
		for (int i = 1; i < n; i++)
			if (comp[i] == 0) {
				int temp = (ver[i].first - ver[v].first) * (ver[i].first - ver[v].first) + (ver[i].second - ver[v].second) * (ver[i].second - ver[v].second);
				if (temp < d[i]) d[i] = temp;
			}
		/*double w = reb[i].first;
		int a = reb[i].second.first, b = reb[i].second.second;
		if (comp[a] != comp[b]) {
			res += w;
			int temp = comp[b];
			for (int j = 0; j < n; j++)
				if (comp[j] == temp) comp[j] = comp[a];
		}*/
	}	
	//cout << res;
	printf("%.3lf", res);
	return 0;
}
