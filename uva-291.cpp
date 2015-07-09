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
#define ull long long int
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
int arr[5][5] = {0,1,1,0,1,
				 1,0,1,0,1,
				 1,1,0,1,1,
				 0,0,1,0,1,
				 1,1,1,1,0
				};
vector<vector<int> >ans;
void DFS(map<pair<int,int>,bool>visited,int s,vector<int>vec,int n)
{
	//cout<<visited.size()<<endl;
	if(n ==visited.size()+1)
	{
		for(int i =0;i<vec.size();i++)
		cout<<vec[i];
		cout<<endl;
		ans.PB(vec);
	}
	else
	{
		for(int i =0;i<5;i++)
		{
			map<pair<int,int>,bool>mymap = visited;
			vector<int>temp = vec;
			if(arr[s][i]==1 && mymap[make_pair(min(s+1,i+1),max(s+1,i+1))] == false)
			{
				mymap[make_pair(min(s+1,i+1),max(s+1,i+1))] = true;
				temp.PB(i+1);
				DFS(mymap,i,temp,n+1);
			}
		}
	}
}

int main()
{
	map<pair<int,int>,bool>visited;
	visited[make_pair(1,2)] = false;visited[make_pair(1,3)] = false;visited[make_pair(1,5)] = false;visited[make_pair(4,5)] = false;visited[make_pair(3,4)] = false;
	visited[make_pair(2,3)] = false;visited[make_pair(3,5)] = false;visited[make_pair(2,5)] = false;
	vector<int>vec;
	vec.PB(0+1);
	DFS(visited,0,vec,1);
	return 0;
}