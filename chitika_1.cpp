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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
bool bt;
void DFS(stack<int>st,vector<bool>visited,vector<int>arr)
{
	if(st.size() == arr.size()-1)
	{
		while(!st.empty())
			{
				cout<<st.top()<<"->";
				st.pop();
			}
			cout<<endl;
			bt =true;
			return;
	}
	else
	{
 		int n = arr.size();
		bool bt = true;
		for(int i =1;i<n;i++)
		{
			if(arr[i] == st.top() && !visited[i])
			{
				stack<int>temp = st;
				
				temp.push(i);
				visited[i] = true;
				DFS(temp,visited,arr);
				visited[i] = false;
				
			}
		}
	}
}
int main()
{
	int n =0;
	cin>>n;
	vector<int>arr(n+1);
	for(int i =0;i<n;i++)
	{
		int ind,inp =0;
		cin>>ind>>inp;
		arr[ind] = inp;
	}
	bt =false;
	for(int i = 1 ;i<=n;i++)
	{
		if(arr[i] == 0)
		{
			vector<bool>visited(n+1);
			fill(visited.begin(),visited.end(),false);
			visited[i] = true;
			
			stack<int>st;st.push(i);
			DFS(st,visited,arr);
		}
	}
	if(!bt)
	cout<<"Not possible"<<endl;
	return 0;
}