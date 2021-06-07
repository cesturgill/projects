#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

int main() {
  int need;
  cin >> need;
  int lowest = need;
  for (double i = 1; pow(2,i) <= need; ++i) {
    int possible = i + ceil(need / pow(2,i));
    if (possible < lowest)
      lowest = possible;
  }
  cout << lowest << endl;
  return 0;
}
