#include <vector>
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
using namespace std;


int main()
{
	ull t =0;
	cin>>t;
	ull LIMIT = pow(2,64)-1;
	ull pp=1;
	string x; ull y;
	string tt ;
	while(t>0)
	{
	cin>>x>>y;
				cout<<"Case #"<<pp++<<": ";

		ull len = x.size();
		if( len == 1 )
		{
			for(int i =1;i<=y;i++)
			{
				cout<<x[0];
			}
			cout<<endl;
		}
		else
		{
			ull n = 0; ull r = 1; ull val = 0;ull ans;
			ull diff  ;
		bool check = false;
		while( val < y ) 
		{
			diff = LIMIT - r;
			check = false;
			for(ull  i=0;i<len;i++) 
			{
				if( diff > r )
				{
				diff -= r;
				} 
				else 
				{
				check = true;
				break;
				}
			}

			if( !check )
			{
				r *= len;
				n++;
				val += r;
			}
			else 
			{
			break;
			}
		}
		if( val == y )
		{
			for(int i =0;i<n;i++)
			cout<<x[len-1];
		}
		else 
		{
		if(!check ) {
			ans = val - r; n--;}
		else
			ans = val;
		if(!check) 
			r = r/len;
		for(ull i =0;i<=n;i++) 
		{
		for(ull j =0;j<len;j++) 
		{
			if( ans + r < y )
				ans += r;
			else {
				cout<<x[j]; break;}
		}
		r = r/len;
		}
		}
		cout<<endl;
		}
		getline(cin,tt);
		t--;
	}
   return 0;
}