#include<iostream>
#include<cmath>
using namespace std;
const double PI = 3.1416;
double Area(double r){
  return PI*r*r;
}
double Area(double len,double wid){
  return len*wid;
}
double Area(double a,double b,double c){
  double p = (a + b + c)/2.0;
  return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main(){
  double r;
  cin >> r;
  cout << Area(r) << endl;
  double len,wid;
  cin >> len >> wid;
  cout << Area(len,wid) << endl;
  double a,b,c;
  cin >> a >> b >> c;
  cout << Area(a,b,c) << endl;
  return 0;
}
