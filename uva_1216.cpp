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
#define MP make_pair
#define INF 1<<30
using namespace std;
double dist(pair<int,int>f,pair<int,int>g)
{
	return hypot((f.first-g.first),(f.second-g.second));
}
vector<int>DS;
int find(int t)
{
	if(t == DS[t])
	return t;
	else DS[t] = find(DS[t]);
}
void merge(int x,int y)
{
	DS[find(x)] = find(y);
}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int w =0;
		cin>>w;
		int x,y;
		cin>>x;
		vector<pair<int,int> >vec;
		while(x!=-1)
		{
			cin>>y;
			vec.PB(MP(x,y));
			cin>>x;
		}
		for(int i =0;i<=vec.size();i++)
		DS.PB(i);
		vector<pair<double,pair<int,int> > >arr;
		for(int i =0;i<vec.size();i++)
		{
			for(int j =i+1;j<vec.size();j++)
			{
				//cout<<dist(vec[i],vec[j])<<endl;
				arr.PB(MP(dist(vec[i],vec[j]),MP(i,j)));
			}
		}
		sort(arr.begin(),arr.end());
		int d = vec.size();
		double sum =0;bool flag =true;
		for(int i =0;i<arr.size();i++)
		{
			if(find(arr[i].second.first) != find(arr[i].second.second))
			{
				sum = max(sum,arr[i].first);
				d--;
				merge(arr[i].second.first,arr[i].second.second);
			}
			if(d == w){
                sum= arr[i].first;
                flag=false;
                break;
            }
		}
		if(flag) 
		 sum=arr[arr.size() - 1].first;
		printf("%ld\n",(long int)ceil(sum));
		DS.clear();
	}
	return  0;
}