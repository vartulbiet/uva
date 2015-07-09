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
using namespace std;
int arr[15][15];
void init()
{
	for(int i =0;i<15;i++)
	{
		for(int j =0;j<15;j++)
		arr[i][j]  =1<<15;
		arr[i][i] =0;
	}
}
void floyd_warshall(int n)
{
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			for(int k =0;k<n;k++)
			{
				arr[j][k] = min(arr[j][i]+arr[i][k],arr[j][k]);
			}
		}
	}
}
vector<int>hold;
int dp[1<<16];
int build(int pN, int ot) {
    if(pN == 0)
        return 0;
    if(dp[pN] != -1)
        return dp[pN];
    int i, j, tmp;
    dp[pN] = 0xfffffff;
    for(i = 0; i < ot; i++) {
        if(pN&(1<<i)) {
            for(j = i+1; j < ot; j++) {
                if(pN&(1<<j)) {
                    tmp = build(pN-(1<<i)-(1<<j), ot);
                    dp[pN] = min(dp[pN], tmp+arr[hold[i]][hold[j]]);
                }
            }
            break;
        }
    }
    return dp[pN];
}
int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		int m =0;
		cin>>m;
		init();
		int total =0;
		 memset(dp, -1, sizeof(dp));	
		map<int,int>count;
		for(int i =0 ;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			total+=c;
			if(arr[a-1][b-1]>c)
			arr[a-1][b-1] =c;
			if(arr[b-1][a-1]>c)
			arr[b-1][a-1] =c;
			count[a-1]++;
			count[b-1]++;
		}
		floyd_warshall(n);
		
		for(std::map<int,int>::iterator it =count.begin();it!=count.end();it++)
		{
			if(it->second%2!=0)
			hold.PB(it->first);
		}
		total+=build((1<<hold.size())-1,hold.size());
		cout<<total<<endl;
		hold.erase(hold.begin(),hold.end());	
		cin>>n;
	}
	return 0;
}