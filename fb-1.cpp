#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;

int main()
{
	int x =0;
	cin>>x;int kk=1;
	while(x>0)
	{
		int n =0;
		cin>>n;
		vector<string>arr;
		string s;
		getline(cin,s);
		for(int i =0;i<n;i++)
		{
			getline(cin,s);
			arr.push_back(s);
		}
		int a=n-1,b=n-1,c =0,d=0;
		for(int i =0;i<n;i++)
		{
			for(int j =0;j<n;j++)
			{
				if(arr[i][j] == '#')
				{
					if(i<a)
					{
						a= i;
					}
					if(i>c)
					c= i;
					if(j>d)
					d= j;
					if(j<b)
					b=j;
				}
			}
		}
		//cout<<a<<b<<c<<d<<endl;
		bool bt =true;
		
		if((c-a)!=(d-b))
		{
		bt= false;
		}
		if(bt)
		{
		for(int i =a;i<=c;i++)
		{
			for(int j=b;j<=d;j++)
			{
				if(arr[i][j] !='#')
				bt =false;
			}
		}
		}
		cout<<"Case #"<<kk++<<": ";
		if(bt)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
		x--;
	}
	return  0;
}