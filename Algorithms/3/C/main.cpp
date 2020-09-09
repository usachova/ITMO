#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  freopen("isheap.in", "r", stdin);
  freopen("isheap.out", "w", stdout);
  int n;
  cin >> n;  
  int mas[n];
  for (int i = 0; i < n; i++) {
    cin >> mas[i];
  }
  int flag = 0; 
  for (int i = 1; i <= n; i++) {
  	if (2 * i <= n && mas[i - 1] > mas[2 * i - 1]) {
  		flag = 1;
  		break;
	}
	if (2 * i + 1 <= n && mas[i - 1] > mas[2 * i]) {
  		flag = 1;
  		break;
	}
  }
  if (flag == 0) cout << "YES";
  else cout << "NO";
  fclose(stdin);
  fclose(stdout);
}

