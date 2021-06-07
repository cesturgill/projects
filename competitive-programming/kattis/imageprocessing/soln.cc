#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::reverse;

typedef vector< int > vi;
typedef vector< vi > vvi;

int main() {
  int iheight;
  int iwidth;
  int kheight;
  int kwidth;

  cin >> iheight >> iwidth >> kheight >> kwidth;

  vvi image(iheight, vi(iwidth));
  vvi kernel(kheight, vi(kwidth));

  for (int i = 0; i < iheight; ++i) {
    for (int j = 0; j < iwidth; ++j) {
      cin >> image [i][j];
    }
  }
  for (int k = kheight - 1; k >= 0; --k) {
    for (int l = kwidth - 1; l >= 0; --l) {
      cin >> kernel [k][l];
    }
  }

  int bheight = iheight - kheight + 1;
  int bwidth = iwidth - kwidth + 1;
  vvi blur(bheight, vi(bwidth));
  for (int m = 0; m < bheight; ++m) {
    for (int n = 0; n < bwidth; ++n) {
      int sum = 0;
      for (int o = 0; o < kheight; ++o) {
	for (int p = 0; p < kwidth; ++p) {
	  sum += kernel [o][p] * image [m+o][n+p];
	}
      }
      blur [m][n] = sum;
    }
  }
  for (int q = 0; q < bheight; ++q) {
    for (int r = 0; r < bwidth; ++r) {
      cout << blur [q][r];
      if (r != bwidth - 1)
	cout << " ";
    }
    cout << endl;
  }
  
  return 0;
}
