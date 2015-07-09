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
	int x =0;
	cin>>x;
	while(x--)
	{
		int m,n;
		int a,b;
		int c,d;
		cin>>m>>n;
		a =m/2;
		b =m%2;
		c = n/2;
		d =n%2;
		if(m == n)
		{
			cout<<ceil(m/2.0)*(ceil(m/2.0)+1)/2<<endl;
		}
		else
		{
			cout<<(int)(ceil(m/2.0)*ceil(n/2.0))<<endl;
		}
	}
	return 0;
}