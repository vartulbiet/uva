#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<stack>
#include<map>
#include<list>
#include<queue>
#include<string>
#include <algorithm>
#include<stdlib.h>
#include<math.h>
#define SIZE sizeof(arr)/sizeof(long long)
#define FEL(i,a,b) for(long long i=a;i<b;i++)
#define INF 1<<30
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	int l =1;
	while(n!=0)
	{
		vector<int>arr;
		int sum =0;
		for(int i =0;i<n;i++)
		{
			int h =0;
			cin>>h;
			sum+=h;
			arr.push_back(h);
		}
		int meat = sum/n;
		int ans =0;
		for(int i =0;i<n;i++)
		{
			ans+=(abs(meat-arr[i]));
		}
		cout<<"Set #"<<l++<<endl;
		cout<<"The minimum number of moves is "<<ans/2<<"."<<endl<<endl;;
			cin>>n;
	}
	return 0;
}