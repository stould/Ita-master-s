#include <bits/stdc++.h>

using namespace std;

void print(int n){
  if(n > 0){
    printf("%d ", n - 1);
    print(n - 1);
  }
}

int main(){
  print(10);
  printf("\n");
  return 0;
}
