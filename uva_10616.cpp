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
	cin>>m>>n;
	while(m!=0 && n!=0)
	{
		vector<int>arr(m);
		for(int i =0;i<m;i++)
		{
			int x ;
			cin>>x;
			arr[i] = x;
		}
		for(int i =0;i<n;i++)
		{
			int sum,c;
			cin>>sum>>c;
			int ans =  subset_sum(sum,arr,c);
			cout<<ans<<endl;
		}
		cin>>m>>n;
	}
	return  0;
}