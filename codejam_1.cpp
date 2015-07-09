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
#define ll long long int
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
int main()
{
	int n =0;
	cin>>n;int tc =1;
	while(n--)
	{
		ull r,b;
		cin>>r>>b;
		ull c =0;;
		/*if(r<10000)
		{
		 c = (ull)sqrtl((ull)((2*r-1)*(2*r-1)+b*8)) - (2*r-1);
		c =c/4;
		}
		else*/
		{
		ull mat =0;
		ull f =1;
		while((2*r-1)*f+2*f*f<b)
		{
			f=f*1000;
		}
		ull d = f/1000;
		for(ull h =d;h<=f;h++)
		{
			if((2*r-1)*h+2*h*h>b)
			{
				c =h-1;
				break;
			}
		}
		}
		cout<<"Case #"<<tc++<<": ";
		cout<<c<<endl;
	}
	return 0;
}