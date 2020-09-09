#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
  ifstream in;
  ofstream out;
  in.open("smallsort.in");
  out.open("smallsort.out");
  int n, key, j;
  in >> n;
  int mas[n];
  for (int i = 0; i < n; i++) {
    in >> mas[i];  
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
  for (int i = 0; i < n; i++) {
    out << mas[i] << ' ';  
  }
  in.close();
  out.close();
}
