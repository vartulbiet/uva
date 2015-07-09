#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
#include<map>
#include<cstdio>
#define INF 1<<20
#include<queue>
#include<algorithm>
using namespace std;
int arr[100][100];


int n;

void init()
{
	for(int i =0;i<100;i++)
	{
		for(int j =0;j<100;j++)
		{
			if(i ==j)
			{
			arr[i][j] = 0;
			}
			else
			{
			arr[i][j] = INF;
			}
		}
	}
}
void floyd_warshall()
{
	for(int k =0;k<n;k++)
	{
		for(int i =0;i<n;i++)
		{
			for(int j =0;j<n;j++)
			{	
				arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);	
			}
		}
	}
}
int main()
{
	int x =0;
	int r =1;
	cin>>x;
	while(x>0)
	{
		cin>>n;
		int m;
		cin>>m;
		init();
		for(int i =0;i<m;i++)
		{
			int a,b;cin>>a>>b;
			arr[a][b] = 1;
			arr[b][a] = 1;
		}
		floyd_warshall();
		
		int s,t;
		cin>>s>>t;
		int ans =0;
		for(int i =0;i<n;i++)
		{
			
				ans = max(ans,arr[s][i]+arr[i][t]);
			
		}
		cout<<"Case "<<r<<": "<<ans<<endl;
		x--;
		r++;
	}
	return 0;
}