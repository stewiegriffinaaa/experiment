#include<iostream>
#include<list>
using namespace std;
class Student
{
  string name;
  int ID;
  string lesson;
  double sum_score;
public:
  Student(const string name = "",const int ID = 0,const string lesson = "",const double sum_score = 0):name(name),
  ID(ID),lesson(lesson),sum_score(sum_score){}
  ~Student(){}
  friend ostream& operator<<(ostream& out,const Student& num);
  friend bool operator>(const Student& num1,const Student& num2);
};
ostream& operator<<(ostream& out,const Student& num){
  out << num.name << " " << num.ID << " " << num.lesson << " " << num.sum_score << endl;
  return out;
}
bool operator>(const Student& num1,const Student& num2){
  return num1.sum_score > num2.sum_score;
}
bool compare(const Student& num1,const Student& num2){
    return num1 > num2;
}
int main(){
  list<Student> Lst;
  for(int i = 0;i<3;i++){
    string name;
    int ID;
    string lesson;
    double sum_score;
    cin >> name >> ID >> lesson >> sum_score;
    Student num(name,ID,lesson,sum_score);
    Lst.push_back(num);
  }
  list<Student> Lst2;
  for(int i = 0;i<3;i++){
    string name;
    int ID;
    string lesson;
    double sum_score;
    cin >> name >> ID >> lesson >> sum_score;
    Student num(name,ID,lesson,sum_score);
    Lst2.push_back(num);
   }
  Lst.sort(compare);
  Lst2.sort(compare);
  Lst.merge(Lst2,compare);
  //Lst.sort(compare);
  for(list<Student>::iterator it = Lst.begin();it != Lst.end();it++){
    cout << *it ;
  }
  return 0;
}
