#include<iostream>
using namespace std;
class Point2D
{
protected:
  double x,y;
public:
  Point2D(double x = 0,double y = 0):x(x),y(y){}
  double GetX() const{
    return this->x;
  }
};
class Point3D:public Point2D{
  double z;
public:
  Point3D(double x = 0,double y = 0,double z = 0):Point2D(x,y),z(z) {}
  double GetX() const{
    return this->z;
  }
};
int main(){
  Point3D p3d_obj(1.2,3.5,9.9);
  Point2D p2d_obj(p3d_obj);
  cout << p2d_obj.GetX() << endl;
  return 0;
}

