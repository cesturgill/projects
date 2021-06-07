#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

int main() {
  string can;
  string need;
  cin >> can;
  cin >> need;
  if (can.length() >= need.length())
    cout << "go" << endl;
  else
    cout << "no" << endl;
}
