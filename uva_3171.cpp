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
#define graphAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
map<int,char>mymap;
int graph[30][30];
int arr[30];
void init()
{
	for(int  i=0;i<30;i++)
	{
		for(int j =0;j<30;j++)
			graph[i][j] =-1;
			arr[i] =i;
			mymap[i] =('A'+i);
	}
}

int find_set(int a)
{
	if(arr[a]==a)
	return a;
	else
	return arr[a] = find_set(arr[a]);
}
void merge(int a,int b)
{
	arr[find_set(a)] = find_set(b);
}

void kruskal(priority_queue<pair<int,pair<int,int> > >pq)
{
	vector<pair<int,pair<int,int> > >vec;
	while(!pq.empty())
	{
		pair<int,pair<int,int> > uu = pq.top();
		pq.pop();
		int yy = uu.first;
		if(find_set(uu.second.second) != find_set(uu.second.first))
		{
			//	cout<<uu.first<<"   "<<uu.second.first<<"  "<<uu.second.second<<endl;
			merge(uu.second.second,uu.second.first);
			uu.first =abs(yy);
			vec.PB(uu);
		}
	}
	sort(vec.begin(),vec.end());
	for(int i =0;i<vec.size();i++)
	{
		pair<int,pair<int,int> > uu = vec[i];
		cout<<mymap[uu.second.first]<<"-"<<mymap[uu.second.second]<<" "<<uu.first<<endl;
	}
}

int main()
{
	int n =0;
	cin>>n;
	int tc =1;
	while(n--)
	{
		int k;
		cin>>k;
		init();
		priority_queue<pair<int,pair<int,int> > >pq;
		for(int i =0;i<k;i++)
		{
			for(int j =0;j<k;j++)
			{
				if(j!=0)
				{
					char c;
					cin>>c;
//cout<<c<<" ";
				}
				int y =0;
				cin>>y;
//cout<<y;
				graph[i][j] =y;
				if(graph[j][i]==-1 && y>0)
				{
					pq.push(make_pair(-y,make_pair(i,j)));
				}
			}
		}
		cout<<"Case "<<tc++<<":"<<endl;
		kruskal(pq);
	}
	return 0;
}