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
void update_multiple(vi &arr,int k ,int n)
{
	int i =2;
	while(i*k<=n)
	{
		arr[i*k] =0;
		i++;
	}
}
int main()
{
	int n =0;
	cin>>n;
	vi arr(n+1);
	fill(arr.begin(),arr.end(),1);
	arr[0] =0;arr[1] =0;
	for(int i =1;i<=n;i++)
	{
		if(arr[i] ==1)
		{
			update_multiple(arr,i,n);
		}
	}
	for(int i =0;i<=n;i++)
	if(arr[i])cout<<i<<" ";
	cout<<endl;
}