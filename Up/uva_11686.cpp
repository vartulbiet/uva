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
	vector<int>vec;
};
vector<struct node>vect(5000000);
vector<int>st;
vector<int>visit(5000000);
bool bt;
void do_topo(int n,int s)
{
if(visit[s] == 1){
bt =false;
return;}
if(visit[s] == 2)
return;
	visit[s] =  1;
	for(int i =0;i<vect[s].vec.size();i++)
	{
			do_topo(n,vect[s].vec[i]);
	}
	visit[s] =  2;
	st.PB(s);
}
void topo(vector<struct node>vect,int n)
{
	fill(visit.begin(),visit.end(),0);
	for(int i =0;i<n;i++)
	{
			do_topo(n,i);
	}
	if(!bt)
	{
	printf("IMPOSSIBLE\n");
	}
	else
	{
		for(int i =0;i<n;i++)
			printf("%d\n",st[i]+1);
	}
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	while(m || n)
	{
		bt =true;
		for(int i =0;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			vect[y-1].vec.PB(x-1);
		}
		topo(vect,m);
		scanf("%d%d",&m,&n);
	}
	for(int i=0;i<5000000;i++)    vect[i].vec.clear();st.clear();
	return 0;
}