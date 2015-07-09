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
char Buffer[2000];
int firstg[105][105];
int secondg[105][105];
int main()
{
	int n =0;
	while(scanf("%d\n", &n) == 1, n)
	{
		//cout<<n<<endl;
		memset(firstg,63,sizeof(firstg));
		memset(secondg,63,sizeof(secondg));

		for(int i =0;i<n;i++)
		{
			gets(Buffer);
			for(char *c  =  strtok(Buffer," ");c != NULL; c = strtok(NULL," "))
			firstg[i][atoi(c) - 1] = 1;
		}
		for(int i =0;i<n;i++)
		{
			for(int j =0;j<n;j++)
			{
				for(int k =0;k<n;k++)
				{
					firstg[j][k] = min(firstg[j][k],firstg[j][i] + firstg[i][k]);
				}
			}
		}
		for(int i =0;i<n;i++)
		{
			gets(Buffer);
			for(char *c  =  strtok(Buffer," ");c != NULL; c = strtok(NULL," "))
			secondg[i][atoi(c) - 1] = 1;
		}
		for(int i =0;i<n;i++)
		{
			for(int j =0;j<n;j++)
			{
				for(int k =0;k<n;k++)
				{
					secondg[j][k] = min(secondg[j][k],secondg[j][i] + secondg[i][k]);
				}
			}
		}
		int A,B;
		scanf("%d%d",&A,&B);
		//cout<<A<<B;
		bool bt = true;
		for(int i =0;i<n && bt;i++)
		{
			for(int j =0;j<n && bt;j++)
			{
				if(secondg[i][j]>A*firstg[i][j]+B)
					bt= false;
			}
		}
		if(bt)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
}