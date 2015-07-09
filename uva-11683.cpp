#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
int main()
{
	int a;int b;
	cin>>a>>b;
	while(a!=0 || b!=0)
	{
		vector<int>arr;
		for(int i =0;i<b;i++)
		{
			int d;
			cin>>d;
			arr.push_back(d);
		}
		for(int i =0;i<b;i++)
		{
			arr[i] = a-arr[i];
		}
		int ans  = arr[0];
		for(int i =0;i<b-1;i++)
		{
		//cout<<arr[i]<<" ";
			if(arr[i+1]-arr[i]>0)
			ans+=(arr[i+1]-arr[i]);
		}
		cout<<ans<<endl;
		cin>>a>>b;
	}
	return 0;
}