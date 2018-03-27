#include <bits/stdc++.h>

using namespace std;

bool find(int *v, int n, int pos, int key){
  if(n - 1 == pos){
    return v[pos] == key;
  }else{
    return (v[pos] == key) || find(v, n, pos + 1, key);
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
  printf("Key found? %d\n", find(v, n, 0, 3));
  return 0;
}
