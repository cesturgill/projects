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
  while ( cin >> cases && cases != 0 ) {
    double maxc = 1000;
    double maxa = 0;
    double cpera;
    for (int i = 0; i < cases; ++i) {
      cin >> cpera;
      double temp = maxc;
      if (maxc < maxa * cpera * 0.97) {
	maxc = maxa * cpera * 0.97;
	maxc = floor(maxc * 100) / 100;
      }
      if (maxa < temp / cpera * 0.97) {
	maxa = temp / cpera * 0.97;
	maxa = floor(maxa * 100) / 100;
      }
    }
    printf("%.2f\n", maxc);
  }
}
