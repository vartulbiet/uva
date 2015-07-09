#include <vector>
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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int a;
double arr[205][205];
void init()
{
for(int i =0;i<a;i++)
{
	for(int j =0;j<a;j++)
	arr[i][j] = 1<<30;
}
}
double distance_d(pair<int,int>x,pair<int,int>y)
{
	return sqrt((x.first-y.first)*(x.first-y.first) +(x.second-y.second)*(x.second-y.second));
}
void floyd_warshall()
{
	for(int k =0;k<a;k++)
	{
		for(int i =0;i<a;i++)
		{
			for(int j =0;j<a;j++)
			{
				if(arr[i][j]>max(arr[i][k],arr[k][j]))
					arr[i][j] = max(arr[i][k],arr[k][j]);
			}
		}
	}
}
void pp()
{
for(int i =0;i<a;i++)
{
	for(int j =0;j<a;j++)
		cout<<arr[i][j]<<" ";
		cout<<endl;
}
}
int main()
{
	cin>>a;
	int x =1;
	while(a!=0)
	{
		init();
		int k =0;
		vector<pair<int,int> >cood;
		for(int i =0;i<a;i++)
		{
			int x,y;
			cin>>x>>y;
			cood.push_back(make_pair(x,y));
		}
		for(int i =0;i<cood.size();i++)
		{
			for(int j =0;j<cood.size();j++)
			if(i!=j)
			arr[i][j] =distance_d(cood[i],cood[j]);
		}
		floyd_warshall();
		//pp();
		cout<<"Scenario #"<<x++<<endl;
		printf("Frog Distance = %.3lf\n",arr[0][1]);
		cout<<endl;
		cin>>a;
	}
	return 0;
}