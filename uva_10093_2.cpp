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
		int arr[200005];
		int brr[200005];
bool check(int s,int m)
{
	int sum1 =0;
	int sum2 =0;
	int j = s+m;
	for(int i =s;i<j;i++)
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
		for(int i =0;i<m;i++)
		{
			cin>>arr[i];
		}
		for(int i =m;i<2*m;i++)
		{
			arr[i] = arr[i-m];
		}
		for(int i =0;i<m;i++)
		{
			cin>>brr[i];
		}
		for(int i =m;i<2*m;i++)
		{
			brr[i] = brr[i-m];
		}
	
		int ans =0;
		for(int i =0;i<m;i++)
		{
			bool bt= true;
			bt = check(i,m);
			if(bt)
			{
				ans = i+1;
				break;
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