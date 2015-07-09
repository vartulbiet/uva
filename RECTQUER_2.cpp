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

int main()
{
	int n = 0;
	scanf("%d",&n);
	vector< vector< map<int,bool> > >vec;
	for(int i =0;i<n;i++)
	{
		map<int,bool>mymap;
		vector<map<int,bool> >temp;
		for(int j =0;j<n;j++)
		{
			int u;
			scanf("%d",&u);
			mymap[u] =true;
			temp.PB(mymap);
		}
		vec.PB(temp);
		mymap.erase(mymap.begin(),mymap.end());
		temp.erase(temp.begin(),temp.end());
	}
	int m =0;
	scanf("%d",&m);
	for(int jj =0;jj<m;jj++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		map<int,bool>alpha;
		map<int,bool>beta;
		map<int,bool>gamma;
		int ans =0;
		a-=1;b-=1;c-=1;d-=1;
		if(a==c && b==d)
				printf("1\n");
		else
		{
			for(int i =a;i<=c;i++)
			{
				beta = vec[i][d];
				if(i>=0 && b>0)
				{
					alpha = vec[i][b-1];
					for(std::map<int,bool>::iterator it = alpha.begin();it!=alpha.end();it++)
					{
						beta.erase(it->first);
					}
				}
				if(!beta.empty())
				gamma.insert(beta.begin(),beta.end());
			}
			if(!gamma.empty())
			ans = gamma.size();	
			else
			ans =1;
			printf("%d\n",ans);
			alpha.erase(alpha.begin(),alpha.end());
			beta.erase(beta.begin(),beta.end());
			gamma.erase(gamma.begin(),gamma.end());
		}
	}
	vec.erase(vec.begin(),vec.end());
	return 0;
}