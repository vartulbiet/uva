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
 int arr[105][105];
 vector<string>brr;
 void init()
 {
	for(int i =0;i<105;i++)
	{
		for(int  =0;j<105;j++)
		arr[i][j] =0;
	}
 }
 bool visited[105];
 int n;
 void topo_sort()
 {
	for(int i =0;i<n;i++)
	{
		if(visited[i]==false)
		do_topo(i);
	}
 }
 
 void do_topo(int i)
 {
	visited[i] = true;
	for(int k =0;k<n;k++)
	{
		if(arr[i][k] == 1&& visited[k]==false)
		do_topo(k);
	}
	cout<<brr[i]<<" ";
 }
int main()
{
		while(scanf("%d",&n)!=EOF)
		{
			init();
			visited ={false};
			map<string,int>mymap;
			string s;
			for(int i =0;i<n;i++)
			{
				getline(cin,s);
				mymap[s] =i;
				brr.PB(s);
			}
			int m =0;
			cin>>m;
			for(int i =0;i<m;i++)
			{
				string x,y;
				cin>>x>>y;
				arr[mymap[y]][mymap[x]] =1;
			}
			topo_sort();
			brr.erase(brr.begin(),brr.end());
		}
		return 0;
}