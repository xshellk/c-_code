#include<stdio.h>
#include<malloc.h>

typedef struct softArray
{
  int i;
  int soft[];
}softArray;
int main()
{
  printf("%d\n", sizeof(softArray));
  softArray* p = (softArray*)malloc(1);
  
  return 0;

}
