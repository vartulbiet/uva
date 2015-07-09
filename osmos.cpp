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
#define ll long long int
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
int main()
{
	int n =0;
	cin>>n;int tc =1;
	while(n--)
	{
		int x =0;
		cin>>x;
		int y =0;
		cin>>y;int t =y;
		vector<int>arr(y);int u =0;
		while(y--)
		{
			cin>>arr[u++];
		}

		sort(arr.begin(),arr.end());
		int curr =x;
		int ans =0;
		for(int i =0;i<t;i++)
		{
			if(arr[i]>=curr)
			{
				if(arr[i]<(curr+curr-1))
				{
					curr+=(curr-1);
					curr+=arr[i];
				}
				ans++;
			}
			else
			{
				curr+=arr[i];
			}
		}cout<<"Case #"<<tc++<<": ";
		cout<<ans<<endl;
	}
	return 0;
}