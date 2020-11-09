#include<iostream>
#include<unistd.h>
#include<stdio.h>


using namespace std;

int main()
{
  pid_t id = fork();
  if(id > 0)
  {
    cout << "this is father" << endl;
  }
  else if(id == 0)
  {
    cout << "this is child" << endl;
  }
  else{
    cout << "fork error" << endl;
  }
  sleep(200);
  

  return 0;
}
