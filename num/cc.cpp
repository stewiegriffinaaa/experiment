#include<iostream>
#include<cmath>
using namespace std;
class CComplex
{
  double real,imag;
public:
  CComplex(double a = 0,double b = 0):real(a),imag(b){}
  ~CComplex(){}
  bool operator>(const CComplex& num){
    return sqrt(this->real*this->real+this->imag*this->imag)>sqrt(num.real*num.real+num.imag*num.imag);
  }
  bool operator<(const CComplex& num){
    return sqrt(this->real*this->real+this->imag*this->imag)<sqrt(num.real*num.real+num.imag*num.imag);
  }
  CComplex operator+(const CComplex& num){
    CComplex result;
    result.real = this->real + num.real;
    result.imag = this->imag + num.imag;
    return result;
  }
  CComplex operator*(const CComplex& num){
    CComplex result;
    result.real = num.real*this->real - num.imag*this->imag;
    result.imag = this->imag*num.real + this->real*num.imag;
    return result;
  }
  double GetR() const{
    return real; 
  }
  double GetI() const{
    return imag;
  }
  friend istream& operator>>(istream& in,CComplex& num);
};
istream& operator>>(istream& in,CComplex& num){
  in >> num.real >> num.imag;
  return in;
}
void print(const CComplex& num){
  if(num.GetI() >= 0){
    cout << num.GetR() << "+" << num.GetI() << "i" <<endl;
  }
  else 
    cout << num.GetR() << num.GetI() << endl;
}
int main(){
  CComplex a,b;
  cin >> a;
  cin >> b;
  print(a+b);
  print(a*b);
  if(a>b)
    cout << "a>b" << endl;
  if(a<b)
    cout << "a<b" << endl;
  return 0;
}










