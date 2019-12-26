#include<iostream>
#include<typeinfo>
using namespace std;

template<typename Type>
Type fun(Type a ,Type b)
{
  cout << typeid(a).name() << endl;
  cout << typeid(b).name() << endl;
  
}
int main()
{
  int a = 0;
  int b = 0;
  fun(a,b);
  
  return 0;
}
