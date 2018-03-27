#include <bits/stdc++.h>

using namespace std;

void reverser(int *v, int a, int b){
  if(a < b){
    swap(v[a], v[b]);
    reverser(v, a + 1, b - 1);
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
  reverser(v, 0, n - 1);
  for(int i = 0; i < n; i++){
    printf("%d ", v[i]);
  }
  puts("");
  return 0;
}
