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
	ull n =0;
	cin>>n;
	while(n!=0)
	{
		ull a ,b;
		cin>>a>>b;
		ull x =0;ull count =1;
		map<ull,ull>mymap;
		mymap[0] = 0;
		int y =1;
		while(mymap.find(((((a*x)%n)*x)%n+b)%n) == mymap.end ())
		{
			x = ((((a*x)%n)*x)%n+b)%n;
		//	cout<<x<<"  "<<((((a*x)%n)*x)%n+b)%n<<endl;
			mymap[x] = y++;
		}
		cout<<n-y +mymap[((((a*x)%n)*x)%n+b)%n]<<endl;
		cin>>n;
	}
	return 0;
}