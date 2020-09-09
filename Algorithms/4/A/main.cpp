#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	//freopen("stack.in", "r", stdin);
    //freopen("stack.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int mas[n];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	char ch;
    	cin >> ch;
    	if (ch == '+') {
    		cin >> mas[cnt];
    		cnt++;
		}
		else {
			cnt--;
			cout << mas[cnt] << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
