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
#define INF 1<<30
using namespace std;
int arr[22];
long long table[22][9999+1];
void count_ways(int sum)
{
	
	for(int i =0;i<22;i++)
	{
		for(int j =0;j<sum+1;j++)
		table[i][j] =0;
	}
	for(int i =0;i<22;i++)
	table[i][0] =1;
	for(int i =1;i<22;i++)
	{
		for(int j = 1;j<sum+1;j++)
		{
			table[i][j] = table[i-1][j];
			if(j>=arr[i])
			{
				table[i][j]= table[i][j]+table[i][j-arr[i]];
			}
		}
	}
}
int main()
{
	for(int i =1;i<22;i++)
	arr[i] = i*i*i;
	int sum =0;
	count_ways(9999);
	while(scanf("%d",&sum)==1)
	{
		cout<<table[21][sum]<<endl;
	}
	return 0;
}