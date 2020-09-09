#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> alf = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

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
    int n;
    cin >> n;
    string p;
    cin >> p;
    int m = p.length();
    vector<int> pf;
    pf.resize(m);
    pref(p, pf);
    int sig[m + 1][n];
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n; j++) {
            char a = alf[j];
            if (i > 0 && a != p[i]) sig[i][j] = sig[pf[i - 1]][j];
            else {
                if (a == p[i]) sig[i][j] = i + 1;
                else sig[i][j] = i;
            }
        }
    }
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n; j++) {
            cout << sig[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
