#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#define INF 1<<30

   // If N = 100, then f91(N) = f91(f91(N+11));
  //  If N = 101, then f91(N) = N-10.

using namespace std;
int func(int n)
{
	if(n>100)
	return n-10;
	else
	return func(func(n+11));
}
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		
		cout<<"f91("<<n<<") = "<<func(n)<<endl;
		cin>>n;
	}
	return 0;
}