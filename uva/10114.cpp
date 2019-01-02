//caesar stefanus
//uva 10114
//loansome car buyer

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define EPSILON 0.00001

int main() {
  double month, dp, amount, num;

  while(scanf("%lf %lf %lf %lf", &month, &dp, &amount, &num)) {
    if(month < 0) break;
    double rates[111];
    for(int i = 0; i <= month; ++i) rates[i] = 0.00;
    for(int i = 0; i < num; ++i) {
      int start;
      double rate;
      scanf("%d %lf", &start, &rate);
      rates[start] = rate;
    }
    for(int i = 1; i <= month; ++i)
      if(rates[i] < EPSILON) rates[i] = rates[i - 1];
    double owes = amount;
    double worth = (amount + dp) * (1.00 - rates[0]);
    int ans = 0;

    while(owes - worth >= EPSILON) {
      owes -= amount / month;
      worth *= (1.00 - rates[++ans]);
    }

    printf("%d month", ans);
    if(ans != 1) printf("s");
    printf("\n");
  }
  return 0;
}
