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
#define ull long long int
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1LL << 60;
using namespace std;
vector<ull>arr;
ull max(ull x,ull y)
{
	return x>y?x:y;
}


vector<ull>max_sum(int n)
{	
	vector<ull>ret;
	for(int  i =0;i<n;i++)
	ret.PB(arr[i]);
	int k =0;
	ull sum =arr[0];
	for(int i = 1;i<n;i++)
	{
		if(sum+arr[i]>arr[i])
		{
			sum+=arr[i];
			ret[k+1] = sum;
		}
		else 
		sum = arr[i];
		k++;
	}
	ull maxy = ret[0];
	for(int i = 1;i<ret.size();i++)
	{
	ret[i]= max(ret[i],maxy);
	maxy = ret[i];
	}
	for(int i =0;i<ret.size();i++)
	{
	//cout<<ret[i]<<" ";
	}
	//cout<<endl;
	/*
	ret.resize(n);
	ret[0] = arr[0];
	ull maxSum = -(1LL << 60);
	ull meh = arr[0];
	for( int i = 1; i < n; i++ ) {
		meh = max(meh+arr[i], arr[i]);
		maxSum = max( maxSum, meh );
		ret[i] = maxSum;
	}	*/
	return ret;
}

int main()
{
	int n =0;
	cin>>n;
	for(int i =0;i<n;i++)
	{
		int m ,k;
		cin>>m>>k;
		for(int j =0;j<m;j++)
		{
			ull d;
			cin>>d;
			arr.PB(d);
		}
		vector<ull>front = max_sum(m);
		reverse(arr.begin(),arr.end());
		vector<ull>dusra = max_sum(m);
		reverse(dusra.begin(),dusra.end());
		ull ans =-INF;
		for(int h =0;h<front.size(),h+k+1<dusra.size();h++)
		{
		//	cout<<front[h]<<" "<<dusra[h+k+1]<<endl;
		ans = max(ans,front[h]+dusra[h+k+1]);
		}/*
		for( int s = 0, e = k+1; s < m && e < m; s++, e++ ) {
			ans = max(ans,front[s]+dusra[e]);
		}*/
		cout<<ans<<endl;
		arr.erase(arr.begin(),arr.end());
	}
	return 0;
}