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

int search(int x,vector<int> arr)
{
	int ans =0;
	int diff =INF;
	for(int i =0;i<arr.size();i++)
	{
		if(abs(x-arr[i])<diff)
		{
			diff = abs(x-arr[i]);
			ans = i;
		}
	}
	return  ans;
}
int main()
{
	int m,n;
	int tc =1;
	cin>>m>>n;
	while(m!=0 || n!=0)
	{
		vector<int>arr(m);
		vector<int>brr(n);
		for(int i =0;i<m;i++)
		{
			int x =0;
			cin>>x;
			arr[i] = x;
		}
		sort(arr.begin(),arr.end());
		reverse(arr.begin(),arr.end());
		for(int i =0;i<n;i++)
		{
			int x =0;
			cin>>x;
			brr[i] = x;
		}
		sort(brr.begin(),brr.end());
		reverse(brr.begin(),brr.end());
		while(arr.size()!=0 && brr.size()!=0)
		{
			int f= arr[0];
			arr.erase(arr.begin());
			int ind = search(f,brr);
			int g = brr[ind];
			brr.erase(brr.begin()+ind);
		}
		cout<<"Case "<<tc++<<": ";
		if(arr.size()==0)
		cout<<arr.size()<<endl;
		else
		cout<<arr.size()<<" "<<arr[arr.size()-1]<<endl;
		cin>>m>>n;
	}
	return 0;
}