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
	int n =0;
	while(scanf("%d",&n)!=EOF)
	{
		string s;
		int arr[100][100];
		getline(cin,s);
		for(int i =0;i<n;i++)
		{
			getline(cin,s);
			//cout<<s<<endl;
			for(int k =0;k<n;k++)
			{
				if(s[k]=='1')
				arr[i][k] = 1;
				else if(s[k]=='2')
				arr[i][k] = 2;
				else arr[i][k] =3;
			}
		}
		int nas =0;
		for(int i =0;i<n;i++)
		{
			for(int j =0;j<n;j++)
			{
				
				if(arr[i][j] == 1)
				{
				int mint =1000000;
					for(int m =0;m<n;m++)
					{
						for(int x =0;x<n;x++)
						{
							int temp =0;
							if(arr[m][x] ==3)
							{
							temp = abs(m-i)+abs(x-j);
							mint =min(mint,temp);
							}
						}
					}
					nas = max(nas,mint);
				}
			}
		}
		cout<<nas<<endl;
	}
	return 0;
}