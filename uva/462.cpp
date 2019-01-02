//caesar stefanus
//uva 462
//Bridge Hand Evaluator
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  char rank[15], suit[15];
  while(scanf("%c%c", &rank[0], &suit[0]) != EOF) {
    getchar();
    for(int i = 1; i < 13; ++i) {
      scanf("%c%c", &rank[i], &suit[i]);
      getchar();
    }
    int score = 0;
    string spades = "";
    string hearts = "";
    string diamonds = "";
    string clubs = "";

    bool stops = false;
    bool stoph = false;
    bool stopd = false;
    bool stopc = false;
    bool notrump = false;

    for(int i = 0; i < 13; ++i) {
      if(rank[i] == 'A') {
        score += 4;
        if(suit[i] == 'S') stops = true;
        if(suit[i] == 'H') stoph = true;
        if(suit[i] == 'D') stopd = true;
        if(suit[i] == 'C') stopc = true;
      }
      if(rank[i] == 'K') {
        score += 3;
      }
      if(rank[i] == 'Q') {
        score += 2;
      }
      if(rank[i] == 'J') {
        ++score;
      }
      if(suit[i] == 'S') spades += rank[i];
      if(suit[i] == 'H') hearts += rank[i];
      if(suit[i] == 'D') diamonds += rank[i];
      if(suit[i] == 'C') clubs += rank[i];
    }
    //cout << score << endl;
    int slen = spades.length();
    int hlen = hearts.length();
    int dlen = diamonds.length();
    int clen = clubs.length();

    //king
    if(slen == 1 && spades[0] == 'K') --score;
    if(hlen == 1 && hearts[0] == 'K') --score;
    if(dlen == 1 && diamonds[0] == 'K') --score;
    if(clen == 1 && clubs[0] == 'K') --score;
    //stop king
    if(slen >= 2 && spades.find('K') != string::npos) stops = true;
    if(hlen >= 2 && hearts.find('K') != string::npos) stoph = true;
    if(dlen >= 2 && diamonds.find('K') != string::npos) stopd = true;
    if(clen >= 2 && clubs.find('K') != string::npos) stopc = true;
    //queen
    if(slen == 1 && spades[0] == 'Q') --score;
    if(hlen == 1 && hearts[0] == 'Q') --score;
    if(dlen == 1 && diamonds[0] == 'Q') --score;
    if(clen == 1 && clubs[0] == 'Q') --score;

    if(slen == 2 && (spades[0] == 'Q' || spades[1] == 'Q')) --score;
    if(hlen == 2 && (hearts[0] == 'Q' || hearts[1] == 'Q')) --score;
    if(dlen == 2 && (diamonds[0] == 'Q' || diamonds[1] == 'Q')) --score;
    if(clen == 2 && (clubs[0] == 'Q' || clubs[1] == 'Q')) --score;
    //stop queen
    if(slen >= 3 && spades.find('Q') != string::npos) stops = true;
    if(hlen >= 3 && hearts.find('Q') != string::npos) stoph = true;
    if(dlen >= 3 && diamonds.find('Q') != string::npos) stopd = true;
    if(clen >= 3 && clubs.find('Q') != string::npos) stopc = true;
    //jack
    if(slen == 1 && spades[0] == 'J') --score;
    if(hlen == 1 && hearts[0] == 'J') --score;
    if(dlen == 1 && diamonds[0] == 'J') --score;
    if(clen == 1 && clubs[0] == 'J') --score;

    if(slen == 2 && (spades[0] == 'J' || spades[1] == 'J')) --score;
    if(hlen == 2 && (hearts[0] == 'J' || hearts[1] == 'J')) --score;
    if(dlen == 2 && (diamonds[0] == 'J' || diamonds[1] == 'J')) --score;
    if(clen == 2 && (clubs[0] == 'J' || clubs[1] == 'J')) --score;

    if(slen == 3 && (spades[0] == 'J' || spades[1] == 'J' || spades[2] == 'J')) --score;
    if(hlen == 3 && (hearts[0] == 'J' || hearts[1] == 'J' || hearts[2] == 'J')) --score;
    if(dlen == 3 && (diamonds[0] == 'J' || diamonds[1] == 'J' || diamonds[2] == 'J')) --score;
    if(clen == 3 && (clubs[0] == 'J' || clubs[1] == 'J' || clubs[2] == 'J')) --score;

    if(score >= 16 && stops && stoph && stopd && stopc) notrump = true;
    //cout << score << endl;
    //rule 5
    if(slen == 2) ++score;
    if(hlen == 2) ++score;
    if(dlen == 2) ++score;
    if(clen == 2) ++score;
    //rule 6
    if(slen == 1) score += 2;
    if(hlen == 1) score += 2;
    if(dlen == 1) score += 2;
    if(clen == 1) score += 2;
    //rule 7
    if(slen == 0) score += 2;
    if(hlen == 0) score += 2;
    if(dlen == 0) score += 2;
    if(clen == 0) score += 2;

    //printf("%d\n", score);
    if(score < 14) {
      printf("PASS\n");
    }
    else {
      if(notrump) printf("BID NO-TRUMP\n");
      else {
        int maxlen = max(slen, max(hlen, max(dlen, clen)));
        if(maxlen == slen) printf("BID S\n");
        else {
          if(maxlen == hlen) printf("BID H\n");
          else {
            if(maxlen == dlen) printf("BID D\n");
            else printf("BID C\n");
          }
        }
      }
    }
  }
}
