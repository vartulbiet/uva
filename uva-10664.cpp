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
using namespace std;
bool subset_sum(vector<int>arr,int sum)
{
	int m = arr.size()+1;
	int n = sum+1;
	int table[arr.size()+1][sum+1];
	for(int i =1;i<m;i++)
	{
		for(int j =1;j<n;j++)
		{
		table[i][j] =0;
		}
		}
	for(int i =0;i<n;i++)
	table[0][i] =0;
	for(int i =0;i<m;i++)
	table[i][0] =1;
	for(int i =1;i<m;i++)
	{
		for(int j =1;j<n;j++)
		{
			if(arr[i-1] == j)
			table[i][j] =1;
			else if(arr[i-1]<j)
			{
				if(table[i-1][j-arr[i-1]]==1)
				table[i][j] =1;
			}
			else
			table[i][j] =table[i-1][j];
		}
	}
	//cout<<m<<n<<endl;
	/*for(int i =1;i<m;i++)
	{
		for(int j =1;j<n;j++)
		{
		cout<<table[i][j]<<" ";
		}
		cout<<endl;
		}
	*/
	if(table[m-1][n-1]==1)
	return true;
	else
	return false;
}
int main()
{
	int n =0;
	cin>>n;
	string v;
		getline(cin,v);
	while(n>0)
	{
		string s;
		getline(cin,s);
		istringstream x(s);
		int y;
		vector<int>arr;
		int sum =0;
		while(x>>y)
		{
			arr.PB(y);
			sum +=y;
		}
		sort(arr.begin(),arr.end());
		//cout<<sum<<endl;
		if(sum%2==0 && subset_sum(arr,sum/2))
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
		n--;
	}
	return 0;
}