#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
class CPoint
{
  double x;
  double y;
public:
  CPoint(double x = 0,double y = 0):x(x),y(y){}
  double Distance(const CPoint& num) {
    return sqrt((num.x-this->x)*(num.x-this->x) + (num.y-this->y)*(num.y-this->y));
  }
};
class CTriangle
{
  CPoint a;
  CPoint b;
  CPoint c;
public:
  CTriangle(const CPoint& a,const CPoint& b,const CPoint& c):a(a),b(b),c(c){}
  double Peri(){
    double length = a.Distance(b) + a.Distance(c) + c.Distance(b);
    return length;
  }
  double Area(){
    double m = a.Distance(b);
    double n = b.Distance(c);
    double z = a.Distance(c);
    double p = (m+n+z)/2.0;
    return sqrt(p*(p-m)*(p-n)*(p-z));
  }
};
int main(){
  double x,y;
  cin >> x >> y;
  CPoint a(x,y);
  cin >> x >> y;
  CPoint b(x,y);
  cin >> x >> y;
  CPoint c(x,y);
  CTriangle num(a,b,c);
  cout << setprecision(10) << num.Peri() << " " << num.Area() << endl;
}
