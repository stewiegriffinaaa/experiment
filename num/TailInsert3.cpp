#include<iostream>
#include<string>
using namespace std;
template<class T>
class Array
{
  T *q;
public:
  int num;
  Array(int n):num(n){
    q = new T[n];
  }
  ~Array(){
    delete [] q;
  }
  template<class _T>
  friend istream& operator>>(istream& in,Array<_T>& arr);
  template<class _T>
  friend ostream& operator<<(ostream& out,Array<_T>& arr);
  T& operator[](int x){
    if(x >= 0 && x < num)
      return this->q[x];
    else{
      cout << "Out of boundary!" << endl;
      exit(0);
    }
  }
  void sort(){
    for(int i = 0;i<num-1;i++){
      for(int j = 0;j < num-1-i;j++){
        if(q[j] > q[j+1]){
          T a;
          a = q[j+1];
          q[j+1] = q[j];
          q[j] = a;
        }
      }
    }
  }
  int search(T k) const{
    for(int i = 0;i<num;i++){
      if(q[i] == k)
        return i;
    }
    return -1;
  }
};
template<class T>
istream& operator>>(istream& in,Array<T>& arr){
  for(int i = 0;i<arr.num;i++){
    in >> arr[i];
  }
  return in;
}
template<class T>
ostream& operator<<(ostream& out,Array<T>& arr){
  for(int i = 0;i<arr.num-1;i++){
    out << arr[i] << " ";
  }
  out << arr[arr.num-1] << endl;
  return out;
}
template<class T>
void Process(Array<T> &a){
  cin >> a;
  int mid;
  cin >> mid;
  T test;
  cin >> test;
  cout << a;
  a.sort();
  cout << a;
  cout << a[mid] << endl;
  cout << a.search(test) << endl;
}
int main()
{
    string type;
    int n;

    cin >> type >> n;
    if (type=="int")
    {
        Array<int> a(n);
        Process(a);
    }
    else if (type=="double")
    {
        Array<double> a(n);
        Process(a);
    }
    else if (type=="string")
    {
        Array<string> a(n);
        Process(a);
    }
    else
        cout << "Input error!" << endl;

    return 0;
}










