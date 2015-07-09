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

vector<ull>vec;
string x;
ull LIMIT;
void main_func(ull value,ull  n,ull  k,ull ans)
{
	if(value>=ans)
	return;
	else
	{
	ull  u =( ull)1;
	//cout<<k<<endl;
	ull h = (ull)pow((ull)n,(ull)k);
	while((value+(ull)h)<=(ull)ans)
	{
		value= value+(ull)h;
		if(value!=ans)
		u=u+(ull)1;
	}
	//cout<<value<<endl;
	vec.push_back(u);
	k = k-1;
	main_func(value,n,k,ans);
	}
}

int main()
{
	ull  t =(ull)0;
	cin>>t;
	int pp =1;
	LIMIT = 1;
	for(int i =1;i<64;i++)
LIMIT *= 2;
LIMIT -= 1;
	while(t>0)
	{
		ull  y;
		cin>>x>>y;
		ull  len = x.size();
		ull  till_now =(ull)0;
		ull  r =(ull)1;
		//ull h = (ull)pow((ull)n,(ull)r);
		ull diff =0;
		ull p =1;
		ull n =0;
		bool bad =false;
		while( till_now < y ) {
		diff = LIMIT - p;
		bad = false;
		for(int i =1;i<=len;i++) 
		{
			if( diff > p )
			{
			diff -= p;
			} 
			else 
			{
			bad = true;
			break;
			}
		}
		if( !bad )
		{
			p *= len; n++;
			till_now += p;
		}
		else
		{
		break;
		}
		}

		//cout<<till_now<<endl;
		main_func(till_now,len,n-1,y);
		cout<<"Case #"<<pp++<<": ";
		for(ull i =0;i<vec.size();i++)
		cout<<x[vec[i]-(ull)1];
		cout<<endl;
		vec.erase(vec.begin(),vec.end());
		t--;
	}
	return 0;
}