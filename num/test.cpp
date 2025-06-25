#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Hero
{
  int &ID;
  char* name;
  bool gender;
public:
  Hero(int& id, char* _name, bool gender = true):ID(id)
  {
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name,_name);
    this->gender = gender;
    cout << "Constructor of" << this->name << endl;
  }
  ~Hero(){
    cout << "Destructor of" << this->name << endl;
    delete [] this->name;
    this->ID = 0;
    this->gender = 0;
  }
  int GetID(){
    return ID;   //only permit to read because of what was delivered just a copyy 
  }
  void SetID(int ID){
    this->ID = ID;
  }
  void print(){
    cout << ID << " ";
    cout << name << " ";
    cout << gender << endl;
  }
};
int main()
{
  return 0;
}


















