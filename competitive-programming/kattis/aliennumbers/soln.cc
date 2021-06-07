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
  int cases;
  cin >> cases;
  for (int cas = 0; cas < cases; ++cas) {
    string num, base1, base2;
    cin >> num >> base1 >> base2;
    long dec = 0;
    long pv = 1;
    for (int i = 0; i < num.length(); ++i) {
      char val = num[num.length() - 1 - i];
      int pos;
      for (int j = 0; j < base1.length(); ++j) {
	if (base1[j] == val)
	  pos = j;
      }
      dec += pv * pos;
      pv *= base1.length();
    }
    string fin;
    if (dec == 0) {
      fin = base2[0];
    } else {
      while (dec > 0) {
	int next = dec % base2.length();
	fin += base2[next];
	dec = dec / base2.length();
      }
      reverse(fin.begin(), fin.end());
    }
    cout << "Case #" << cas + 1 << ": " << fin << endl;
  }
  
  return 0;
}
