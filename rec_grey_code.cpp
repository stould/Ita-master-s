#include <bits/stdc++.h>

using namespace std;

/*
0000
0001
0011
0010
0110
0111
0101
0100
1100
1101
1111
1110
1010

starting wit {0, 1}:
0, 1 -> old
1, 0 -> new

newlist = {00, 01, 11, 10} contatenated old + new

00, 01, 11, 10 -> old
10, 11, 01, 00 -> new

newlist = {000, 001, 011, 010, 110, 111, 101, 100} concatenated old + new

recursive step: gray(n): ["0" + [gray(n - 1)]] + ["1" + [reversed(gray(n - 1))]]

*/


vector<string> gray(int n){
  if(n == 1){
    return vector<string>({"0", "1"});
  }else{
    vector<string> oldl = gray(n - 1);
    vector<string> newl(oldl);
    vector<string> ans;
    reverse(newl.begin(), newl.end());
    for(int i = 0; i < oldl.size(); i++){
      ans.push_back("0" + oldl[i]);
    }
    for(int i = 0; i < newl.size(); i++){
      ans.push_back("1" + newl[i]);
    }
    return ans;
  }
}

int main(){
  vector<string> code = gray(3);
  for(auto i : code){
    cout << i << endl;
  }
  return 0;
}
