
#include <cstdlib>
#include <iostream>
#include <string.h>
#include "header.h"

using namespace std;




int main()
{
  stack line1;
  queue line2;
  word *tmp1, *tmp2;

  char wrd[30];
  char c;
  int cnt=0, flag=1;

  cout<<"Insert something: \n";

  cin.get(c);
  while(1)
  {
    if(c =='?' || c =='.' || c ==';' || c ==':' || c =='!' || c ==',')
      cin.get(c);
    else if(c == 32)
    {    
      line1.push(wrd);
      line2.enqueue(wrd);
      cnt=0;
      cin.get(c);
    }
    else if(c =='\n')
    {
      line1.push(wrd);
      line2.enqueue(wrd);
      break;
    }
    else
    {
      wrd[cnt] = c;
      ++cnt;
      wrd[cnt] = '\0';
      cin.get(c);
    }
  }
  cin.clear();
  

  while(!line1.isEmpty() && !line2.isEmpty())
  {
    tmp1=line1.gettop();
    tmp2=line2.getfront();

    if(strcmp(tmp1->w,tmp2->w))
    { 
      flag =0;
      break;
    }

    line1.pop();
    line2.dequeue();    
  }

  if(flag == 1)
    cout<<"\nThe line is read the same from front to back and from back to front.\n";
  else
    cout<<"\nThe line is NOT read the same from front to back and from back to front.\n";


  return 0;
}




