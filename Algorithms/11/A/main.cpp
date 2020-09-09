#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("pathmgep.in", "r", stdin);
	freopen("pathmgep.out", "w", stdout);
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int n, s, f;
	cin >> n >> s >> f;
	s--;
	f--;
	vector<vector<long long>> mat(n);
	for (int i = 0; i < n; i++) mat[i].resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	vector<bool> vis(n);
	vector<unsigned long long> d(n);
	for (int i = 0; i < n; i++) {
		vis[i] = false;
		d[i] = ULLONG_MAX;
	}
	d[s] = 0;
	int v = 0;
	unsigned long long min;
	for (int i = 0; i < n; i++) {
		min = ULLONG_MAX; 
		for (int j = 0; j < n; j++) {
			if (!vis[j] && d[j] < min) {
				v = j;
				min = d[j];
			}
		}
		//if (d[v] == ULONG_MAX) break;
		vis[v] = true;
		for (int j = 0; j < n; j++) {
            if (d[j] > d[v] + mat[v][j] && d[v] != ULLONG_MAX && mat[v][j] != -1 && !vis[j]) {
                d[j] = d[v] + mat[v][j];
            }
        }
	}
	if (d[f] != ULLONG_MAX) cout << d[f];
	else cout << "-1";
	return 0;
}
