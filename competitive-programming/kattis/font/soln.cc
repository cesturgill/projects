#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

vi words;

int combinations(int included, int current);

int main() {
  int wordnum;
  cin >> wordnum;
  words = vi(wordnum);
  string current;
  int letters;
  for (int i = 0; i < wordnum; ++i) {
    cin >> current;
    letters = current.length();
    for (int j = 0; j < letters; ++j) {
      words[i] = words[i]|(1<<(current[j] - 'a'));
    }
  }
  int include = 0;
  cout << combinations(include, 0) << endl;
  
  return 0;
}

int combinations(int included, int current) {
  if(current == words.size()) {
    if(included == ((1<<26)-1))
      return 1;
    else
      return 0;
  } else {
    int valid = combinations(included, current + 1);
    valid += combinations(included|words[current], current + 1);
    return valid;
  }
}
