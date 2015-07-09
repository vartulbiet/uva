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
	int n =0;
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		for(int i =0;i<b;i++)
		{
			for(int k =1;k<=a;k++)
			{
				for(int l =0;l<k;l++)
				cout<<k;
				cout<<endl;
			}
			for(int k =a-1;k>=1;k--)
			{
				for(int l =0;l<k;l++)
				cout<<k;
				cout<<endl;
			}
			if(i!=b-1)
			{
			cout<<endl;
			}
			
		}
		if(n>=1)
		cout<<endl;
	}
	return 0;
}