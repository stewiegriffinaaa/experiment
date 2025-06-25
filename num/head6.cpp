#include<iostream>
using namespace std;
class Ellipsoid
{
  double r1,r2,r3;
  static const double PI;
public:
  Ellipsoid(double r1 = 0,double r2 = 0,double r3 = 0):r1(r1),r2(r2),r3(r3){}
  bool IsEqual(Ellipsoid& num){
    double s1[] = {this->r1,this->r2,this->r3},s2[] = {num.r1,num.r2,num.r3};
    _sort(s1);
    _sort(s2);
    for(int i = 0;i<3;i++){
      if(s1[i] != s2[i]){
        return false;
      }
    }
    return true;
  }
  double GetVolume(){
    return 4*PI*r1*r2*r3/3.0;
  }
  void _sort(double *s);
};
const double Ellipsoid::PI = 3.1416;
void Ellipsoid::_sort(double *s){
  for(int i = 0;i<3-1;i++){
    for(int j = 0;j<3-1-i;j++){
      if(s[j]<=s[j+1]){
        double mid;
        mid = s[j];
        s[j] = s[j+1];
        s[j+1] = mid;
      }
    }
  }
}
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  Ellipsoid num1(a,b,c);
  cin >> a >> b >> c;
  Ellipsoid num2(a,b,c);
  cout << num1.GetVolume() << " " << num2.GetVolume() << endl;
  if(num1.IsEqual(num2))
    cout << "true" << endl;
  else
    cout << "false" << endl;
  return 0;
}






