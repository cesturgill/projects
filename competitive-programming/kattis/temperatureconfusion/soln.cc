#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

int gcd(int a, int b);

int main() {
  int num, den;
  scanf("%d/%d", &num, &den);
  num -= 32 * den;
  num *= 5;
  den *= 9;
  int div;
  if(abs(num) > abs(den))
    div = gcd(abs(num), abs(den));
  else
    div = gcd(abs(den), abs(num));
  num /= div;
  den /= div;
  printf("%d/%d\n", num, den);
  
  return 0;
}

int gcd(int a, int b) {
  while (b > 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
