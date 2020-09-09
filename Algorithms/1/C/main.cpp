#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  freopen("turtle.in", "r", stdin);
  freopen("turtle.out", "w", stdout);
  int h, w;
  cin >> h >> w;
  int mas[h][w];
  for (int i = 0; i < h; i++) 
    for (int j = 0; j < w; j++) {
	  cin >> mas[i][j];
	}
  for (int i = h - 1; i >= 0; i--) 
    for (int j = 0; j < w; j++) {
	  if (j == 0 && i < h - 1) mas[i][j] += mas[i + 1][j];
	  else if (i == h - 1 && j > 0) mas[i][j] += mas[i][j - 1];
	  else if (i != h - 1 && j != 0) mas[i][j] += max(mas[i + 1][j], mas[i][j - 1]);
	}
  cout << mas[0][w - 1];
  fclose(stdin);
  fclose(stdout);
}
