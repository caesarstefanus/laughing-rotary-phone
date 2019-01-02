#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

#define epsilon 0.0001
#define pi 3.14159265

int main() {
  double l;
  while(scanf("%lf", &l)) {
    if(l < epsilon) break;
    double r = l / pi;
    printf("%.2lf\n", pi * r * r * 0.50);
  }
  return 0;
}
