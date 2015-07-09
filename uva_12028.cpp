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
#define INF 1<<30
using namespace std;
int main()
{
	int tt =0;int tc =1;
	int k,c,n,t;
	cin>>tt;
	while(tt>0)
	{
		cin>>k>>c>>n>>t;
		long long int sum=0;
		for(int i =1;i<n;i++)
		{
			double y = pow(double(k),i-2);
			double yy =((pow(double(k+1),n-1)-1));
			double value =(y*yy*((k-1)*(t)+c));
	
			cout<<value<<"  ";
			sum+=value;
			sum %=10000007;
		}
		cout<<sum<<endl;
		tt--;
	}
	return 0;
}