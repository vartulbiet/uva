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
#define ll  long long 
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
vector<int>primes;
void seive()
{
	bool arr[1000000];
	memset(arr,false,sizeof(arr));
	int n =1000000;
	for(int i  = 2;i<n;i++)
	{
			if(arr[i] == false)
			{
			primes.PB(i);
			//cout<<i<<endl;
			for(int j = 2;j*i<n;j = j+1)
			{
				arr[j*i] = true;
			}
			}
	}
}
using namespace std;
int main()
{
	int n =0;
	cin>>n;seive();
	while(n!=0)
	{
		int i =0;
		ll c =0;
	//	cout<<n;
		while(primes[i]<=n && i<primes.size())
		{
		if(n%primes[i] == 0)
		c++;
		i++;
		}
		cout<<n<<" : "<<c<<endl;
		cin>>n;
	}
	return 0;
}