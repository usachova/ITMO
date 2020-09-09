#include <iostream>
#include <vector>

using namespace std;

vector<long long> d;
vector<int> par;
vector<vector<int>> mat;
int n;

int main() {
	freopen("negcycle.in", "r", stdin);
	freopen("negcycle.out", "w", stdout);
	cin >> n;
	long long inf = LLONG_MAX, inf1 = 100000;
	mat.resize(n);
	for (int i = 0; i < n; i++) mat[i].resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}		
	}
	d.assign(n, 0);
	par.assign(n, -1);
	for (int t = 0; t < n; t++)	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] != inf1) {
					if (d[j] > d[i] + mat[i][j]) {
						par[j] = i;
						d[j] = d[i] + mat[i][j];
					}
				}
			}
		}
	}
	vector<int> answer;
	bool flag = false;
	for (int i = 0; i < n; i++)	{
		if (flag) break;
		for (int j = 0; j < n; j++) {
			if (mat[i][j] != inf1) {
				if (d[j] > d[i] + mat[i][j]) {
					int v = j;
					for (int t = 0; t < n; t++) v = par[v];
					int u = v;
					answer.push_back(v);
					while (u != par[v]) {
						v = par[v];
						answer.push_back(v);
					}
					flag = true;
					break;			
				}
			}
		}
	}
	if (!flag) cout << "NO";
	else {
		cout << "YES" << endl;
		cout << answer.size() + 1 << endl;
		for (int i = answer.size() - 1; i >= 0 ; i--) cout << answer[i] + 1 << " ";
		cout << answer[answer.size() - 1] + 1;
	}
	return 0;
}
