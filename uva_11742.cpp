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
	int a,b,c;
};
int  main()
{
	int n,m;
	cin>>n>>m;
	while(m!=0 && n!=0)
	{
		vector<int>arr;
		for(int i =0;i<n;i++)
		arr.PB(-1);
		vector<struct node>hold;
		for(int i =0;i<m;i++)
		{
			struct node z;int c =0;
			cin>>z.a>>z.b>>c;
			z.c = abs(c);
			hold.PB(z);
		}
		int ans =1;
		for(int i =0;i<hold.size();i++)
		{
			struct node r = hold[i];
			int ct =  r.c;
			arr[]
		}
		cin>>m>>n;
	}
	return 0;
}