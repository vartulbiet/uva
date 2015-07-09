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
#define graphAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<20
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		int m =0;
		cin>>m;
		int h = m/100;
		int table[10][1005]={{0}};
		for(int i =0;i<10;i++)
		{
			for(int j =0;j<h;j++)
			{
				int g =0;
				cin>>g;
				table[9-i][j] = g;
			}
		}
		int arr[1005][10];
		for(int i =0;i<1005;i++)
		{	
			for(int k =0;k<10;k++)
			arr[i][k] = INF;
		}
		arr[0][0] =0;
		for(int i =1;i<=h;i++)
		{
			for(int j =0;j<10;j++)
			{
				int temp = INF;
				if(j>0)
				temp = arr[i-1][j-1]+60-table[j-1][i-1];
				if(j<9)
				temp = min(temp,arr[i-1][j+1]+20-table[j+1][i-1]);
				
				arr[i][j] = min(temp, arr[i-1][j]+30-table[j][i-1]);	
			}
		}
	
		cout<<arr[h][0]<<endl;
		cout<<endl;
		n--;
	}
	return 0;
}