#include <bits/stdc++.h>

using namespace std;

bool find(int *v, int l, int r, int key){
  if(l > r){
    return false;
  }else{
    int mid = l + (r - l) / 2;
    if(v[mid] > key){
      return find(v, l, mid - 1, key);
    }else if(v[mid] < key){
      return find(v, mid + 1, r, key);
    }else{
      return true;
    }
  }
}

int main(){
  srand(time(NULL));
  int n = 15;
  int *v = (int *) malloc(sizeof(int) * n);
  v[0] = rand() % 50;
  
  for(int i = 1; i < n; i++){
    v[i] = v[i - 1] + rand() % 6 + 1;
  }

  for(int i = 0; i < n; i++){
    printf("%d ", v[i]);
  }  
  puts("");

  int key = 40;
  
  printf("Key found? %d\n", find(v, 0, n - 1, key));
  return 0;
}
