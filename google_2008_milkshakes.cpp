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
#define SORT(X) sort(X.begin(),X.end())
using namespace std;
int arr[2005][2005];
vector<int>ans;int c;
void recurse(vector<int>vec,int p,int maxx,int cust)
{
	if(p == cust)
	{
		bool bt = true;
		for(int i =0;i<vec.size() && bt;i++)
		{
			if(vec[i]!=-1)
			bt= false;
		}
		if(!bt)
		{
			int ct =0;
			for(int i =0;i<vec.size();i++)
			{
				if(vec[i] ==1)
				ct++;
			}
			if(ct<c)
			{
			ans =vec;
			c =ct;
			}
		}
	}
	else
	{
		for(int i =0;i<maxx;i++)
		{
			vector<int>temp= vec;
			if((temp[i] ==-1 ||(temp[i] == arr[p][i]))&& arr[p][i]!=-1)
			{
				temp[i] = arr[p][i];
				recurse(temp,p+1,maxx,cust);
			}
		}
	}
}
int main()
{
	int n =0;
	cin>>n;
	int k =1;
	while(n>0)
	{
		memset(arr,-1,sizeof(arr));
		int x,y;
		
		cin>>x>>y;
		c =x;
		
		for(int i =0;i<y;i++)
		{
			int z =0;
			cin>>z;
			for(int j =0;j<z;j++)
			{
				int a,b;
				cin>>a>>b;
				arr[i][a-1] = b;
			}
		}
		
		vector<int>vec(x);
		fill(vec.begin(),vec.end(),-1);
		recurse(vec,0,x,y);
		cout<<"Case #"<<k++<<":";
		if(c == x)
		cout<<" IMPOSSIBLE"<<endl;
		else
		{
			for(int i =0;i<ans.size();i++)
			{
					if(ans[i]==-1)
						cout<<" "<<"0";
					else
				cout<<" "<<ans[i];
			}
			cout<<endl;
		}
		n--;
	}
	return 0;
}