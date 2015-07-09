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
		int store[30005];
		for(int i=0;i<30005;i++)
			store[i] = 0;
		for(int i=1;i<=n;i++)
		{
				store[findset(arr,arr[i])]++;
		}

		for(int i=0;i<30005;i++)
			if(store[i]>count)
				count = store[i];
		return count;
}
int main()
{
	int j =1;int k=1;
	cin>>j;
	while(k++<=j)
	{
	int m =0;
	int n =0;
	cin>>n>>m;
	int arr[30005];
	arr[0] =-1;
	for(int i=1;i<=n;i++)
		arr[i]=i;
	for(int i=0;i<m;i++)
	{
			int x;int y;
			cin>>x>>y;
			union_set(arr,x,y);
	}
	cout<<numberOFSets(arr,n)<<endl;
	}
		return 0;
}