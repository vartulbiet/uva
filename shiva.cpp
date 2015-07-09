#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int main()
{
   string s;
   int count=0;
   while(getline(cin,s))
   {
   cout<<s<<endl;
   if(s=="*")
  break;
  if(s =="hajj")
  printf("Case %d: Hajj-e-Akbar\n",++count);
  if(s=="umrah")
        printf("Case %d: Hajj-e-Asghar\n",++count); 
 
    }
   //p:;
    return 0;
}