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

int main()
{	
	ull arr[] ={6,2,4,8};
ull brr[] ={1,3,9,7};
ull crr[]={1,7,9,3};
ull drr[] ={6,8,4,2};
int trr[100];
memset(trr,0,sizeof(trr));
ull ans =0;
for(int  i = 1;i<100;i++)
{
	int yy = i%10;
	if(yy == 5 || yy == 1 || yy ==6 || yy == 9)
			{
				ans+=yy;
			}
			else if(yy == 4)
			ans+=6;
			else
			{
				if(yy == 2)
				{	
					ull s = i%4;
					ans +=arr[s];
				}
				if(yy == 3)
				{	
					ull s = i%4;
					ans +=brr[s];
				}
				if(yy == 7)
				{	
					ull s = i%4;
					ans +=crr[s];
				}
				if(yy == 8)
				{	
					ull s = i%4;
					ans +=drr[s];
				}
			}
			ans =ans%10;
			trr[i] = ans;
			//cout<<trr[i]<<" ";
}
	char a[102];
    char *ptr;
    int p, q;
    scanf("%s", a);
    while(a[0]!='0')
    {
        p=0;
        ptr=a;
        while(*ptr!='\0')
        {
            q=p;
            p=*ptr-'0';
            ptr++;
        }
        printf("%d\n", trr[p+10*q]);
        scanf("%s", a);
    }
return 0;
}