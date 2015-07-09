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
#define graphAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<10
using namespace std;
int main()
{
	ull n =0;
	cin>>n;
	while(n>0)
	{
		ull m =0;
		cin>>m;
		ull ans =0;
		ull k =0;
		map<ull,ull>mymap;
		vector<int>vec;
		for(int i =0;i<m;i++)
		{
			int h =0;
			cin>>h;
			vec.PB(h);
		}
		bool bt =true;
		for(int i =0;i<m;i++)
		{
			if(mymap.find(vec[i])!=mymap.end())
			{
				//ans = max(ans,k-mymap[vec[i]]);
				i = mymap[vec[i]]+1;
				mymap.erase(mymap.begin(),mymap.end());
			}
			mymap[vec[i]] =i;
			ans = max(ans,(ull)mymap.size());			
		}
		cout<<ans<<endl;
		n--;
	}
	return 0;
}