#include<iostream>
using namespace std;
class Complex{
public:
  int real;
  int imag;
  Complex(int real = 0,int imag = 0):real(real),imag(imag){}
  Complex operator+(const Complex& a){
    Complex result;
    result.real = a.real + this->real;
    result.imag = a.imag + this->imag;
    return result;
  }
  Complex operator-(const Complex& a){
    Complex result;
    result.real = this->real - a.real;
    result.imag = this->imag - a.imag;
    return result;
  }
  Complex operator=(const Complex& a){
    this->real = a.real;
    this->imag = a.imag;
    return *this;
  }
  Complex operator++(int x){
    Complex result(real,imag);
    this->real++;
    this->imag++;
    return result;
  }
  Complex operator++(){
    this->real++;
    this->imag++;
    return *this;
  }
};

















