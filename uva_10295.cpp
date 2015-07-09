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
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	map<string,int>mymap;
	for(int i =0;i<m;i++)
	{
		string x;int y;
		getline(cin,x);
		cin>>x>>y;
		//cout<<x<<y;
		mymap[x] = y;
	}
	for(int j =0;j<n;j++)
	{
		string s;int ans =0;
		cin>>s;
		while(s!=".")
		{
		if(mymap.find(s)!=mymap.end())
		ans+=mymap[s];
		cin>>s;
		}
		cout<<ans<<endl;
	}
	return 0;
}