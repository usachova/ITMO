#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
  ifstream in;
  ofstream out;
  in.open("aplusb.in");
  out.open("aplusb.out");
  int a, b;
  in >> a >> b;
  out << a + b;
  in.close();
  out.close();
}