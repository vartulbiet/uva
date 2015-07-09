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
int main()
{
	int m,n;
	cin>>m;
	while(m!=0)
	{
		cin>>n;
		string s;
		int arr[m][n];
		vector<string>vec;
		int count = 0;
		getline(cin,s);
		for(int i = 0;i<m;i++)
		{
			getline(cin,s);
			vec.PB(s);
			//cout<<s<<endl;
			for(int j =0;j<n;j++)
			{
				if(s[j] == '1')
				{
				arr[i][j] =1;
				//count++;
				}
				else
				arr[i][j] = 0;
			}
		}
		/*cout<<count<<endl;
		int sum =0;
		for(int  i =0;i<m;i++)
		{
			string h =vec[i];
			int temp=0;
			for(int j =0;j<n;j++)
			{
				if(h[j] == '0')
				{
				sum+=(temp*(temp-1)/2);
				temp =0;
				}
				else
				temp++;
			}
			sum+=(temp*(temp-1)/2);
		}
		cout<<sum<<endl;;
		for(int  i =0;i<n;i++)
		{
			int temp=0;
			for(int j =0;j<m;j++)
			{
				if(arr[j][i] == 0)
				{
				sum+=(temp*(temp-1)/2);
				temp =0;
				}
				else
				temp++;
			}
			sum+=(temp*(temp-1)/2);
		}*/
		int ggg =0;
		for(int i =0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				for(int k =i;k<m;k++)
				{
					for(int t = j;t<n;t++)
					{
						int hhh =0;bool bt = true;
						for(int h =i;h<=k;h++)
						{
							for(int bb = j;bb<=t;bb++)
							{
								if(arr[h][bb]==0)
								bt = false;
							}
						}
						if(bt)
						ggg++;
					}
				}
			}
		}
		cout<<ggg<<endl;
		//cout<<sum+count<<endl;
		cin>>m;
	}
	return 0;
}