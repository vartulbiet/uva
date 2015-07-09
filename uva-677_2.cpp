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
int arr[11][11];
int num_path;
void init()
{
	for(int i =0;i<11;i++)
	{
		for(int j =0;j<11;j++)
		arr[i][j] = 0;
	}
}
void create_ans(int h,int g,vector<int>ans,bool visit[11])
{
	if(g==0)
	{
		cout<<"(";
		for(int i =0;i<ans.size();i++)
		{
		if(i!=0)
		cout<<",";
		cout<<ans[i]+1;
		}
		cout<<")";
		cout<<endl;
		num_path++;
	}
	else
	{
		int r =ans[ans.size()-1];
		for(int i =0;i<h;i++)
		{
			if(arr[r][i] ==1 && visit[i] == false)
			{
				vector<int>temp = ans;
				temp.PB(i);
				visit[i] = true;
				create_ans(h,g-1,temp,visit);
				visit[i] = false;
			}
		}
		return;
	}
}
int main()
{
	int a;int b;
	int c =0;
	while(scanf("%d%d",&a,&b)==2)
	{
	if(c!=0)
	cout<<endl;
		for(int i =0;i<a;i++)
		{
			for(int j =0;j<a;j++)
			{
				int g;
				cin>>g;
				arr[i][j] = g;
			}
		}

num_path = 0;
		vector<int>ans;
		ans.PB(0);
		bool visit[11];
		fill(visit,visit+11,false);
		visit[0] = true;
		create_ans(a,b,ans,visit);
		if(num_path == 0)
		printf("no walk of length %d\n",b); 
		cin>>c;
	}
	return 0;
}