#include <iostream>
#include <vector>

using namespace std;

struct edge {
	int a;
	int b;
	int cost;
};

int mat[200][200], d[200][200];
vector<edge> reb;
int n, m;

int main() {
	freopen("pathsg.in", "r", stdin);
	freopen("pathsg.out", "w", stdout);
	cin >> n >> m;
	int inf = 3000000;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			if (i != j) d[i][j] = inf;
			else d[i][j] = 0;
		}
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edge e;
		e.a = a - 1;
		e.b = b - 1;
		e.cost = w;
		reb.push_back(e);	
		//d[a - 1][b - 1] = w;
		//d[b - 1][a - 1] = w;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (d[k][reb[j].a] < inf)
					d[k][reb[j].b] = min(d[k][reb[j].b], d[k][reb[j].a] + reb[j].cost);
			}
		}
	}
	/*for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
