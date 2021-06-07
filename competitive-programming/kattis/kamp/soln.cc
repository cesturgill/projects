#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <tuple>

using namespace std;


typedef tuple <int, int>  ii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector <ii> vii;
typedef vector <vii> vvii;

void dfs1(int root, int parent);
void dfs2(int root, int parent, long pmax, long ptotal);

vvii edges;
vector <bool> kamp;
vector <long> lp;
vector <long> tp;
vector <long> longest;
vector <long> total;
vector <long> mintour;

int main() {
  int n, k;
  cin >> n >> k;
  edges = vvii(n+1);
  lp = vector <long>(n+1, -1);
  tp = vector <long>(n+1, 0);
  longest = vector<long>(n+1, -1);
  total = vector<long>(n+1, 0);
  mintour = vector<long>(n+1, 0);
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back(ii(b, c));
    edges[b].push_back(ii(a, c));
  }
  kamp.assign(n+1, 0);
  for (int j = 0; j < k; ++j) {
    int d;
    cin >> d;
    kamp[d] = 1;
  }
  dfs1(1, 0);
  dfs2(1, 0, -1, 0);
  for(int l = 1; l < n+1; ++l) {
    cout << mintour[l] << endl;
  }
  return 0;
}

void dfs1 (int root, int parent) {
  for (auto e : edges[root]) {
    int j = get<0>(e);
    if (j != parent) {
      dfs1(j, root);
      if (lp[j] != -1) {
	tp[root] += tp[j] + 2*get<1>(e);
	if (lp[j] + get<1>(e) > lp[root]) {
	  lp[root] = lp[j] + get<1>(e);
	}
      }
    }
  }
  if(lp[root] == -1 && kamp[root] == true) {
    lp[root] = 0;
  }
}

void dfs2 (int root, int parent, long pmax, long ptotal) {
  total[root] = tp[root] + ptotal;
  if (pmax > lp[root])
    longest[root] = pmax;
  else
    longest[root] = lp[root];
  mintour[root] = total[root] - longest[root];
  
  for (auto e : edges[root]) {
    if (get<0>(e) != parent) {
      long cmax = pmax;
      long ctotal = ptotal;
      for (auto f : edges[root]) {
        if (f != e && get<0>(f) != parent && lp[get<0>(f)] != -1) {
          ctotal += tp[get<0>(f)] + 2 * get<1>(f);
          if (lp[get<0>(f)] + get<1>(f) > cmax)
	    cmax = lp[get<0>(f)] + get<1>(f);
        }
      }
      if (cmax != -1) {
        cmax += get<1>(e);
        ctotal += 2*get<1>(e);
      } else if (kamp[root] == 1) {
	cmax = get<1>(e);
	ctotal += 2*get<1>(e);
      }
      dfs2(get<0>(e), root, cmax, ctotal);
    }
  }
}
