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
#define INF 1<<10
using namespace std;
int arr[55][55];
void init()
{
	for(int i =0;i<55;i++)
	{
		for(int j =0;j<55;j++)
		arr[i][j] = INF;
			arr[i][i] =0;
	}

}
int m =0;
void floyd_warshall()
{
	for(int i =0;i<m;i++)
	{
		for(int j =0;j<m;j++)
		{
			for(int k =0;k<m;k++)
			arr[j][k] = min(arr[j][i]+arr[i][k],arr[j][k]);
		}
	}
}
int main()
{
	int n;
	cin>>m>>n;int tc =1;
	while(!(m==0 && n==0))
	{
		map<string,int>mymap;
		int k =0;
		init();
		for(int i =0;i<n;i++)
		{
			string x,y;
			cin>>x>>y;
			if(mymap.find(x)==mymap.end())
			{
				mymap[x] =k++;
			}
			if(mymap.find(y)==mymap.end())
			{
				mymap[y] =k++;
			}
			arr[mymap[x]][mymap[y]] =1;
			arr[mymap[y]][mymap[x]] =1;
		}
		floyd_warshall();
		int nas =0;
		for(int i =0;i<m;i++)
		{
			for(int j =0;j<m;j++)
			{//cout<<arr[i][j]<<" ";
			nas = max(arr[i][j],nas);}
			//cout<<endl;
		}
		cout<<"Network "<<tc++<<": ";
		if(nas==INF)
		cout<<"DISCONNECTED"<<endl;
		else
		cout<<nas<<endl;
		cout<<endl;
		cin>>m>>n;
	}
	return 0;
}