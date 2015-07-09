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
int brr[100][100];

int n;

void init()
{
	for(int i =0;i<100;i++)
	{
		for(int j =0;j<100;j++)
		{
			if(i ==j)
			{
			arr[i][j] = 0;brr[i][j] = 0;
			}
			else
			{
			arr[i][j] = INF;brr[i][j] = INF;
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
				if(arr[i][j]>arr[i][k]+arr[k][j])
				{
				arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
				brr[i][j] = min(brr[i][j],brr[i][k]+brr[k][j]);
				}
				else if(arr[i][j]==arr[i][k]+arr[k][j])
				brr[i][j] = min(brr[i][j],brr[i][k]+brr[k][j]);
			}
		}
	}
}
int main()
{
	int x =0;
	cin>>x;
	while(x>0)
	{
		cin>>n;
		int m;
		init();
		cin>>m;
		for(int i =0;i<m;i++)
		{
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			if((c<arr[a-1][b-1])|| (c==arr[a-1][b-1] && d<brr[a-1][b-1]))
			{
			arr[a-1][b-1] =c;
			brr[a-1][b-1] =d;
			arr[b-1][a-1] =c;
			brr[b-1][a-1] =d;
			}
			
		}
		floyd_warshall();
		int v =0;
		cin>>v;
		for(int i =0;i<v;i++)
		{
			int d,e;
			cin>>d>>e;
			if(arr[d-1][e-1]==INF)
			cout<<"No Path."<<endl;
			else
			cout<<"Distance and time to reach destination is "<<brr[d-1][e-1]<<" & "<<arr[d-1][e-1]<<"."<<endl;
		}
		if(x!=1)
		cout<<endl;
		x--;
	}
	return 0;
}