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
using namespace std;
	
void print_as_desired(vector<string>toPrint,vector<string>inp,int g,int ind)
{
	if(toPrint.size()==g)
	{
		for(int i =0;i<g;i++){
		cout<<toPrint[i];if(i!=g-1)cout<<", ";}
		cout<<endl;
	}
	else if(toPrint.size()<g)
	{
		for(int i =0;i<inp.size();i++)
		{
			if(i>ind && toPrint.size()<g)
			{
				vector<string>temp = toPrint;
				temp.PB(inp[i]);
				print_as_desired(temp,inp,g,i);
			}
		}
		return;
	}
	else 
	return;
}
int main()
{
	int n =0;
	cin>>n;
	string s;
		getline(cin,s);
		getline(cin,s);
	while(n>0)
	{
		int a,b;
		getline(cin,s);
		 if(s != "*") {
            if(sscanf(s.c_str(), "%d %d\n", &a, &b) == 1)
                b = a;
        } else a = 0, b = 0;
		string z;vector<string>vec;
		while(getline(cin,z) && z.size()>0)
		{
			vec.PB(z);
		}
		//cout<<a<<b;
		if(s=="*")
		{
			a =1;
			b =vec.size();
		}
		for(int i =a;i<=b;i++)
		{
			vector<string>toPrint;
			cout<<"Size "<<i<<endl;
			print_as_desired(toPrint,vec,i,-1);
			cout<<endl;
		}
			if(n!=1)
			cout<<endl;
			n--;
	}
	return 0;
}