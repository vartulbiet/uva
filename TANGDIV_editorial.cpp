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
	int n = 0;
	scanf("%d",&n);
	while(n--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);

		vector<int>vec,dec;
		
		for(int i =0;i<b;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			vec.PB(x);
		}
		bool bt =true;
		for(int i =0;i<c;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			bool ct =true;
			for(int j =0;j<vec.size();j++)
			{
			if(vec[j] == x)
			ct =false;
			}
			if(ct)
			bt =false;
		}
		
		if(bt)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		vec.erase(vec.begin(),vec.end());
	}
	return 0;
}