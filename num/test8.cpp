#include<iostream>
using namespace std;
class OrderIntList{
  int length;
  int arr[1024];
public:
  OrderIntList(){
    this->length = 0;
  }
  OrderIntList(int *a,int length){
    if(length >= 1024)
      exit(-1);
    this->length = length;
    for(int i = 0;i < this->length;i++)
        this->arr[i] = a[i];
  }
  ~OrderIntList(){}
  OrderIntList operator=(const OrderIntList& num){
    for(int i = 0;i < num.length; i++){
      this->arr[i] = num.arr[i];
    }
    return *this;
  }
  int& operator[](int x){
    if(x >= length)
      exit(-1);
    return this->arr[x];
  }
  friend istream& operator>>(istream &in,OrderIntList& num);
  friend ostream& operator<<(ostream &out,OrderIntList& num);
};
istream& operator>>(istream &in,OrderIntList& num){
  int n;
  in >> n;
  int *a = new int[n];
  num.length = n;
  for(int i = 0;i < n;i++){
    in >> a[i];
  }
  OrderIntList mid(a,n);
  num = mid;
  delete [] a;
  return in;
}
ostream& operator<<(ostream &out,OrderIntList& num){
  out << "length: " << num.length << endl;
  for(int i = 0;i < num.length ; i++){
    out << num.arr[i];
  }
  out << endl;
  return out;
}
int main(){
  OrderIntList List1;
  cin >> List1;
  cout << List1;
  cout << List1[3] << endl;
  cout << List1[2000];
  return 0;
}
