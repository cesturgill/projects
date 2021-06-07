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
  for( int i = 0; i < cases; ++i ) {
    int weight;
    vi weightBase3;
    vi left;
    vi right;
    cin >> weight;

    //Convert the weight to base 3, stored as a vector of ints

    /**
    int currentweight = 1;
    while( weight != 0 ) {
      int d = weight % 3;
      if( d == 1 ) {
	right.push_back(currentweight);
      } else if( d == 2 ) {
	//Can't have 2 of the same weight on the right hand side, so we add
	//a weight to the left and carry on the right
	left.push_back(currentweight);
	weight += 3;
      }

      currentweight *= 3;
      weight = weight / 3;
    }
    **/
    
    for( int j = 1; j <= pow(3, 18); j*=3 ) {
      if( weight >= j ) {
	int digit = (weight % (j*3)) / j;
	weightBase3.push_back(digit);
      }
    }

    //Calculate the right and left hand sides
    for( int h = 0; h < weightBase3.size(); ++h ) {
      if( weightBase3[h] == 1 ) {
	right.push_back(pow(3, h));
      } else if( weightBase3[h] == 2 || weightBase3[h] == 3 ) {
	//Can't have 2 of the same weight on the right hand side, so we add
	//a weight to the left and carry on the right
	if( h == weightBase3.size() - 1 ) {
	  weightBase3.push_back(1);
	} else {
	  weightBase3[h+1] += 1;
	}
	if( weightBase3[h] == 2 ) {
	  left.push_back(pow(3, h));
	}
      }
    }
    
    //Reverse the vectors so the larger weights are first
    reverse(right.begin(), right.end());
    reverse(left.begin(), left.end());

    //Output the results
    cout << "left pan:";
    for( int l = 0; l < left.size(); ++l ) {
      cout << " " << left[l];
    }
    cout << "\n";

    cout << "right pan:";
    for( int r = 0; r < right.size(); ++r ) {
      cout << " " << right[r];
    }
    cout << "\n";

    if( i < cases - 1 ) {
      cout << "\n";
    }
  }
}
