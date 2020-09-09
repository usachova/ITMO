#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int mas[n];
    int head = 0, tail = 0;
    for (int i = 0; i < n; i++) {
    	char ch;
    	cin >> ch;
    	if (ch == '+') {
    		cin >> mas[tail];
    		tail++;
		}
		else {
			cout << mas[head] << endl;
			head++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
