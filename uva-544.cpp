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
int arr[205][205];
void init()
{
for(int i =0;i<a;i++)
{
	for(int j =0;j<a;j++)
	arr[i][j] = 0;
}
}
void floyd_warshall()
{
	for(int k =0;k<a;k++)
	{
		for(int i =0;i<a;i++)
		{
			for(int j =0;j<a;j++)
			{
				if(arr[i][j]<min(arr[i][k],arr[k][j]))
					arr[i][j] = min(arr[i][k],arr[k][j]);
			}
		}
	}
}
int main()
{
	int b;
	cin>>a>>b;
	int x =1;
	while(a!=0 || b!=0)
	{
		init();
		map<string,int>mymap;
		int k =0;
		for(int i =0;i<b;i++)
		{
			string x,y;
			int c;
			cin>>x>>y>>c;
			if(mymap.find(x)==mymap.end())
			mymap[x] = k++;
			if(mymap.find(y)==mymap.end())
			mymap[y] = k++;
			arr[mymap[x]][mymap[y]] = c;
			arr[mymap[y]][mymap[x]] = c;
		}
		floyd_warshall();
		string c,d;
		cin>>c>>d;
		cout<<"Scenario #"<<x++<<endl;
		cout<<arr[mymap[c]][mymap[d]]<<" tons"<<endl;
		cout<<endl;
		cin>>a>>b;
	}
	return 0;
}