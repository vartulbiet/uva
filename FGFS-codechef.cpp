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
#define u unsigned  
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
using namespace std;
//long long int arr[1000000001];
int main()
{
	int n =0;
	scanf("%d",&n);
	while(n>0)
	{
		 int a;long long int b;
		scanf("%d%lld",&a,&b);
		vector<pair<pair< long long int,long long int>,long long int> >vec;
		//vector< long long int>arr(b+1);
		map<long long int,long long int>mymap;
		for( int i =0;i<a;i++)
		{
			long long int x,y,z;
			scanf("%lld%lld%lld",&x,&y,&z);
			vec.PB(make_pair(make_pair(x,y),z));
		}
		sort(vec.begin(),vec.end());
		int ans =0;
		if(a>0)
		{
		ans =1;
		mymap[vec[0].second] = vec[0].first.second;
		}
		for( int i =1;i<vec.size();i++)
		{
			pair<pair< long long int, long long int>,long long int>p = vec[i];
			if((mymap.find(p.second)==mymap.end())||( mymap[p.second]<=p.first.first))
			{
			mymap[p.second] = p.first.second;
			ans++;
			}
		}
		printf("%d\n",ans);
		n--;
		//arr.erase(arr.begin(),arr.end());
	}
	return 0;
}