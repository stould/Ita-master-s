#include <bits/stdc++.h>

using namespace std;

int getMax(int *v, int n, int pos){
  if(n - 1 == pos){
    return v[pos];
  }else{
    return max(v[pos], getMax(v, n, pos + 1));
  }
}

int main(){
  srand(time(NULL));
  int n = 10;
  int *v = (int *) malloc(sizeof(int) * n);
  for(int i = 0; i < n; i++){
    v[i] = rand() % 1000;
    printf("%d ", v[i]);
  }
  puts("");
  printf("Max = %d\n", getMax(v, n, 0));
  return 0;
}
