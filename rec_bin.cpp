#include <bits/stdc++.h>

using namespace std;

void toBin(int n){
  if(n > 0){
    toBin(n / 2);
    printf("%d", n % 2);
  }
}

int main(){
  int n = 0;
  if(n == 0) printf("0\n");
  else toBin(n);
  return 0;
}
