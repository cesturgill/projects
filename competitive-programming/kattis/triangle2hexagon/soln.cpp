#include <cmath>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Point {
  Point( double xv = 0, double yv = 0 ) { x = xv; y = yv; }

  Point operator+( Point p ) const { return Point( x + p.x, y + p.y ); }

  Point operator-( Point p ) const { return Point( x - p.x, y - p.y ); }

  Point operator*( double s ) const { return Point( x * s, y * s ); }

  // Vector dot product.
  double operator*( Point p ) const { return x * p.x + y * p.y; }

  // Vector cross product, if the X axis points right and Y points up,
  // will return positive if p is a left turn compred to this Vector
  double cross( Point p ) const { return x * p.y - y * p.x; }

  // Return the magnitude of this vector.
  double mag() const { return sqrt( x * x + y * y ); }

  // Return a unit-length vector pointing in the same direction.
  Point unit() const { return operator*( 1 / mag() ); }

  // Return a new vector that is perpendicular to this one, (rotated 90
  // counter-clockwise if X points right and Y points up)
  Point perp() const { return Point( -y, x ); }

  // Get the angle of this vector from horizontal, in radians between `$-\pi$`
  // and `$\pi$`. Positive is in the counter-clockwise direction.
  double angle() const { return atan2(y, x); }

  // This is a struct, so you are free to use these fields directly.
  double x, y;
};

// Free operator for double * Point
inline Point operator*( double s, Point const &p ) { return p * s; }

Point intersect (Point p1, Point p2, Point p3, Point p4);
Point circintersect (Point p1, Point v1, Point ctr, double r);

typedef vector< Point > vp;

typedef pair< int, int > ii;
typedef vector< int > vi;
typedef vector< vi > vvi;

// typedef vector< ii > vii;
// typedef vector< vii > vvii;
// typedef vector< double > vd;
// typedef vector< vd > vvd;

Point A, B, C;

int main() {
  double xin;
  double yin;
  cin >> B.x >> C.x >> C.y;
  Point AB = (A + B) * 0.5;
  Point BC = (B + C) * 0.5;
  Point ABV = (A - B).perp();
  Point BCV = (B - C).perp();
  Point O = intersect(AB, ABV, BC, BCV);
  Point Abi = ((B-A).unit() + (C-A).unit()) * 0.5;
  Point Bbi = ((A-B).unit() + (C-B).unit()) * 0.5;
  Point Cbi = ((A-C).unit() + (B-C).unit()) * 0.5;
  Point M = circintersect(A, Abi, O, (A-O).mag());
  Point N = circintersect(B, Bbi, O, (A-O).mag());
  Point P = circintersect(C, Cbi, O, (A-O).mag());
  Point G = intersect(A, C-A, N, M-N);
  Point H = intersect(B, C-B, N, M-N);
  Point J = intersect(B, C-B, M, P-M);
  Point K = intersect(B, A-B, M, P-M);
  Point E = intersect(B, A-B, N, P-N);
  Point F = intersect(A, C-A, N, P-N);
  printf("%f %f %f %f %f %f\n", abs((E-F).mag()), abs((F-G).mag()),
	 abs((G-H).mag()), abs((H-J).mag()), abs((J-K).mag()),
	 abs((K-E).mag()));
  
  return 0;
}

Point intersect (Point p1, Point v1, Point p2, Point v2) {
  double t = ((p2-p1)*v2.perp())/(v1*v2.perp());
  return (p1+t*v1);
}

Point circintersect (Point p1, Point v1, Point ctr, double r) {
  p1 = p1 - ctr;
  double A = v1*v1;
  double B = p1*v1*2;
  double C = p1*p1 - r*r;
  double t = (-B + sqrt(B*B - 4*A*C))/(2*A);
  return (p1+ctr)+t*v1;
}
