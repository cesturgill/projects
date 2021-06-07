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
    int digits, high0, high1, next0, next1;
    cin >> digits;
    high0 = 1;
    high1 = 1;
    for (int i = 1; i < digits; ++i) {
      next1 = high0;
      next0 = high0 + high1;
      high0 = next0 % (1000000000 + 7);
      high1 = next1 % (1000000000 + 7);
    }
    cout << (high1 + high0) % (1000000000 + 7) << endl;
  }
  return 0;
}
