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
struct city
{
	int x;
	int y;
};

/*struct node
{
	double distt;
	int c1;
	int c2;
};
*/
double dist(struct city one,struct city two)
{
	return (double)sqrt((double)(one.x-two.x)*(one.x-two.x) + (double)(one.y-two.y)*(one.y-two.y));
}
int find(int*arr,int i)
{
	if(arr[i] == i)
	return i;
	else return arr[i] =  find(arr,arr[i]);
}
void merge(int*arr,int a,int b)
{
	arr[find(arr,a)] = find(arr,b);
}
void kruskal(priority_queue<pair<double,pair<int,int> > >pq,int*arr,int n)
{
	vector<pair<int,int> >vec;
	while(!pq.empty())
	{
		pair<double,pair<int,int> > u = pq.top();
		int distt = u.first;
		int c1 = u.second.first;
		int c2 =u.second.second;
		pq.pop();
		if(find(arr,c1-1) != find(arr,c2-1))
		{
			merge(arr,c1-1,c2-1);
			if(distt !=0)
			{
				vec.PB(make_pair(c1,c2));
			}
		}
	}
	sort(vec.begin(),vec.end());
	if(vec.size()==0)
	cout<<"No new highways need."<<endl;
	else
	{
		for(int i =0;i<vec.size();i++)
		{
			cout<<vec[i].first<<" "<<vec[i].second<<endl;
		}
	}
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int cities =0;
		cin>>cities;
		vector<struct city>vec;
		while(cities--)
		{
			struct city c; //(struct city)malloc(sizeof(struct city));
			cin>>c.x>>c.y;
			vec.PB(c);
		}
		cities =vec.size();
		priority_queue<pair<double,pair<int,int> > >pq;
		for(int i =0;i<cities;i++)
		{
			for(int j =i+1;j<cities;j++)
			{
				pair<double,pair<int,int> > r ;//= (struct node)malloc(sizeof(struct node)); 
				r.first = -dist(vec[i],vec[j]);
				r.second.first =i+1;
				r.second.second =j+1;
				pq.push(r);
			}
		}
		int m =0;
			cin>>m;
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			pair<double,pair<int,int> >r ;//= (struct node)malloc(sizeof(struct node)); 
				r.first = 0;
				r.second.first =a;
				r.second.second =b;
			pq.push(r);
		}
		int*arr = (int*)malloc(sizeof(int)*cities);
		for(int i =0;i<cities;i++)
		arr[i] = i;
		kruskal(pq,arr,cities);
		if(n!=0)
		cout<<endl;
	}
}