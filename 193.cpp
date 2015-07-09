#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#define REP(i, a, b) for ( int i = int(a); i <= int(b); i++ )
#define PB push_back
#define MP make_pair
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define MAXN 1000
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define INF 1<<30
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;


vector< vector<int> >graph;
int nodes;
vector<int>ans;
int max_ans;

void recurse(int curr_node,vector<int>&arr_nodes,bool color_to_apply,vector<bool>&visited)
{
		if(max_ans<arr_nodes.size())
		{
			ans = arr_nodes;
			max_ans = arr_nodes.size();
		}

		if(visited[curr_node] == true)
			return;
		visited[curr_node] = true;
		if(color_to_apply == true)
		{
			arr_nodes.PB(curr_node);
		}
		for(int j = 0;j<nodes;j++)
		{
			if(visited[j] == false && graph[curr_node][j] == 1)
			{
				recurse(j,arr_nodes,!color_to_apply,visited);
			}
		}

}
int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int edges;
		max_ans = 0;
		cin>>nodes>>edges;

		for(int i =0;i<nodes;i++)
			ans.PB(0);

		vector<int>arr(nodes);
		for(int i =0;i<nodes;i++)
			graph.PB(arr);

		for(int i =0;i<nodes;i++)
		{
			for(int j =0;j<nodes;j++)
				graph[i][j] = 0;
		}

		for(int x = 0;x<edges;x++)
		{
			int a,b;
			cin>>a>>b;
			graph[a-1][b-1] = 1;
			graph[b-1][a-1] = 1;
		}

		vector<int>blacks;
		vector<bool>visited(nodes);
		recurse(0,blacks,true,visited);

		cout<<max_ans<<endl;
		for(int i =0;i<max_ans-1;i++)
			cout<<ans[i]+1<<" ";
			cout<<ans[max_ans-1]+1;
		cout<<endl;

		graph.erase(graph.begin(),graph.end());
		ans.erase(ans.begin(),ans.end());
	}
	return 0;
}