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
#define INF 1<<20
using namespace std;
map<int,int>mymap;
string get_part(string y)
{
	reverse(y.begin(),y.end());
	string ans = y.substr(2,4);
	reverse(ans.begin(),ans.end());
	return ans;
}

string convert(int h)
{
	vector<int>y;
	string z;
	while(h!=0)
	{
		y.PB(h%10);
		h/=10;
	}
	reverse(y.begin(),y.end());
	for(int i =0;i<y.size();i++)
	z.PB('0'+y[i]);
	reverse(z.begin(),z.end());
	for(int i =0;i<8-z.size();i++)
	z.PB('0');
	reverse(z.begin(),z.end());
	return z;
}

int again_convert(string y)
{
	int ans =0;
	int cont= 1;
	for(int i =y.size()-1;i>=0;i--)
	{
		ans+=((y[i]-'0')*cont);
		cont*=10;
	}
	//cout<<y<<" "<<ans<<endl;
	return ans;
}
void recurse(int x)
{
	int n = x*x;
	string a = convert(n);
	//cout<<a<<" ";
	string b = get_part(a);//cout<<b<<" ";
	int g= again_convert(b);
	if(mymap.find(g)==mymap.end())
	{
		mymap[g] =true;
		//cout<<g<<" ";
		recurse(g);
		//cout<<endl;
	}
}
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		mymap[n] = true;
		recurse(n);
		cout<<mymap.size()<<endl;
		mymap.erase(mymap.begin(),mymap.end());
		cin>>n;
		
	}
	return 0;
}