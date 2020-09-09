#include <iostream>
#include <vector>
#include <string>

using namespace std;

void pref(string s, vector<int> &p) {
    p[0] = 0;
    for (int i = 1; i < s.length(); i++) {
        int k = p[i - 1];
        while (k > 0 && s[i] != s[k]) k = p[k - 1];
        if (s[i] == s[k]) k++;
        p[i] = k;
    }
}

int main() {
    freopen("search2.in", "r", stdin);
    freopen("search2.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    string p, t;
    cin >> p >> t;
    int n = t.length();
    int m = p.length();
    string s = p + "#" + t;
    vector<int> pf;
    pf.resize(n + m + 1);
    pref(s, pf);
    //for (int i = 0; i < pf.size(); i++) cout << pf[i] << " ";
    //cout << endl;
    vector<int> answer;
    for (int i = 1; i < n + 1; i++) {
        if (pf[m + i + 1] == m) answer.push_back(i);
    }
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++) cout << answer[i] - (m - 1) + 1 << " ";
    return 0;
}
