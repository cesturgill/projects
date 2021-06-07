#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int, int > ii;
typedef vector< ii > vii;

int main() {
  int mr[]{0, 0, 1, -1};
  int mc[]{1, -1, 0, 0};
  int cases;
  cin >> cases;
  for (int cas = 0; cas < cases; ++cas) {
    vector< vector< char > > map;
    int width, height;
    vii fire;
    vii loc;
    cin >> width;
    cin >> height;
    map = vector< vector< char > >(height, vector< char >(width));
    for (int r = 0; r < height; ++r) {
      for (int c = 0; c < width; ++c) {
	cin >> map[r][c];
	if (map[r][c] == '*')
	  fire.push_back(ii(r, c));
	if (map[r][c] == '@')
	  loc.push_back(ii(r, c));
      }
    }

    int seconds = 0;
    bool escaped = false;
    while (escaped == false && loc.size() != 0) {
      vii temp;
      for (int f = 0; f < fire.size(); ++f) {
	for (int m = 0; m < 4; ++m) {
	  int nr = fire[f].first + mr[m];
	  int nc = fire[f].second + mc[m];
	  if (nr > -1 && nr < height && nc > -1 && nc < width &&
	      (map[nr][nc] == '.' || map[nr][nc] == '@')) {
	    temp.push_back(ii(nr, nc));
	    map[nr][nc] = '*';
	  }
	}
      }
      fire = temp;
      temp.clear();
    
    for (int l = 0; l < loc.size(); ++l) {
	for (int n = 0; n < 4; ++n) {
	  int nr = loc[l].first + mr[n];
	  int nc = loc[l].second + mc[n];
	  if (nr < 0 || nr >= height || nc < 0 || nc >= width) {
	      escaped = true;
	    } else if (map[nr][nc] == '.') {
	      temp.push_back(ii(nr, nc));
	      map[nr][nc] = '@';
	    }
	 }
      }
      loc = temp;
      temp.clear();
      seconds ++;
    }
    if (escaped == true)
      cout << seconds << endl;
    else
      cout << "IMPOSSIBLE" << endl;
  }
  
  return 0;
}
