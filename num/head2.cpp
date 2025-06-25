#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
  vector<int> v1;
  int n;
  cin >> n;
  for(int i = 0;i<n;i++){
    int num;
    cin >> num;
    v1.push_back(num);
  }
  sort(v1.begin(),v1.end());
  for(int i = 0;i<n - 1;i++){
    cout << v1[i] << " ";
  }
  cout << v1[n-1] << endl;
  return 0;
}
