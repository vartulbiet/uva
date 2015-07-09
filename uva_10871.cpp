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
bool isPrime(long long int n)
{
	double z = sqrt(n);
	for(long long int i=2;i<=z+1;i++)
	{
		if(n%i==0)
		return false;
	}
	return true;
}
void get_ans(vector<long long int>ans)
{
	long long int n = ans.size();
	long long int till = INF;
	long long int f,l;
	for(long long int k =0;k<n;k++)
	{
		long long int sum = ans[k];
		for(long long int i = k+1;i<n;i++)
		{
			sum+=ans[i];
			if(isPrime(sum) && i -k+1<till)
			{
				f =k;l =i;
				till = i-k+1;
			}
		}
	}

	if(till==INF)
	cout<<"This sequence is anti-primed.";
	else
	{
			cout<<"Shortest primed subsequence is length "<<till<<":";
		for(long long int i =f;i<=l;i++)
		cout<<" "<<ans[i];
	}
	cout<<endl;
}
int main()
{
	long long int n =0;
	cin>>n;
	while(n!=0)
	{
		long long int x;
		cin>>x;
		vector<long long int>y;
		for(long long int i =0;i<x;i++)
		{
			long long int z =0;
			cin>>z;
			y.PB(z);
		}
		get_ans(y);
		n--;
	}
	return 0;
}