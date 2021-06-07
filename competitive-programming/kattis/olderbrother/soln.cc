#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

vi getPrimeFactors(int num);

int main() {
  int q;
  cin >> q;
  vi factors = getPrimeFactors(q);
  if (q == 1) {
    cout << "no" << endl;
  } else if (factors.size() == 1) {
    cout << "yes" << endl;
  } else {
    bool power = true;
    for (int i = 1; i < factors.size(); ++i) {
      if (factors[i] != factors[i-1]) {
	power = false;
      }
    }
    if (power == true)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}

vi getPrimeFactors(int num) {
  vi factors;
  for (int i = 2; i * i <= num; ++i) {
    while (num % i == 0) {
      factors.push_back(i);
      num = num / i;
    }
  }
  if (num != 1) {
    factors.push_back(num);
  }
  return factors;
}
