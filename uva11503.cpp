#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
int findset(int*arr,int i)
{
		if(arr[i] == i)
			return i;
		else
			return arr[i] = findset(arr,arr[i]);
}
void union_set(int*arr,int i,int j)
{
		arr[findset(arr,i)] = findset(arr,j);
}
bool isSameSet(int*arr,int i,int j)
{
		return findset(arr,i)==findset(arr,j);
}
int count(int *arr,int i,int j)
{
		int c =0;
		for(int k=0;k<i;k++)
		{
				if(findset(arr,arr[k]) ==arr[j])
					c++;
		}
		return c;
}
int main()
{
		int kase =0;
		int i =1;
		cin>>kase;
		while(i<=kase)
		{
			int num =0;
			cin>>num;
			map<string,int>mymap;
			int t =0;
			int arr[100005];
			for(int i=0;i<num;i++)
			{
					string s,r;
					cin>>s>>r;
					bool val =true;
					if(mymap.find(s)==mymap.end())
					{
							mymap[s] =t;
							arr[t] =t++;
							val =false;
					}
					if(mymap.find(r)==mymap.end())
					{
							mymap[r] =t;
							arr[t] =t++;
							val =false;
					}
					union_set(arr,mymap[s],mymap[r]);
					cout<<count(arr,t,mymap[s])<<endl;
			}
			i++;
		}
		return 0;
}