#include<iostream>
#include<cmath>
using namespace std;
class Point2D
{
  double x,y;
  static int number;
public:
  Point2D(double x = 0,double y = 0){
    this->x = x;
    this->y = y;
//    cout << "CP" << this->x << endl;
    number++;
  }
  ~Point2D(){
//    cout << "DP" << endl;
  }
  static int getCounter(){
    return number;
  }
  double GetX() const{
    return x;
  }
  double GetY() const{ //const functions are only used to read informationn
    return y;
  }
};
class Circle2D{
  Point2D c;
  double r;
  static int Count;
public:
  static const double pi;
  Circle2D(double x = 0,double y = 0,double r = 0):c(x,y){
    this->r = r;
    Count++;
  }
  static int GetCount(){
    return Count;
  }
  ~Circle2D(){
    Count--;
  }
  double GetArea() const{
    return pi*r*r;
  }
  double GetCirc() const{
    return 2*pi*this->r;
  }
};
const double Circle2D::pi = acos(-1);
int Circle2D::Count = 0;
int main(){
  Circle2D *circle[10];
  for(int i = 0;i < 10;i++){
    circle[i] = new Circle2D(i,i,1);
  }

  return 0;
}







