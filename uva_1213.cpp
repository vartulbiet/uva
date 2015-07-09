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
vector<int>primes;
int D[1121][15][187];
void calculate()
{
	primes.PB(2);
	primes.PB(3);
	primes.PB(5);
	primes.PB(7);
	for(int i =8;i<1150;i++)
	{
	bool bt = true;
		if(i%2!=0)
		{
			int z = sqrt(i)+1;
			for(int k =2;k<=z;k++)
			{
				if(i%k==0)
				{
					bt = false;
					break;
				}
			}
				if(bt)
				primes.PB(i);
		}
	}
}
int ans =0;
int DP(int sum,int numb,int id)
{
	if(!sum && !numb)
		return 1;
	else if(sum<0|| numb==0 || id>=187)
	return 0;
	else if(D[sum][numb][id]!=-1)
		return D[sum][numb][id];
		else
	return D[sum][numb][id]= DP(sum,numb,id+1)+DP(sum-primes[id],numb-1,id+1);
}
int main()
{
	calculate();
	int m,n;
	cin>>m>>n;
	while(!(m==0 && n==0))
	{
	//	cout<<m<<n;
		for(int i =0;i<=m;i++)
		{
			for(int  j = 0;j<=14;j++)
			{
				for(int k =0;k<187;k++)
				D[i][j][k] =-1;
			}
		}
		cout<<DP(m,n,0)<<endl;;
		cin>>m>>n;
	}
	return 0;
}
