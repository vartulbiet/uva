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
using namespace std;
void recurse(int a,string ans)
{
	if(a == 0)
	{
	cout<<ans<<endl;
	return;
	}
	else
	{
		for(int i =0;i<ans.size();i++)
		{	
			if(ans[i] == '-')
			{
				for(int j =0;j<=9;j++)
				{
					char x = j+'0';
					ans[i] = x;
					recurse(a-1,ans);
				}
			}
		}
	}
	
}
int main()
{
	int m;
	while(scanf("%d",&m)==1)
	{
			vector<string>vec;
		string x;
		getline(cin,x);
		cout<<"--"<<endl;
		while(m>0)
		{
			getline(cin,x);
		//	cout<<x<<"----";
			vec.PB(x);
			m--;
		}
		int n =0;
		cin>>n;
			getline(cin,x);
		vector<string>rules;
		while(n>0)
		{
				getline(cin,x);
				//cout<<x<<"---";
				for(int j = 0;j<vec.size();j++)
				{
					string y  = vec[j];
					int a =0;
					int b =0;
					string ans;
					for(int i =0;i<x.size();i++)
					{
						if(x[i] == '0')
						{
						ans+='-';	a++;
						}	
						else
						ans+=y;
						
					}
					recurse(a,ans);
				}
			n--;	
		}
	}
	return 0;
}