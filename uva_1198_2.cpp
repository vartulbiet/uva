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
struct node
{
		set<int> s;
};
int graph[50][50];
node arr[50][50];
char s[1005];
int main()
{
	int n =0;
	cin>>n;gets(s);
	memset(graph,10000,sizeof(graph));
	for(int i =0;i<n;i++)
	{
		gets(s);
		cout<<s<<endl;
		int f = 0, tmp = 0;
            for(int j = 0; s[j]; j++) {
                if(s[j] >= '0' && s[j] <= '9')
                    tmp = tmp*10 + s[j]-'0', f = 1;
                else {
                    if(f) {
                        graph[i][tmp-1] = graph[tmp-1][i] = 1;
						set<int>sets;
						sets.insert(i);sets.insert(tmp-1);
						arr[i][tmp-1].s = sets;arr[tmp-1][i].s = sets;
                        tmp = 0, f = 0;
                    }
                }
            }
            if(f) {
                graph[i][tmp-1] = graph[tmp-1][i] = 1;
				set<int>sets;
				sets.insert(i);sets.insert(tmp-1);
				arr[i][tmp-1].s = sets;arr[tmp-1][i].s = sets;
            }
	}

	for(int i =0;i<n;i++)
	{
		graph[i][i]= 0;
		for(int j =0;j<n;j++)
		{
			for(int k =0;k<n;k++)
			{
				if(graph[j][k] > graph[j][i] + graph[i][k])
				{
					graph[j][k] = graph[j][i] + graph[i][k];
					set<int>ss;
					ss.insert(arr[j][i].s.begin(),arr[j][i].s.end());
					ss.insert(arr[i][k].s.begin(),arr[i][k].s.end());
					arr[j][k].s =ss;
				}
				if(graph[j][k] == graph[j][i] + graph[i][k])
				{
					graph[j][k] = graph[j][i] + graph[i][k];
					set<int>ss;
					ss.insert(arr[j][i].s.begin(),arr[j][i].s.end());
					ss.insert(arr[i][k].s.begin(),arr[i][k].s.end());
					arr[j][k].s =ss;
				}
			}
		}
	}
	int h =0;
	scanf("%d",&h);
	while(getchar() != '\n');
	cout<<h<<"--"<<endl;
	for(int k =0;k<h;k++)
	{
		 gets(s);
		 int i =0;
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
			set<int>sett;
			for(int i =0;i<D.size();i++)
			{
				for(int j =0;j<D.size();j++)
				{
					sett.insert(arr[i][j].s.begin(),arr[i][j].s.end());
				}
			}
			if(sett.size()==n)
			cout<<"Yes"<<endl;
			else
			cout<<"No"<<endl;
	}
}