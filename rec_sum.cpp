#include <bits/stdc++.h>

using namespace std;

int sum(int *v, int n){
  if(n == 0){
    return v[0];
  }else{
    return v[n] + sum(v, n - 1);
  }
}

int main(){
  srand(time(NULL));
  int n = 10;
  int *v = (int *) malloc(sizeof(int) * n);
  for(int i = 0; i < n; i++){
    v[i] = rand() % 10;
    printf("%d ", v[i]);
  }
  puts("");
  printf("Sum is %d\n", sum(v, n - 1));
  return 0;
}
