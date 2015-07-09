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
int main()
{
	int m,n,p;
	cin>>m>>n>>p;
	while(m || n || p)
	{
		vector<string>vec;
		for(int i =0;i<m;i++)
		{
			string s;
			cin>>s;
			//cout<<s<<endl;
			vec.PB(s);
		}
		int**visited = (int**)malloc(sizeof(int)*m);
		for(int i =0;i<m;i++)
			visited[i]   =  (int*)malloc(sizeof(int)*n);
		for(int i =0;i<m;i++)
			for(int j =0;j<n;j++)
			visited[i][j] =  0;
			int new_i = 0;
			int new_j = p-1;
			visited[new_i][new_j] = 0;
			int ans =0;int prev =0;
			bool bt =true;
		while(new_i>=0 && new_i<m && new_j>=0 && new_j<n)
		{
			int k = visited[new_i][new_j];
			if(vec[new_i][new_j] == 'S')
			{
				new_i = new_i+1;
			}
			else if(vec[new_i][new_j] == 'N')
			{
				new_i = new_i-1;
			}
			else if(vec[new_i][new_j] == 'E')
			{
				new_j = new_j+1;
			}
			else if(vec[new_i][new_j] == 'W')
			{
				new_j = new_j-1;
			}
			if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && visited[new_i][new_j]>0)
			{
				ans = k- visited[new_i][new_j]+1;
				prev = visited[new_i][new_j];
				bt =false;
				break;
			}
			if(!(new_i>=0 && new_i<m && new_j>=0 && new_j<n ))
			{
				ans =k+1;
				break;
			}
			else
			{
				visited[new_i][new_j] = k+1;
				}
		}
		if(bt)
		cout<<ans<<" step(s) to exit"<<endl;
		else
		cout<<prev<<" step(s) before a loop of "<<ans<<" step(s)"<<endl; 
		cin>>m>>n>>p;
	}
	return 0;
}