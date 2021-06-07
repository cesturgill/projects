#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vector < double > > vvd;

int main() {
  int k;
  int n;
  int e;
  cin >> k >> n >> e;
  while (k != 0 || n != 0 || e != 0) {
    int v = 1 << n ;
    vvi edges(v);
    int v1;
    int v2;
    for (int i = 0; i < e; ++i) {
      cin >> v1;
      cin >> v2;
      edges[v1].push_back(v2);
      edges[v2].push_back(v1);
    }
    vvd probs(k, vector<double>(v));
    bool isValid = true;
    for (int j = 0; j < v; ++j) {
      probs[0][j] = 1.0 / v;
    }
    for (int l = 1; l < k; ++l) {
      for (int m = 0; m < v; ++m) {
	for (int o = 0; o < edges[m].size(); ++o) {
	  probs[l][edges[m][o]] += probs[l-1][m] / edges[m].size();
	}
      }
      vector <double> pOne(n);
      for (int p = 0; p < v; ++p) {
	for (int q = 0; q < n; ++q) {
	  if (p & 1 << q)
	    pOne [q] += probs [l][p];
	}
      }
      for (int r = 0; r < n; ++r) {
	if (pOne[r] < 0.25 || pOne[r] > 0.75)
	  isValid = false;
      }
    }
    if (isValid == true)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    cin >> k >> n >> e;
  }
  return 0;
}
