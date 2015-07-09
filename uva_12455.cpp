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
void subset_sum(vector<int>arr,int sum)
{
	int matrix[arr.size()+1][sum+1];
	memset(matrix,0,sizeof(matrix));
	for(int i =0;i<=arr.size();i++)
	matrix[i][0] =1;
	for(int i = 1 ;i<=arr.size();i++)
	{
		for(int j =1;j<=sum;j++)
		{
			if(arr[i-1] == j)
				matrix[i][j] = 1;
			else 
				matrix[i][j] = matrix[i-1][j];
			if(arr[i-1]<j && j-arr[i-1]>=0&& matrix[i-1][j-arr[i-1]]==1)
				matrix[i][j] = 1;
		}
	}
	/*for(int i = 0 ;i<=arr.size();i++)
	{
		for(int j =0;j<=sum;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}*/
	if(matrix[arr.size()][sum] ==1)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
}
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		int sum =0;
		int k =0;
		cin>>sum>>k;
		vector<int>arr(k);
		int i =0;
		while(k!=0)
		{
			cin>>arr[i];
			i++;
			k--;
		}
		sort(arr.begin(),arr.end());
		subset_sum(arr,sum);
		n--;
	}
	return 0;
}