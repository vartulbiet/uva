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
#define pi 3.141592653589793
#define ull unsigned long long  
using namespace std;

vector<ull>vec;
string x;
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
	int t =0;
	cin>>t;
	int pp =1;
	while(t>0)
	{
		ull y;
		cout<<"Case #"<<pp++<<": ";
		cin>>x>>y;
		ull n = x.size();
		ull till_now =0ull;
		ull  r =1ull;
		ull h = (ull)pow((ull)n,(ull)r);
		if(n ==1)
		{
			for(ull l =0;l<y;l++)
			cout<<x;
		}
		else
		{
		while((ull)(till_now)+h<=((ull)y))
		{
			till_now=till_now+h;
				cout<<y<<" "<<h<<" "<<r<<endl;
			r = r+1;
			h= h*n;
			/*ull j =h; ull g =0;
			for(ull i = 0;i<n;i++)
				g =g+h;
			h =g;*/
		}
		cout<<till_now<<endl;
		main_func(till_now,n,r,y);
		for(ull i =0;i<vec.size();i++)
		cout<<x[vec[i]-(ull)1];
		}
		cout<<endl;
		vec.erase(vec.begin(),vec.end());
		t--;
	}
	return 0;
}