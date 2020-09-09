#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main() {
  freopen("garland.in", "r", stdin);
  freopen("garland.out", "w", stdout);
  int n;
  cin >> n;
  double mas[n];
  cin >> mas[0];
  double up = mas[0], l = 0;
  while (up - l > 0.0000001) {
  	mas[1] = (l + up) / 2;
  	bool flag = true;
  	for (int i = 2; i < n; i++) {
  		mas[i] = 2 * (mas[i - 1] + 1) - mas[i - 2];
  		if (mas[i] < 0) {
  			flag = false;
  			break;
		}
	}
	if (flag) up = mas[1];
	else l = mas[1];
  }
  cout << fixed << setprecision(2) << mas[n - 1];
  fclose(stdin);
  fclose(stdout);
}

