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
#define SORT(X) sort(X.begin(),X.end())
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	int kk =1;
	while(n>0)
	{
		int m =0;
		cin>>m;
		vector<long long int>vec;
		vector<long long int>arr;
		for(int i =0;i<m;i++)
		{
			long long int x =0;
			cin>>x;
			vec.PB(x);
		}
		sort(vec.begin(),vec.end());
		for(int i =0;i<m;i++)
		{
			long long int x =0;
			cin>>x;
			arr.PB(x);
		}
		SORT(arr);
		reverse(arr.begin(),arr.end());
		long long int ans =0;
		for(int i =0;i<m;i++)
		{
			ans +=(vec[i]*arr[i]);
		}
		cout<<"Case #"<<kk++<<": "<<ans<<endl;
		n--;
	}
	return 0;
}