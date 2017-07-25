#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
  char sentence []="-3ABC";
  char str [20];
  char st;
  int i,j;

  sscanf (sentence+1,"%d%c",&j,&st,&i);
  printf ("%c -> %d\n",st,j);
  cout<<(j*2-1) + (st-'A');
  
  return 0;
}