#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

int main() {
  int cases;
  cin >> cases;
  for (int cas = 0; cas < cases; ++cas) {
    long a, b, c, d, m;
    int n, x, y;
    cin >> n >> a >> b >> c >> d >> x >> y >> m;
    long batch[3][3]= {0};
    int xloc;
    int yloc;
    for (int in = 0; in < n; ++in) {
      xloc = x % 3;
      yloc = y % 3;
      ++batch[xloc][yloc];
      x = (a * x + b) % m;
      y = (c * y + d) % m;
    }
    /*for (int f = 0; f < 3; ++f) {
      for (int s = 0; s < 3; ++s) {
	cout << batch [f][s] << ", ";
      }
      cout << endl;
      }*/
    long total = 0;
    for (int i1 = 0; i1 < 3; ++i1) {
      for (int j1 = 0; j1 < 3; ++j1) {
	for (int i2 = 0; i2 < 3; ++i2) {
	  for (int j2 = 0; j2 < 3; ++ j2) {
	    for (int i3 = 0; i3 < 3; ++i3) {
	      for (int j3 = 0; j3 < 3; ++j3) {
	        if (i1 == i2 && i2 == i3 && j1 == j2 && j2 == j3) {
		  total += batch[i1][j1] * (batch[i1][j1] - 1) * (batch[i1][j1] - 2);
		  //cout << i1 << ", " << j1 << ", " << i2 << ", " << j2 << ", "
		  //<< i3 << ", " << j3 << ", " << total << endl;
	        } else if ((i1 != i2 && i2 != i3 && i1 != i3 && j1 == j2 && j2 == j3) ||
			   (j1 != j2 && j2 != j3 && j1 != j3 && i1 == i2 && i2 == i3)) {
		  total += batch [i1][j1] * batch [i2][j2] * batch [i3][j3];
		  //cout << i1 << ", " << j1 << ", " << i2 << ", " << j2 << ", "
		  //<< i3 << ", " << j3 << ", " << total << endl;
	        } else if ((i1 != i2 && i2 != i3 && i1 != i3) &&
			   (j1 != j2 && j2 != j3 && j1 != j3)) {
		  total += batch [i1][j1] * batch [i2][j2] * batch [i3][j3];
		  //cout << i1 << ", " << j1 << ", " << i2 << ", " << j2 << ", "
		  //<< i3 << ", " << j3 << ", " << total << endl;
		}
	      }
	    }
	  }
	}
      }
    }
    total /= 6;
    cout << "Case #" << (cas + 1) << ": " << total << endl;
  }
  return 0;
}
