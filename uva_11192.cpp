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
		string s;
		cin>>s;
		string ans;
		int m = s.size()/n;
		for(int i=0;i<s.size();i =i+m)
		{
			string g = s.substr(i,m);
			reverse(g.begin(),g.end());
			ans +=g;
		}
		cout<<ans<<endl;
		cin>>n;
	}
	return 0;
}