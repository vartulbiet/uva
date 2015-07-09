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
#define ll long long int
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
int GCD(int a, int b){
    return b == 0 ? a : GCD(b, a % b);
}
int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		ll g =0;
		for(int i =1;i<n;i++)
		{
			for(int j =i+1;j<=n;j++)
			{
				g+=GCD(i,j);
			}
		}
		cout<<g<<endl;
		cin>>n;
	}
	return 0;
}