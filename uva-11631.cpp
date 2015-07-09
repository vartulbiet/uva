#include <cmath>
#include<list>
#include <cstdio>
#include <vector>
#include<queue>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;

int m;
int ans =0;
int find_set(vector<int>&arr,int m)
{
	if(arr[m] == m)
	return m;
	else
	return arr[m] = find_set(arr,arr[m]);
}
void merge_set(vector<int>&arr,int m,int n)
{
	arr[find_set(arr,m)] = find_set(arr,n);
}


int main()
{
	int n;
	cin>>m>>n;
	
	while(m!=0 || n!=0)
	{
		int total =0;
		
		priority_queue<pair<int,pair<int,int> > >vec;
		for(int j =0;j<n;j++)
		{
			int a,b,c;
			cin>>a>>b>>c;
		total +=c;
			
			pair<int,pair<int,int> >p;
                    pair<int,int>x;
                    x.first= a;
                    x.second =b;
                    p.first =-c;
                    p.second =x;
                    vec.push(p);

		}
    vector<int>arr;
	for(int i =0;i<m;i++)
	arr.push_back(i);
	ans =0;
	//sort(vec.begin(),vec.end());
	while(vec.size()!=0)
	{
		pair<int,pair<int,int> >p = vec.top();
		vec.pop();
		if(find_set(arr,p.second.first)!=find_set(arr,p.second.second))
		{
			ans +=p.first;
			merge_set(arr,p.second.first,p.second.second);
			//cout<<p.second.first<<"--"<<p.second.second<<endl;
		}
	}
		cout<<total+ans<<endl;
		cin>>m>>n;
	}
	return 0;
}