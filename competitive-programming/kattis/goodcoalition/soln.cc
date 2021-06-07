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
    int parties;
    cin >> parties;
    int seats[parties];
    double success[parties];
    for (int par = 0; par < parties; ++par){
      cin >> seats[par];
      cin >> success[par];
      success[par] /= 100.0;
    }
    vector< double > current(151, -1);
    vector< double > next(151, -1);
    current[0] = 1;
    for (int i = 0; i < parties; ++i) {
      for (int j = 0; j < 151; ++j) {
	if (j - seats[i] >= 0 && current[j-seats[i]] * success[i] > current[j])
	  next[j] = current[j-seats[i]] * success[i];
	else
	  next[j] = current[j];
      }
      current = next;
    }
    double highest = -1;
    for (int k = 76; k <= 150; ++k) {
      if (current[k] > highest)
	highest = current[k];
    }
    highest *= 100;
    printf("%f\n", highest);
  }
  return 0;
}
