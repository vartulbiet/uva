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
 
#define MAX_BOLTS 1000
#define MAX_NUTS  1000
 
int nuts,bolts;

int fits[MAX_BOLTS][MAX_NUTS];

void read_input_data(void){
   int n,b;
   
   scanf("%d%d",&bolts,&nuts);
   for(b=0;b<bolts;b++){
      for(n=0;n<nuts;n++){
         scanf("%d",&fits[b][n]);
         }
      }
   }
   
   bool bpm(int*match,bool*seen,int j)
   {
	for(int i=0;i<nuts;i++)
	{
		if(!seen[i] && fits[j][i])
		{
			seen[i] = true;
			if(bpm(match,seen,match[i]) || match[i]<0 )
			{
				match[i] = j;
				return true;
			}
		}
	}
	return false;
   }

void bestmatched()
{
	int match[nuts];
	memset(match,-1,sizeof(match));
	int ans =0;
	for(int i =0;i<bolts;i++)
	{
		bool seen[nuts];
		memset(seen,false,sizeof(seen));
		if(bpm(match,seen,i))
		ans++;
	}
	cout<<ans;
}
   
int main(){
   int cases,caseno;
   
   scanf("%d",&cases);
   for(caseno=1;caseno<=cases;caseno++){
      read_input_data();
      printf("Case %d: ",caseno);
      printf("a maximum of ");
	  bestmatched();
      printf(" nuts and bolts can be fitted together\n");
      }
      
   return 0;
   }
