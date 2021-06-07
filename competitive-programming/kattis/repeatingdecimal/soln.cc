#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

int main() {
  int a, b, c;
  while (cin >> a) {
    cin >> b;
    cin >> c;
    string output = "0.";
    for (int i = 0; i < c; ++i) {
    int div = a * 10 / b;
    output += (div + 48);
    a = a * 10 % b;
    }
    cout << output << endl;;
  }
  return 0;
}
