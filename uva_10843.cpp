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
#define M 2000000011
using namespace std;
//((X%M)*(Y%M))%M
long long int recurse(long long int x,long long int y)
{
	if(y ==0)
	return 1;
	if(y%2==0)
	{
		return ((recurse((x%M),(y/2%M))%M)*(recurse((x%M),(y/2%M))%M))%M;
	}
	else
		return (x*(recurse((x%M),((y-1)%M))%M))%M;
}

int main()
{
		int n =0;
		cin>>n;
		int tt =1;
		while(n>0)
		{
			int x =0;
			cin>>x;
			int y = x-2;
			long long int val;
			if(y<=0)
		    val =1;
			else
			val =recurse(x,y);
			cout<<"Case #"<<tt++<<": ";
			cout<<val<<endl;
			n--;
		}
		return 0;
}