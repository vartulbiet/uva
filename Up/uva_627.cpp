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
#define INF 1<<10
using namespace std;
int graph[350][350];

void BFS(int s,int d,vector<int>&arr)
{
	queue<int>q;
	q.push(s);bool bt =true;
	vector<bool>visited(350);
	for(int i =0;i<350;i++)
		visited[i] = false;
	visited[s] = true;
	while(!q.empty() && bt)
	{
		int g = q.front();
		q.pop();
		//cout<<g<<" ";
		for(int i =0;i<350;i++)
		{
			if(graph[g][i] == 1 && visited[i] == false)
			{
				arr[i] = g;
				q.push(i);
				visited[i] = true;
				if(i == d)
				{
					bt= false;
					break;
				}
			}
		}
	}
	//cout<<endl;
}
int main()
{
	int n =0;
	while(scanf("%d",&n) ==1)
	{
		cout<<"-----"<<endl;
		memset(graph,0,sizeof(graph));
		for(int i =0;i<=n;i++)
		{
		char line[150], *tok;
			gets(line);int j;
            tok = strtok(line, " ,-");
            while ((tok = strtok(NULL, " ,-")) != NULL) {
                sscanf(tok, "%d", &j);
               graph[i][j]=1;
		}
		}
		int m =0;
		cin>>m;
		for(int i =0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			vector<int>temp(350);
			for(int i =0;i<350;i++)
			{
				temp[i] = -1;
			}
			BFS(x,y,temp);
			//cout<<"hi";
			vector<int>ans;
			bool bt =true;
			while(y !=x)
			{
				if(y ==-1){
					bt= false;
				break;}
				ans.PB(y);
				y = temp[y];
			}
			ans.PB(x);
			reverse(ans.begin(),ans.end());//cout<<"hi";
			if(!bt)
			cout<<"connection impossible"<<endl;
			else
			{
				for(int i =0;i<ans.size();i++)
				{
					cout<<ans[i];
					if(i!=ans.size()-1)
					cout<<" ";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}