#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	int kk =1;
	while(n>0)
	{
		int x;
		cin>>x;
		vector<int>arr;
		for(int i =0;i<x;i++)
		{
			int z;
			cin>>z;
			arr.push_back(z);
		}
	
		int sum2 =0;
		
		
		
		for(int i =0;i<x;i++)
		{
			int g =arr[i];int paddu =0;int j =2;	int pp = 10;int xx =10;int sum =0;
			while(paddu<=g)
			{
				paddu+=30;
				sum =pp;
				pp = (xx*j);
				//cout<<paddu<<sum<<endl;
				j++;
			}
			sum2+=sum;
		}
	
		int sum1 =0;
		for(int i =0;i<x;i++)
		{
			int g =arr[i];int paddu =0;int j =2;	int pp = 15;int xx =15;int sum =0;
			while(paddu<=g)
			{
				paddu+=60;
				sum =pp;
				pp = (xx*j);
				//cout<<paddu<<sum1<<endl;
				j++;
			}
			sum1+=sum;
		}
		if(sum2<sum1)
		{
		cout<<"Case "<<kk++<<": Mile "<<sum2<<endl;
		}
		else if(sum2 ==sum1)
		{
		cout<<"Case "<<kk++<<": Mile Juice "<<sum1<<endl;
		}
		else
		cout<<"Case "<<kk++<<": Juice "<<sum1<<endl;
		n--;
	}
	return 0;
}