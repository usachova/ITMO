#include <iostream>
#include <cstdio>
#include <utility>

using namespace std;

int main()
{
  //freopen("antiqs.in", "r", stdin);
  //freopen("antiqs.out", "w", stdout);
  int n;
  cin >> n;  
  long mas[n];
  for (int i = 0; i < n; i++) {
    mas[i] = i + 1;
  }
  for (int i = 1; i < n; i++) {
  	swap(mas[i], mas[i / 2]);
  }
  for (int i = 0; i < n; i++) {
  	cout << mas[i] << " ";
  }
  fclose(stdin);
  fclose(stdout);
}

