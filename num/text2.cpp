#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
  ifstream file;
  file.open("text.txt");
  string mid;
  file >> mid;
  file.close();
  cout << mid << endl;
  return 0;
}
