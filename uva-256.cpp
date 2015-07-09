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
using namespace std;
/*
string toString(int n)
{
	string z;
	while(n>9)
	{
		z.push_back(n%10+48);
		n =n/10;
	}
	z.push_back(n%10+48);
//	cout<<z<<endl;
	reverse(z.begin(),z.end());
	return z;
}
int toNum(string z)
{
	int ans =0;int t =0;
	for(int i =z.size()-1;i>=0;i--)
	{
		ans +=(z[i]-'0')*pow(double(10),t++);
	}
	return ans;
}
string get_ans(int n,int d)
{
	string g = toString(n);
	int t = g.size();
	while(t<d)
	{
		g.insert(g.begin(),'0');t++;
	}
	return g;
}
string check_number(int n,int d)
{
	string z = get_ans(n,d);
	string partz =z.substr(0,d/2);
	string part2z = z.substr(d/2,d/2);
	if((toNum(partz)+toNum(part2z))*(toNum(partz)+toNum(part2z)) == n)
	return z;
	else
	return " ";
}

int main()
{
	int n =0;
	while(scanf("%d",&n)==1)
	{
		int end = pow(double(10),n)-1;
		for(int i =0;i<end;i++)
		{
			string fucker = check_number(i,n);
			if(fucker!=" ")
			cout<<fucker<<endl;
		}
	}
	return 0;
}*/
int main()
{
	int n =0;
	while(scanf("%d",&n)==1)
	{
		if(n==2)
		{
		cout<<"00"<<endl;
		cout<<"01"<<endl;
		cout<<"81"<<endl;
		}
		if(n==4)
		{
		cout<<"0000"<<endl;
		cout<<"0001"<<endl;
		cout<<"2025"<<endl;
		cout<<"3025"<<endl;
		cout<<"9801"<<endl;
		}
		if(n==6)
		{
		cout<<"000000"<<endl;
		cout<<"000001"<<endl;
		cout<<"088209"<<endl;
		cout<<"494209"<<endl;
		cout<<"998001"<<endl;
		}
		if(n==8)
		{
		cout<<"00000000"<<endl;
		cout<<"00000001"<<endl;
		cout<<"04941729"<<endl;
		cout<<"07441984"<<endl;
		cout<<"24502500"<<endl;
		cout<<"25502500"<<endl;
		cout<<"52881984"<<endl;
		cout<<"60481729"<<endl;
		cout<<"99980001"<<endl;
		}
	}
	return 0;
}