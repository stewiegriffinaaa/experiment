#include<iostream>
#include<string>
using namespace std;
class Card
{
  string cont[52];
public:
  Card(const string *mid){
    for(int i = 0;i < 52;i++){
      cont[i] = mid[i];
    }
  }
  string pick(int x){
    return cont[x];
  }
  int getScore(string num){
    if(num[1] <= '9' && num[1] >='2')
      return num[1] - '0';
    if(size(num) == 3)
      return 10;
    if(num[1] == 'A')
      return 11;
    if(num[1] == 'J')
      return 10;
    if(num[1] == 'Q')
      return 10;
    if(num[1] == 'K')
      return 10;
    return 0;
  }
};
int main(){
  string mid[52];
  for(int i = 0;i<52;i++){
    cin >> mid[i];
  }
  Card pu(mid);
  int num1 = 0;
  int num2 = 0;
  string Pick1[5];
  string Pick2[5];
  for(int i = 0;i < 5;i++){
    int x;
    cin >> x;
    Pick1[i] = pu.pick(x);
    num1 += pu.getScore(Pick1[i]);
  }
  for(int i = 0;i < 5;i++){
    int x;
    cin >> x;
    Pick2[i] = pu.pick(x);
    num2 += pu.getScore(Pick2[i]);
  }
  cout << "Player 1 got: ";
  for(int i = 0;i<4;i++){
    cout << Pick1[i] << " ";
  }
  cout << Pick1[4] << endl;
  cout << "Player 1 points: " << num1 << endl;
  cout << "Player 2 got: ";
  for(int i = 0;i<4;i++){
    cout << Pick2[i] << " ";
  }
  cout << Pick2[4] << endl;
  cout << "Player 2 points: " << num2 << endl;
  if(num1 == num2)
    cout << "Draw!" << endl;
  if(num1 > num2)
    cout << "Player 1 wins!" << endl;
  if(num1 < num2)
    cout << "Player 2 wins!" << endl;
  return 0;
}











