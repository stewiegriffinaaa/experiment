#include<iostream>
#include<list>
using namespace std;
bool compare(int a,int b){
  return a > b;
}
int main()
{
  list<int> Lst;
  for(int i = 0;i<5;i++){
    int num;
    cin >> num;
    Lst.push_back(num);
  }
  Lst.sort(compare);
  for(list<int>::iterator it = Lst.begin();it != Lst.end();it++){
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}
