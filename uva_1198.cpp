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
int graph[50][50];
vector<int>parent[50][50];
char s[1005];
void init()
{
	for(int i =0;i<50;i++)
	{
		for(int j =0;j<50;j++)
		{
			graph[i][j] = INF;
			vector<int>vec;
			parent[i][j] = vec;
		}
		graph[i][i] =0;
	}
}
bool comp(vector<int>temp,int n)
{
	if(temp.size()==n)
	return true;
	else
	return false;
}
bool now_check(vector<int>temp,int n)
{
	for(int i =0;i<temp.size() && !comp(temp,n);i++)
	{
		for(int j =i+1;j<temp.size() && !comp(temp,n);j++)
		{
			vector<int>vec = parent[i][j];
			for(int i =0;i<vec.size() && !comp(temp,n);i++)
			temp.PB(vec[i]);
		}
	}
	if(comp(temp,n))
	return true;
	else
	return false;
}
int main()
{
	int n =0;
	cin>>n;
	init();

	for(int i =0;i<n;i++)
	{
		gets(s);
		int f = 0, tmp = 0;
            for(int j = 0; s[j]; j++) {
                if(s[j] >= '0' && s[j] <= '9')
                    tmp = tmp*10 + s[j]-'0', f = 1;
                else {
                    if(f) {
                        graph[i][tmp-1] = graph[tmp-1][i] = 1;
                        tmp = 0, f = 0;
                    }
                }
            }
            if(f) {
                graph[i][tmp-1] = graph[tmp-1][i] = 1;
            }
	}
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			for(int k =0;k<n;k++)
			{
				if(graph[j][k] < graph[j][i] + graph[i][k])
				{
					graph[j][k] = graph[j][i] + graph[i][k];
					vector<int>vec;
					vec.PB(i);
					parent[j][k] = vec;
				}
				else if(graph[j][k] == graph[j][i] + graph[i][k])
				{
					parent[j][k].PB(i);
				}
			}
		}
	}
	int h =0;
	scanf("%d",&h);
	while(getchar() != '\n');
	cout<<h<<"--"<<endl;
	for(int i =0;i<h;i++)
	{
		 gets(s);
		 printf("%s\n",s);
            int f = 0, tmp = 0;
            vector<int>D;
            for(i = 0; s[i]; i++) {
                if(s[i] >= '0' && s[i] <= '9')
                    tmp = tmp*10 + s[i]-'0', f = 1;
                else {
                    if(f) {
                        D.PB(tmp-1);
                        tmp = 0, f = 0;
                    }
                }

            }
            if(f) {
                 D.PB(tmp-1);
            }
		bool ch = now_check(D,n);
		if(ch)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}