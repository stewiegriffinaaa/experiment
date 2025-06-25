#include<iostream>
using namespace std;
class Node
{
  int date;
  Node* next;
public:
  Node(int date = 0){
    this->date = date;
    this->next = NULL;
  }
  ~Node(){
    this->next = NULL;
  }
  friend class LinkedList;
};
class LinkedList{
  Node* head;
public:
  LinkedList(){
    this->head = new Node(0);
  }
  void TailInsert(int date){
    Node* p = this->head;
    while(p->next != NULL){
      p = p->next;
    }
    Node* new_node = new Node(date);
    p->next = new_node;
  }
  bool TailDelete(int &date){
    if(this->head->next == NULL)
      return false;
    Node *p = this->head;
    while(p->next->next != NULL){
      p = p->next;
    }
    date = p->next->date;
    delete p->next;
    p->next = NULL;
    return true;
  }
  void HeadInsert(int date){
    Node *new_node = new Node(date);
    new_node->next = this->head->next;
    this->head->next = new_node;
  }
  bool HeadDelete(int& date){
    if(this->head->next == NULL){
      return false;
    }
    Node *p = this->head->next;
    this->head->next = this->head->next->next;
    date = p->date;
    delete p;
    return true;
  }
  ~LinkedList(){
    int mid;
    while(TailDelete(mid)){
      cout << mid << "is deleted" << endl;
    }
    delete this->head;
  }
};
int main(){
  LinkedList List;
  for(int i = 0;i<10;i++){
    List.TailInsert(i);
  }
  return 0;
}












