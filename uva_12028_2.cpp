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
#define INF 1<<30
using namespace std;
//a[i] = (K*a[i - 1] + C)%1000007
long long arr [100000 + 10];
long long sum [100000 + 10];
int main()
{
	int n =0;
	cin>>n;int tc =1;
	while(n>0)
	{

		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		arr[0] = d;
		for(int i =1;i<c;i++)
		{
			arr[i] = (a*arr[i-1]+b)%1000007;
		}
		//cout<<endl;
				sort(arr,arr+c);

		sum[0]=arr[0];
		for(int i =1;i<c;i++)
		{
			sum[i] = arr[i]+sum[i-1];
		}
		long long ans =0;
		for(int i =0;i<c;i++)
		{
			 long long f = (c-1-i)*arr[i];
			long long s = sum[c-1]-sum[i];
			ans = ans + labs(f-s);
		}
		cout<<"Case "<<tc++<<": "; 
		cout<<ans<<endl;
		n--;
	}
	return 0;
}