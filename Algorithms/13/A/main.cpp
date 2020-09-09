#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	freopen("search1.in", "r", stdin);
	freopen("search1.out", "w", stdout);
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	string p, t;
	cin >> p >> t;
	int n = t.length();
	int m = p.length();
	vector<int> answer;
	for (int i = 0; i < n - m + 1; i++) {
		bool flag = true;
		for (int j = i; j < i + m; j++) {
			if (t[j] != p[j - i]) flag = false;
		}
		if (flag) answer.push_back(i);
	}
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) cout << answer[i] + 1 << " ";
	return 0;
}
