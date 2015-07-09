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

int main()
{
	int n =0;
	cin>>n;
	while(n--)
	{
		int sz,x,y;
		cin>>sz>>x>>y;
		vector<int>arr;
		for(int i =0;i<sz;i++)
		{
			arr.PB(i);
		}
		int ans = 0;
		do
		{
			int c = 1,d = 1;
			for(int i = 0;i<=sz-1;i++)
				cout<<arr[i];
			cout<<endl;
			for(int i = 0;i<sz-1;i++)
			{
				if(arr[i]<arr[i+1])
					c++;
				else
					break;
			}
			for(int i = sz-1;i>0;i--)
			{
				if(arr[i]<arr[i-1])
					d++;
				else
					break;
			}
			cout<<c<<"  "<<d<<endl;
			if(c == x && d ==y)
				ans++;
		}
		while(next_permutation(arr.begin(),arr.end()));
		cout<<ans<<endl;
	}
	return 0;
}