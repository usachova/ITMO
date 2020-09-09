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
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    string t;
    cin >> t;
    int n = t.length();
    vector<int> pf;
    pf.resize(n);
    pref(t, pf);
    for (int i = 0; i < pf.size(); i++) cout << pf[i] << " ";
    return 0;
}
