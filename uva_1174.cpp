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
#define INF 1<<30
using namespace std;
int find_set(int i,vector<int>&arr)
{
	if(arr[i] == i)
	return i;
	else
	return arr[i] = find_set(arr[i],arr);
}
void merge_set(int a,int b,vector<int>&arr)
{
	arr[find_set(a,arr)] =  find_set(b,arr);
}
void kruskal(priority_queue< pair <int,pair<int,int> > >pq,int n)
{
	vector<int>arr(n);
	for(int i =0;i<n;i++)
	arr[i] = i;
	int cost = 0;
	while(!pq.empty())
	{
		pair <int,pair<int,int> >pp = pq.top();
		pq.pop();
		int ct = pp.first;
		if(find_set(pp.second.first,arr) != find_set(pp.second.second,arr))
		{
			merge_set(pp.second.first,pp.second.second,arr);
			cost +=(-ct);
		}
	}
	cout<<cost<<endl;
}
int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		//string h ;
		//getline(cin,h);
		//getline(cin,h);
		int city =0;
		cin>>city;
		int conn =0;
		cin>>conn;
		//cout<<city<<conn<<endl;
		map<pair<string,string>,int>mymap;
		map<string,int>cities;
		int j =0;
		for(int i =0;i<conn;i++)
		{
			string a,b;
			int c;
			cin>>a>>b>>c;
			//cout<<a<<b<<c;
			if( mymap.find(make_pair(a,b)) == mymap.end() 
			||  mymap.find(make_pair(b,a))==mymap.end() 
			|| (mymap.find(make_pair(a,b)) != mymap.end() && mymap[make_pair(a,b)] >c)
			||  (mymap.find(make_pair(b,a)) != mymap.end() &&mymap[make_pair(b,a)] > c))
			mymap[make_pair(a,b)] = c;
			if(cities.find(a) == cities.end())
			{
				cities[a] = j++;
			}
			if(cities.find(b) == cities.end())
			{
				cities[b] = j++;
			}
		}
		priority_queue< pair <int,pair<int,int> > >pq;
		for(std::map<pair<string,string>,int>::iterator it =  mymap.begin();it!=mymap.end();it++)
		{
			pq.push(make_pair(-it->second,make_pair(cities[it->first.first],cities[it->first.second])));
		} 
		kruskal(pq,city);
		if(n>1)
		cout<<endl;
		n--;
	}
	return  0;
}