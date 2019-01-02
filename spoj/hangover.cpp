#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double c;
  while(scanf("%lf", &c)) {
    if(c < 0.001) break;
    double n = 0.0;
    double len = 0.0;
    while(len < c) {
      n = n + 1.0;
      len += 1.0 / (n + 1.0);
    }
    printf("%.0lf card(s)\n", n);
  }
  return 0;
}
