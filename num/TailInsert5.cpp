#include<iostream>
#include<cmath>
using namespace std;
class Rational
{
  int iUp;
  int iDown;
  void Reduce(){
    int mid = Gcd(iUp,iDown);
    iUp = iUp/mid;
    iDown = iDown/mid;
  }
  int Gcd(int l,int r){
    int min;
    if(fabs(l) <= fabs(r) )
      min = fabs(l);
    else
      min = fabs(r);
    int result;
    for(int i = 1;i <= min;i++){
      if(l%i == 0 && r%i == 0){
        result = i;
      }
    }
    return result;
  }
public:
  Rational(int iUp = 1,int iDown = 1):iUp(iUp),iDown(iDown){}
  bool operator!(){
    if(this->iDown == 0){
      return 0;
    }
    return 1;
  }
  Rational operator++(int x){
    Rational mid(this->iUp,this->iDown);
    this->iUp += this->iDown;
    if(mid.iUp != 0)
      mid.Reduce();
    return mid;
  }
  Rational operator--(int x){
    Rational mid(this->iUp,this->iDown);
    this->iUp -= this->iDown;
    if(mid.iUp != 0)
      mid.Reduce();
    return mid;
  }
  Rational operator++(){
    this->iUp += this->iDown;
    if(this->iUp != 0)
      this->Reduce();
    return *this;
  }
  Rational operator--(){
    this->iUp -= this->iDown;
    if(this->iUp != 0)
      this->Reduce();
    return *this;
  }
  Rational operator-(){
    Rational mid(this->iUp,this->iDown);
    mid.iUp = -mid.iUp;
    if(mid.iUp != 0)
      mid.Reduce();
    return mid;
  }
  friend Rational operator+(const Rational& num1,const Rational& num2);
  friend Rational operator-(const Rational& num1,const Rational& num2);
  friend Rational operator*(const Rational& num1,const Rational& num2);
  friend Rational operator/(const Rational& num1,const Rational& num2);
  friend bool operator<(Rational& num1,Rational& num2);
  friend bool operator>(Rational& num1,Rational& num2);
  friend istream& operator>>(istream& in,Rational& num);
  friend ostream& operator<<(ostream& out,const Rational& num);
};
Rational operator+(const Rational& num1,const Rational& num2)
{
  Rational result;
  result.iDown = num1.iDown*num2.iDown;
  result.iUp = num1.iUp*num2.iDown + num2.iUp*num1.iDown;
  if(result.iUp != 0)
    result.Reduce();
  return result;
}
Rational operator-(const Rational& num1,const Rational& num2)
{
  Rational result;
  result.iDown = num1.iDown*num2.iDown; 
  result.iUp = num1.iUp*num2.iDown - num2.iUp*num1.iDown;
  if(result.iUp != 0)
  result.Reduce();
  return result; 
}
Rational operator*(const Rational& num1,const Rational& num2){
  Rational result;
  result.iDown = num1.iDown*num2.iDown;
  result.iUp = num1.iUp*num2.iUp;
  if(result.iUp != 0)
  result.Reduce();
  return result;
}
Rational operator/(const Rational& num1,const Rational& num2){
  Rational result;
  result.iDown = num1.iDown*num2.iUp;
  result.iUp = num1.iUp*num2.iDown;
  if(result.iDown < 0){
    result.iDown = -result.iDown;
    result.iUp = -result.iUp;
  }
  if(result.iDown != 0)
  result.Reduce();
  return result;
}
bool operator<(Rational& num1,Rational& num2){
  int mid = (num1 - num2).iUp;
  return mid < 0;
}
bool operator>(Rational& num1,Rational& num2){
  int mid = (num1 - num2).iUp;
  return mid > 0;
}
istream& operator>>(istream& in,Rational& num){
  in >> num.iUp;
  char mid;
  in >> mid;
  in >> num.iDown;
  if(!num == 0)
    cout << "The denominator cannot be zero!" << endl;
  return in;
}
ostream& operator<<(ostream& out,const Rational& num){
  if(num.iDown == 1){
    out << num.iUp;
    return out;
  }
  else if(num.iDown == 0){
    out << "The denominator cannot be zero!" << endl;;
  }
  out << num.iUp << "/" << num.iDown;
  return out;
}
int main()
{
    Rational a;
    Rational b;

    cout << "Input rational a: " << endl;
    cin >> a;
    cout << "Input rational b: " << endl;
    cin >> b;

    if (!a && !b)
    {
        cout << "a+b: " << (a+b) << endl;
        cout << "a-b: " << (a-b) << endl;
        cout << "a*b: " << (a*b) << endl;
        cout << "a/b: " << (a/b) << endl;
        cout << "-a: " << (-a) << endl;
        cout << "++a: " << (++a) << endl;
        cout << "--a: " << (--a) << endl;
        cout << "a++: " << (a++) << endl;
        cout << "a--: " << (a--) << endl;
        cout << "a>b: " << ((a>b)?"true" : "false") << endl;
        cout << "a<b: " << ((a<b)?"true" : "false") << endl;
    }

    return 0;
}











