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
		int arr[30][30];
		void init()
		{
			for(int i =0;i<30;i++)
			{
				for(int j =0;j<30;j++)
				arr[i][j] = 0;
			}
		}
		bool check(vector<pair<int ,int> >val,int x,int y)
		{
			for(int i =0;i<val.size();i++)
			{
				if(make_pair(min(x,y),max(x,y))==val[i])
				return false;
			}
			return true;
		}
		int ans;
		void DFS(int i,int n,vector<pair<int ,int> >val)
		{
			if(ans<val.size())
			ans =val.size();
			for(int j =0;j<n;j++)
			{
				if(arr[i][j] ==1 && check(val,i,j))
				{
					vector<pair<int ,int> >visit = val;
					visit.PB(make_pair(min(i,j),max(i,j)));
					DFS(j,n,visit);
				}
			}
		}
int main()
{
	int m ,n;
	scanf("%d%d",&m,&n);
	while(m!=0 && n!=0)
	{
		init();
		for(int i =0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			arr[x][y] =1;
			arr[y][x] = 1;
		}
		ans =0;
		for(int i =0;i<m;i++)
		{
		vector<pair<int ,int> >val;
		DFS(i,m,val);
		}
		cout<<ans<<endl;
		cin>>m>>n;
	}
	return 0;
}