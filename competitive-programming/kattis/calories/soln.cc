#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

int main() {
  string line;
  while (getline (cin, line) && line != "-") {
    double totalcal = 0;
    double fatcal = 0;
    do{
      //cout << line << endl;
      stringstream input(line);
      vi num(5);
      vector<char> form(5);
      int cper[5] = {9, 4, 4, 4, 7};
      double itemcal = 0;
      int itempercent = 0;;
      string current;
      for (int i = 0; i < 5; ++i) {
	input >> current;
        form[i] = current[current.length() - 1];
	num[i] = stoi(current.substr(0, current.length() - 1));
	if (form[i] == 'C')
	  itemcal += num[i];
	else if (form[i] == 'g')
	  itemcal += num[i] * cper[i];
	else if (form[i] == '%')
	  itempercent += num[i];
      }
      if(itempercent != 0)
	itemcal = itemcal / ((100 - itempercent) * 0.01);
      totalcal += itemcal;
      if(form[0] == '%')
	fatcal += itemcal * num[0] * 0.01;
      else if (form[0] == 'g')
	fatcal += num[0] * cper[0];
      else
	fatcal += num[0];
    } while (getline (cin, line) && line != "-");
    cout << round(fatcal / totalcal * 100) << "%" << endl;
  }
  return 0;
}
