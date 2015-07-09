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
	while(n!=0)
	{
		for(int i =0;i<n;i++)
		{
			int pos =0;
			int neg =0;
			for(int i =0;i<5;i++)
			{
				int x =0;
				cin>>x;
				if(x<=127)
				{
				pos =i;
				neg++;
				}
			}
			char f = 'A'+pos;
			if(neg == 1)
			cout<<f<<endl;
			else
			cout<<"*"<<endl;
		}
		cin>>n;
	}
	return 0;
}