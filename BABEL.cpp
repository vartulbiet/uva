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
#define INF 1<<20
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
map<string,int>mymap;
vector<pair<string,string>,string>vec;
string f,l;
vector<string>ans;
void DFS()
{
	if(f == l)
	{
		
	}
}
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		cin>>f>>l;
		for(int i =0;i<n;i++)
		{
			string s,r,t;
			cin>>s>>r>>t;
			mymap[s][r] =t;
		}
		DFS();
		vec.clear(vec.begin(),vec.end());
	}
	return 0;
}