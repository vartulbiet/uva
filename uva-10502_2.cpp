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

		int ggg =0;
		for(int i =0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				int temp =arr[i][j];
				if(i-1>=0)
				{
					temp +=arr[i-1][j];
				}
				if(j-1>=0)
				{
					temp +=arr[i][j-1];
				}
				if(i-1>=0 && j-1>=0)
					temp -=arr[i-1][j-1];
				arr[i][j] = temp;
			}
		}
		for(int i =0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				for(int k =i;k<m;k++)
				{
					for(int l =j;l<n;l++)
					{
						int g = arr[k][l];
						if(i-1>=0)
						g-=arr[i-1][l];
						if(j-1>=0)
						g-=arr[k][j-1];
						if(i-1>=0 && j-1>=0)
						g+=arr[i-1][j-1];
						if(g == abs(k-i+1)*abs(l-j+1))
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