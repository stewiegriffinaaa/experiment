#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class CShape
{
protected:
  double rectWidth,rectHeight;
public:
  CShape(){}
  void Show(){
    cout << "W = " << rectWidth << ", ";
    cout << "H = " << rectHeight << ", ";
    cout << "Area = " << Area() << endl;
  }
  virtual double Area() = 0;
  virtual ~CShape(){}
  virtual string signal() = 0;
  friend bool operator==(CShape &num1,CShape &num2);
  friend bool operator<(CShape &num1,CShape &num2);
  friend bool operator>(CShape &num1,CShape &num2);
};
class CRectangle:public CShape
{
public:
  CRectangle(double rectWidth,double rectHeight){
    this->rectWidth = rectWidth;
    this->rectHeight = rectHeight;
  }
  double Area(){
    return rectWidth*rectHeight;
  }
  ~CRectangle(){}
  string signal(){
    return "(rectangle)";
  }
};
class CEllipse:public CShape
{
public:
  CEllipse(double rectWidth, double rectHeight){
    this->rectWidth = rectWidth;
    this->rectHeight = rectHeight;
  }
  static const double PI;
  double Area(){
    return PI*rectWidth*rectHeight/4.0;
  }
  string signal(){
    return "(ellipse)";
  }
};
const double CEllipse::PI = 3.1416;
class CDiamond:public CShape
{
public:
  CDiamond(double rectWidth,double rectHeight)
  {
     this->rectWidth = rectWidth;
     this->rectHeight = rectHeight;
  }
  double Area(){
    return rectWidth*rectHeight/2.0;
  }
  string signal(){
    return "(diamond)";
  }
};
bool operator==(CShape &num1,CShape &num2){
    return fabs(num1.Area() - num2.Area()) < 0.0001;
}
bool operator<(CShape &num1,CShape &num2){
  return num1.Area() < num2.Area();
}
bool operator>(CShape &num1,CShape &num2){
  return num1.Area() > num2 .Area();
}
bool compare(CShape* a,CShape* b){
  return a->Area() > b->Area();
}
string GetType(CShape* num){
  return num->signal();
}
int main()
{
    int num;
    int i, j;

    vector <CShape *> sarr;
    string str;
    double w, h;

    cin >> num;
    for (i = 0; i < num; i++)
    {
        cin >> str >> w >> h;
        if (str == "R")
        {
            sarr.push_back(new CRectangle(w, h));
        }
        else if (str == "E")
        {
            sarr.push_back(new CEllipse(w, h));
        }
        else if (str == "D")
        {
            sarr.push_back(new CDiamond(w, h));
        }
        else
        {
            cout << "Input error!" << endl;
        }
    }

    num = sarr.size();

    for (i = 0; i < num; i++)
    {
        sarr[i]->Show();
    }

    for (i = 0; i < num - 1; i++)
    {
        for (j = i+1; j < num; j++)
        {
            if ((*sarr[i]) == (*sarr[j]))
            {
                cout << "Area of Shape[" << i << "]" << GetType(sarr[i]) << " is equal to Shape[" << j << "]" << GetType(sarr[j]) << endl;
            }
        }
    }

    sort(sarr.begin(), sarr.end(), compare);

    for (i = 0; i < num; i++)
    {
        sarr[i]->Show();
    }

    for (i = 0; i < num; i++)
    {
        delete sarr[i];
    }

    return 0;
}










