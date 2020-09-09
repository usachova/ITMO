#include <iostream>
#include <fstream>
#include <cstdio>
#include <utility>

using namespace std;

int main()
{
  ifstream in;
  ofstream out;
  in.open("sortland.in");
  out.open("sortland.out");
  int n, j;
  pair< float, int > key;
  in >> n;
  pair< float, int > mas[n];
  for (int i = 0; i < n; i++) {
	mas[i].second = i;
    in >> mas[i].first;
  }
  for (int i = 0; i < n; i++) {
    key = mas[i];
    j = i - 1;
    while (j >= 0 && mas[j] > key) {
        mas[j + 1] = mas[j];
        mas[j] = key;
        j--;
    }
  }
  out << mas[0].second + 1 << " " << mas[n / 2].second + 1 << " " << mas[n - 1].second + 1;
  in.close();
  out.close();
}
