#include <bits/stdc++.h>

#define frlp(v) for(const auto &value : v)
#define fr(len) for(int d =0 ; d < len ; d++)

using namespace std;
vector <pair <int ,long long> > Stat;
int LargestFactor(int num){
  int  m = num, el = 0;
  vector <int>v;
  for (int i = 2; i< m; i++){
    if(num % i == 0) {
      v.push_back(i);
      m = num/i;
      v.push_back(m);
    }
  }
  if(v.size() > 0) el = v[v.size()-1];
  Stat.push_back(make_pair(num, el));
  return el;
      
}
int main(){
  int tt;
  cin >> tt;
  while(tt--){
    int N, num, moves = 0;

    cin >> N;
    while(N > 3){
      num = LargestFactor(N);
      if(num > 0)
        N = num;
      else 
        N--;
      moves++;
    }
        cout << (moves+N);
  }
  
    return 0;
}
