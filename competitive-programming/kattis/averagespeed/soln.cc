#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

int main() {
  string input;
  int speed = 0;
  double distance = 0;
  int elapsed;
  while (getline(cin, input)) {
    int h, m, s, newSpeed;
    int matches = sscanf( input.c_str(), "%d:%d:%d %d", &h, &m, &s, &newSpeed );
    int secs = h * 3600 + m * 60 + s - elapsed;
    elapsed = h * 3600 + m * 60 + s;
    distance += speed * secs / 3600.0;
    if( matches == 4 ) {
      speed = newSpeed;
    } else {
      printf("%02d:%02d:%02d %.2f km\n", h, m, s, distance);
    }
    
  }
  return 0;
}
