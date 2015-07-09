#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
#include<map>
#include<cstdio>
#define INF 1<<10
#include<algorithm>
using namespace std;
int arr[10][10];
int n;bool first;
int pred[10][10];
void init()
{
	for(int i =0;i<10;i++)
	{
		for(int j =0;j<10;j++)
		{
		if(i==j)
		arr[i][j] =0;
		else
		arr[i][j] =INF;
		pred[i][j] =-1;
		}
	}
}
void path(int i,int j)
{
    if(pred[i][j]==-1)
        if(first)
        {
            cout<<i+1<<" "<<j+1;
            first=false;
        }
        else
        {
            cout<<" "<<j+1;
        }
    else
    {
        path(i,pred[i][j]);
        path(pred[i][j],j);
    }
}
void floyd_warshall()
{
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			for(int k =0;k<n;k++)
			{
			if(arr[j][k]>(arr[j][i]+arr[i][k]))
			{
			arr[j][k] = arr[j][i]+arr[i][k];
			pred[j][k] = i;
			}
			}
		}
	}
}
int main()
{
	cin>>n;int tt =1;
	while(n!=0)
	{
		init();
		first =true;
		for(int i =0;i<n;i++)
		{
			int x =0;
			cin>>x;
			for(int j =0;j<x;j++)
			{
				int a,b;
				cin>>a>>b;
				
				arr[i][a-1] = b; 
				
			}
		}
		int p,q;
		cin>>p>>q;
		floyd_warshall();
		
		cout<<"Case "<<tt++<<": Path = ";path(p-1,q-1);
		cout<<"; "<<arr[p-1][q-1]<<" second delay"<<endl;
		cin>>n;
	}
	return 0;
}