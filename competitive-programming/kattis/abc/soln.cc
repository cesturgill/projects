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
  vi numbers(3);
  string letters;
  for (int i = 0; i < 3; ++i)
    cin >> numbers[i];
  cin >> letters;
  sort(numbers.begin(), numbers.end());
  for (int j = 0; j < 3; ++j) {
    switch (letters[j]) {
    case 'A' :
      cout << numbers[0] << " ";
      break;
    case 'B' :
      cout << numbers[1] << " ";
      break;
    case 'C':
      cout << numbers[2] << " ";
      break;
    }
  }
  cout << endl;
  return 0;
}
