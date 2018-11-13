// soluzione al problema:  POT, da COCI 2015-16, round 3, task 1 
#include<cassert>
#include<iostream>

using namespace std;

int mypow(int base, int exp) {
  assert(exp >= 0);
  if(exp == 0)  return 1;
  return base * mypow(base, exp-1);
}

int main() {
  int n; cin >> n;
  int risp = 0, val;
  for(int i = 1; i<=n; i++) {
    cin >> val;
    risp += mypow(val/10 , val % 10);
  }
  cout << risp << endl;
  return 0;
}
