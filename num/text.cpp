#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
  fstream file;
  file.open("text.txt",ios::out);
  string name;
  string num;
  while(1){
    cin >> name >> num;
    file << name << " " << num << endl;
  }
  file.close();
  return 0;
}

