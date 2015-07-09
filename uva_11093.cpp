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
bool check(vector<int>arr,vector<int>brr)
{
	int sum1 =0;
	int sum2 =0;
	int m = arr.size();
	for(int i =0;i<m;i++)
	{
		sum1+=arr[i];
		sum2+=brr[i];
		if(sum1<sum2)
		return false;
	}
	return true;
}
int main()
{
	int n =0;
	cin>>n;
	int tc =1;
	while(n!=0)
	{
		int m =0;
		cin>>m;
		vector<int>arr;
		vector<int>brr;
		for(int i =0;i<m;i++)
		{
			int x =0;
			cin>>x;
			arr.PB(x);
		}
		for(int i =0;i<m;i++)
		{
			int x =0;
			cin>>x;
			brr.PB(x);
		}
		int ans =0;
		for(int i =0;i<m;i++)
		{
			bool bt= true;
			bt = check(arr,brr);
			if(bt)
			{
				ans = i+1;
				break;
			}
			else
			{
				arr.PB(arr[0]);brr.PB(brr[0]);
				arr.erase(arr.begin());brr.erase(brr.begin());
			}
		}
		cout<<"Case "<<tc++<<": ";
		if(ans ==0)
		cout<<"Not possible"<<endl;
		else
		cout<<"Possible from station "<<ans<<endl;
		n--;
	}
	return 0;
}