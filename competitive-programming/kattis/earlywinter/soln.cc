#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

int main() {
  int years;
  int gap;
  int current;
  int total = 0;
  cin >> years;
  cin >> gap;
  for(int i = 0; i < years;  ++i) {
    cin >> current;
    if(current > gap)
      ++total;
    else
      break;
  }
  if(total == years)
    cout << "It had never snowed this early!" << endl;
  else
    cout << "It hadn't snowed this early in " << total << " years!" << endl;
  return 0;
}
