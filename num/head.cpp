#include<iostream>
using namespace std;
void Print(int n,int base = 10,bool Upper = false){
  if(base == 10)
    cout << "Dec: " << n << endl;
  if(base == 8)
    cout << "Oct: " << oct << n << endl;
  if(Upper == true && base == 16){
    cout << "Hex: " << hex << uppercase << n << endl;
  }
  if(Upper == false && base == 16)
    cout << "Hex: " << hex << n << endl;
}
int main(){
  int n;
  cin >> n;
  Print(n,10);
  Print(n,8);
  Print(n,16);
  Print(n,16,true);
  return 0;
}
