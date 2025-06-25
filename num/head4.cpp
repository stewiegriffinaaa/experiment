#include<iostream>
#include<string>
using namespace std;
int main(){
  string str1;
  string str2;
  getline(cin,str1);
  getline(cin,str2);
  bool signal = true;
  int head = -1;
  for(int i = 0;i<size(str1)-size(str2)+1;i++){
    for(int j = 0;j<size(str2);j++){
       if(str1[i+j] != str2[j]){
          signal = false;
       }
      if(signal){
        head = i;
      }
      signal = true;
    }
  }
  cout << head << endl;
  return 0;
}
