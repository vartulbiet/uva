#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
#include<map>
#include<cstdio>
#define INF 1<<30
#include<queue>
#include<algorithm>
using namespace std;
int arr[23][23];
map<int,string>mymap;
int n;
void init()
{
	for(int i =0;i<23;i++)
	{
		for(int j =0;j<23;j++)
		{
			if(i ==j)
			arr[i][j] = 0;
			else
			arr[i][j] = INF;
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
			arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
		}
	}
}
int main()
{
	int m;
	cin>>n>>m;int j =1;
	while(n!=0 || m!=0)
	{
		string s;
		init();
		getline(cin,s);
		for(int i =0;i<n;i++)
		{
			getline(cin,s);
			mymap[i] = s;
		}
		for(int k =0;k<m;k++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			arr[a-1][b-1] = c;
			arr[b-1][a-1] = c;
		}
		floyd_warshall();
		int ans =INF;int t;
		for(int k =0;k<n;k++)
		{
			int sum =0;
			for(int i =0;i<n;i++)
			{
			sum+=arr[k][i];
			}
			if(sum<ans)
			{
				ans =sum;
				t= k;
			}
		}
		cout<<"Case #"<<j<<" : "<<mymap[t]<<endl;
		cin>>n>>m;
		mymap.erase(mymap.begin(),mymap.end());
		j++;
	}
	return 0;
}