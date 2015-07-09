#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int findset(int*arr,int i)
{
		if(arr[i] == i)
			return i;
		else
			return findset(arr,arr[i]);
}
void union_set(int*arr,int i,int j)
{
		arr[findset(arr,i)] = findset(arr,j);
}
bool isSameSet(int*arr,int i,int j)
{
		return findset(arr,i)==findset(arr,j);
}
int numberOFSets(int*arr,int n)
{
		int count=0;
		for(int i=1;i<=n;i++)
		{
				if(arr[i]!=i)
					count++;
		}
		return n-count;
}
int main()
{
	bool val = true;
	int j =1;
	while(val)
	{
	int m =0;
	int n =0;
	cin>>n>>m;
	if(m==0&&n==0)
		break;
	int arr[50005];
	arr[0] =-1;

	for(int i=1;i<=n;i++)
		arr[i]=i;
	for(int i=0;i<m;i++)
	{
			int x;int y;
			cin>>x>>y;
			union_set(arr,x,y);
	}
	cout<<"Case "<<j++<<": "<<numberOFSets(arr,n)<<endl;
	}
		return 0;
}