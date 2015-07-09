#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include<string>
#define INF 1<<30
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	string s;
	getline(cin,s);
	while(n>0)
	{
		getline(cin,s);
		int lastd =INF;
		int lasts =INF;
		int ans =INF;
		int i =0;
		for(i =0;i<n;i++)
		{
			if(s[i]=='Z')
			{
			cout<<"0"<<endl;
			break;
			}
			else
			{
				if(s[i]=='R')
				{
					lasts = i;
					if(lastd!=INF)
					{
						ans =min(ans,lasts-lastd);
					}
				}
					if(s[i]=='D')
				{
					lastd = i;
					if(lasts!=INF)
					{
						ans =min(ans,lastd-lasts);
					}
				}
			}
		}
		if(i==n)
			cout<<ans<<endl;
		cin>>n;
getline(cin,s);		
	}
	return  0;
}