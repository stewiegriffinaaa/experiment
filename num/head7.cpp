#include<iostream>
using namespace std;
class CStack
{
  char *s;
  int tp;
  int size;
public:
  CStack(int initSize = 5):size(initSize){
    s = new char[size];
    tp = -1;
  }
  ~CStack(){
    delete [] s;
  };
  bool isEmpty(){
    if(tp == -1)
      return 1;
    return 0;
  }
  bool isFull(){
    if(tp == 4)
      return 1;
    return 0;
  }
  void push(char c){
    if(isFull() == 0){
      tp++;
      s[tp] = c;
    }
  }
  char pop(){
    if(isEmpty() == 0){
      int a = s[tp];
      tp--;
      return a;
    }
    return 0;
  }
  char top(){
    return s[tp];
  }
};
int main(){
  string test;
  getline(cin,test);
  CStack num;
  for(int i = 0;i<size(test);i++){
    if(test[i] == '{' || test[i] == '[' || test[i] == '(')
      num.push(test[i]);
    if(test[i] == '}' || test[i] == ']' || test[i] == ')')
      num.pop();
  }
  if(num.isEmpty())
    cout << "Balanced" << endl;
  else
    cout << "Not balanced" << endl;
  return 0;
}









