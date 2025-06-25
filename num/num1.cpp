#include<iostream>
#include<list>
#include<string>
using namespace std;
class StudentRecord
{
public:
  string stuName;
  int stuNo;
  StudentRecord(){}
  void Print(){
    cout << stuName << " " << stuNo << endl;
  }
};
class LinkedList
{
  list<StudentRecord> lst;
public:
  LinkedList(){}
  void Headpush(const StudentRecord& num){
    lst.push_front(num);
  }
  bool Headcut(){
    if(lst.empty()){
      return 0;
    }
    cout << lst.front().stuName << " " << lst.front().stuNo << endl;
    lst.pop_front();
    return 1;
  }
  void Tailpush(const StudentRecord& num){
    lst.push_back(num);
  }
  bool Tailpop(){
    if(lst.empty()){
      return 0;
    }
    cout << lst.back().stuName <<" "<< lst.back().stuNo << endl;
    lst.pop_back();
    return 1;
  }
};
class LinkedStack:public LinkedList 
{
public:
  LinkedStack(){}
  void Push(const StudentRecord& record){
    Tailpush(record);
  }
  bool Pop(){
    return Tailpop();
  }
};
class LinkedQueue:public LinkedList{
public:
  LinkedQueue(){}
  void EnQueue(const StudentRecord &record){
    Tailpush(record);
  }
  bool DeQueue(){
    return Headcut();
  }
};
int main()
{
  LinkedQueue queue;
  LinkedStack stack;
  string sign = "blank";
  while(1){
    cin >> sign;
    if(sign == "Push"){
      StudentRecord num;
      cin >> num.stuName >> num.stuNo;
      stack.Push(num);
    }
    else if(sign == "Pop"){
      if(stack.Pop() == 1){
        
      }
      else
        cout << "Stack is empty!" << endl;
    }
    else if(sign == "EnQueue"){
      StudentRecord num;
      cin >> num.stuName >> num.stuNo;
      queue.EnQueue(num);  
    }
    else if(sign == "DeQueue"){
      if(queue.DeQueue() == 1)
      {

      }
      else {
        cout << "Queue is empty!" << endl;
      }
    }
    else if(sign == "Exit"){
      while(stack.Pop() == 1){}
      while(queue.DeQueue() == 1){}
      break;
    }
    else{ 
      cout << "Input error!" << endl;
    }
  }
  return 0;
}



















































