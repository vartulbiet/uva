#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n>0)
	{
		int x = 0;
		cin>>x;
		vector<int>arr;
		
		for(int i =0;i<x;i++)
		{
	
			string s;
				getline(cin,s);
			cin>>s;
			if(s=="SAME")
			{
				string h;
				cin>>h;
				int g;
				cin>>g;
				arr.push_back(arr[g-1]);
			}
			else if(s=="LEFT")
			arr.push_back(-1);
			else
			arr.push_back(1);	
		}
		int sum =0;
		for(int i =0;i<x;i++)
		{	
		sum +=arr[i];
		}
		cout<<sum<<endl;
		n--;
	}
	return 0;
}