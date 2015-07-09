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
int main()
{
	int m = 0,n = 0;
	cin>>m>>n;
	char*arr = (char*)malloc(sizeof(char)*m);
	scanf("%s",arr);
	int **table;
	table = (int**)malloc(sizeof(int)*m*10);
	int val[10];
	memset(val,0,sizeof(val));
	for(int i =0;i<m;i++)
	{
		int* temp = (int*)malloc(sizeof(int)*10);
		//for(int j =0;j<10;j++)
		//cout<<val[j]<<" ";
		for(int j =0;j<10;j++)
		temp[j] = val[j];
		table[i]= temp;
		//cout<<endl;
		val[arr[i]-'0']++;
	}
	for(int i =0;i<n;i++)
	{
		int y =0;
		cin>>y;
		int *temp = (int*)malloc(sizeof(int)*10);
		temp = table[y-1];
		char t = arr[y-1];
		int z = t-'0';
		int b1 = 0,b2 =0;
		for(int i =0;i<10;i++)
		{
			//cout<<temp[i]<<" ";
			int u =0;
			if(temp[i]!=0)
			u = (z -i)*temp[i];
			//cout<<u<<" ";
			if(u>0)
			b1+=u;
			else b2+=u;
		}
		cout<<b1-b2<<endl;
	}
	return 0;
}