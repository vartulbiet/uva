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
#define ll long long int
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
ull count(ull y)
{
	ull c =0;
	while(y!=0)
	{
		if(y%2 ==1)
		c++;
		y=y/2;
	}
	return c;
}
string do_And(string in,ull y)
{
	vector<ull>arr(in.size());
	fill(arr.begin(),arr.end(),0);
	ull yy =y;ull k =in.size()-1;
	while(y!=0)
	{
		arr[k--] =y%2;
		y=y/2;
	}
	string ans;
	reverse(arr.begin(),arr.end());
	for(ull i =0;i<arr.size();i++)
	{
		if(arr[i] ==1)
		{
			if(in[i] == '1')
			ans.PB('0');
			else
			ans.PB('1');
		}
		else
		ans.PB(in[i]);
	}
	return ans;
}
int main()
{
	ull n =0;
	cin>>n;
	ull tc =1;
	while(n--)
	{
		ull a,b;
		cin>>a>>b;
		vector<string>inp;
		vector<string>out;
		for(ull i =0;i<a;i++)
		{
			string x;
			cin>>x;
			inp.PB(x);
		}
		for(ull i =0;i<a;i++)
		{
			string x;
			cin>>x;
			out.PB(x);
		}
		ull ans =INF;
		for(ll i =0;i<(1<<b);i++)
		{
			map<string,bool>temp;
			for(ull j =0;j<a;j++)
			{
				string d = inp[j];
				string y = do_And(d,i);
				//cout<<d<<" "<<i<<" "<<y<<endl;
				temp[y] = true;
			}
			bool bt =true;
			for(ull j =0;j<a && bt;j++)
			{
				if(temp.find(out[j])==temp.end())
				bt =false;
			}
			if(bt)
			{
			ans = i;
			break;}
		}
		cout<<"Case #"<<tc++<<": ";
		if(ans ==INF)
		cout<<"NOT POSSIBLE"<<endl;
		else
		cout<<count(ans)<<endl;
	}
	return 0;
}