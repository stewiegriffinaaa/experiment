#include<iostream>
#include<string>
using namespace std;
template<class T>
void Swap(T& a,T& b){
  T c;
  c = a;
  a = b;
  b = c;
}
int main()
{
    int a, b;
    double x, y;
    string str1, str2;
    cin >> a >> b;
    cin >> x >> y;
    cin >> str1 >> str2;
    Swap(a, b);
    Swap(x, y);
    Swap(str1, str2);
    cout << a << " " << b << endl;
    cout << x << " " << y << endl;
    cout << str1 << " " << str2 << endl;
    return 0;
}

