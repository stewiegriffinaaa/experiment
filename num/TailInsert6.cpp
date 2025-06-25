#include<iostream>
#include<string>
using namespace std;
class CAnimal
{
protected:
  string name;
  int age;
public:
  CAnimal(string name,int age):name(name),age(age){
    cout << "Animal constructor: " << name << " " << age << endl;
  }
  virtual void Talk() = 0;
  virtual ~CAnimal(){
    cout << "Animal destructor" << endl;
  }
};
class CHorse:virtual public CAnimal{
  int power;
public:
  CHorse(string name,int age,int power):CAnimal(name,age),power(power){
    cout << "Horse constructor: " << power << endl;
  }
  void Talk(){
    cout << "Whinny..." << endl;
  }
  ~CHorse(){
    cout << "Horse destructor" << endl;
  }
};
class CBird:virtual public CAnimal{
  float wingspan;
public:
  CBird(string name,int age,float wingspan):CAnimal(name,age),wingspan(wingspan){
    cout << "Bird constructor: " << wingspan << endl;
  }
  void Talk(){
    cout << "Chirp..." << endl;
  }
  ~CBird(){
    cout << "Bird destructor" << endl;
  }
};
class CPegasus:public CHorse,public CBird{
public:
  CPegasus(string name,int age,int power,float wingspan):CAnimal(name,age),CHorse(name,age,power),
CBird(name,age,wingspan){
    cout << "Pegasus constructor" << endl;
  }
  void Talk(){
    CHorse::Talk();
  }
  ~CPegasus(){
    cout << "Pegasus destructor" << endl;
  }
};
int main(){
  int n;
  cin >> n;
  CAnimal *List[100];
  string signal;
  string a;
  int b;
  int c;
  float d;
  for(int i = 0;i<n;i++){
    cin >> signal;
    if(signal == "H"){
      cin >> a >> b >> c;
      List[i] = new CHorse(a,b,c);
      List[i]->Talk();
    }
    else if(signal == "B"){
      cin >> a >> b >> d;
      List[i] = new CBird(a,b,d);
      List[i]->Talk();
    }
    else if(signal == "P"){
      cin >> a >> b >> c >> d;
      List[i] = new CPegasus(a,b,c,d);
      List[i]->Talk();
    }
    else{
      cout << "Input error!" << endl;
      List[i] = NULL;
    }
  }
//  for(int i = 0;i<n;i++){
//    if(List[i] != NULL){
//      List[i]->Talk();
//    }
//  }
  for(int i = 0;i<n;i++){
    if(List[i] != NULL){
      delete List[i];
    }
  }
  return 0;
}

















