#include<iostream>
#include<vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
#include<string.h>
#include <iomanip>
#include <cstdio>
#include<math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
#include<stack>
#include <string.h>
#include<stdio.h>
int main(){
   /**write your code here**/
   int n =0;
   cin>>n;
   char*s = (char*)malloc(sizeof(char)*100);
gets(s);
gets(s);
  cout<<s<<endl;
  stack<int>st;
//int i =0;
 char*y= strtok (s, " ");
   while(y != NULL)
   {	
  	
   	if(y[0] == '*' || y[0] =='/' || y[0] == '+' || y[0] =='-')
   	{
   		int a =st.top();st.pop();
   		int b =st.top();st.pop();
		
   		if(y[0]=='*')
   		st.push(a*b);
   		if(y[0]=='-')
   		st.push(a-b);
   		if(y[0]=='+')
   		st.push(a+b);
   		if(y[0]=='/')
   		st.push(a/b);
   	}
   	else
   	{
   	int x = atoi(y);
   	st.push(x);
   	}
   	y= strtok (NULL, " ");
		cout<<st.top()<<endl;
   }
   cout<<st.top();
   return 0;
}