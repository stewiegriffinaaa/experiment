#include<iostream>
#include<cmath>
using namespace std;
class Point2D
{
  double x,y;
public:
  Point2D(double x = 0,double y = 0):x(x),y(y){}
  int GetX(){
    return x;
  }
  int GetY(){
    return y;
  }
};
class Shape
{
protected:
  Point2D center;
public:
  Shape(double x = 0,double y = 0):center(x,y){};
  virtual double Area(){
    cout << "start to caculate the area!" << endl;
    return 0;
  }
};
class Rectangle:public Shape
{
  double length,width;
public:
  Rectangle(double len = 0,double wid = 0):length(len),width(wid),Shape(){}
  double Area(){
    return width*length;
  }
};
class CTriangle:public Shape
{
  double length,width;
public:
  CTriangle(double len = 0,double wid = 0):length(len),width(wid),Shape(){}
  double Area(){
    return width*length/2;
  }
};
class Circle:public Shape
{
  double Radius;
public:
  Circle(double x = 0,double y = 0,double r = 0):Shape(x,y),Radius(r){}
  double Area(){
    return Radius*Radius*acos(-1);
  }
};
class Ellipse:public Circle
{
  double a,b;
public:
  Ellipse(double x,double y, double a = 0,double b = 0):Circle(x,y),a(a),b(b){}
  double Area(){
    return acos(-1)*a*b;
  }
};
int main(){
  Shape *List[100];
  for(int i=0;i<25;i++)
  {
    List[i] = new CTriangle(i,i+1);
    List[i+25] = new Rectangle(i+25,i+25+1);
    List[i+50] = new Circle(0,0,i+50);
    List[i+75] = new Ellipse(0,0,i+75,2*(i+75));
  }
  cout << List[3]->Area() << endl;
  cout << List[57]->Area() << endl;
  return 0;
}









