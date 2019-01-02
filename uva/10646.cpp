//caesar stefanus
//uva 10646
//What is the Card?
#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

struct cards {
  int value;
  char rank;
  char suit;
};

int main() {
  int TC;
  scanf("%d", &TC);
  for(int tc = 1; tc <= TC; ++tc) {
    stack<cards> pile;
    while(!pile.empty()) pile.pop();

    for(int i = 0; i < 52 - 25; ++i) {
      getchar();
      char temp1, temp2;
      scanf("%c%c", &temp1, &temp2);
      cards temp;
      temp.value = ('2' <= temp1 && temp1 <= '9') ? temp1 - '0' : 10;
      temp.rank = temp1;
      temp.suit = temp2;
      pile.push(temp);
      //printf("%d -> %c%c\n", i, pile[i].value, pile[i].suit);
    }

    vector<cards> hand; hand.clear();

    for(int i = 0; i < 25; ++i) {
      getchar();
      char temp1, temp2;
      scanf("%c%c", &temp1, &temp2);
      cards temp;
      temp.value = ('2' <= temp1 && temp1 <= '9') ? temp1 - '0' : 10;
      temp.rank = temp1;
      temp.suit = temp2;
      hand.push_back(temp);
      //printf("%d -> %c%c\n", i, pile[i].value, pile[i].suit);
    }

    int y = 0;
    for(int i = 0; i < 3; ++i) {
      cards topcard = pile.top();
      int x = topcard.value;
      y += x;
      pile.pop();
      for(int j = 0; j < 10 - x; ++j) pile.pop();
    }

    for(int i = 0; i < 25; ++i) pile.push(hand[i]);

    stack<cards> answer;
    while(!answer.empty()) answer.pop();

    while(!pile.empty()) {
      answer.push(pile.top());
      pile.pop();
    }

    for(int i = 1; i < y; ++i) answer.pop();
    printf("Case %d: %c%c\n", tc, answer.top().rank, answer.top().suit);
  }
  return 0;
}
