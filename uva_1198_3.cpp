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

char s[1005];
int main()
{
	int n =0;
	while(scanf("%d",&n)==1)
	{
	gets(s);
	memset(graph,10000,sizeof(graph));
	for(int i =0;i<n;i++)
	{
		gets(s);
		//cout<<s<<endl;
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
		graph[i][i] = 0;
		for(int j =0;j<n;j++)
		{
			for(int k =0;k<n;k++)
			{
					graph[j][k] = min(graph[j][k],graph[j][i] + graph[i][k]);
			}
		}
	}
	int h =0;
	scanf("%d",&h);
	while(getchar() != '\n');
	//cout<<h<<"--"<<endl;
	for(int k =0;k<h;k++)
	{
		 gets(s);
		 int i =0;
		// printf("%s\n",s);
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
			
			vector<int>sett(n);
			for(int i =0;i<D.size();i++)
			sett[D[i]] =1;
			for(int i =0;i<D.size();i++)
			{	
				for(int j =0;j<D.size();j++)
				{
					for(int k =0;k<n;k++)
					{
						if(graph[D[i]][D[j]] == graph[D[i]][k]+graph[k][D[j]])
						sett[k] =1;
					}
				}
			}
			int c =0;
			for(int i =0;i<n;i++)
			{
				if(sett[i] ==1)
				c++;
			}
			if(c==n)
			cout<<"yes"<<endl;
			else
			cout<<"no"<<endl;
	}
	}
	return 0;
}