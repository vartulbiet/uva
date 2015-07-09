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
int main()
{
	int t =0;
	cin>>t;
	string x,y;
	getline(cin,x);
	while(t>0)
	{
		getline(cin,x);
		getline(cin,y);
		bool bt = true;
		if(x.size()!=y.size())
		bt = false;
		for(int i = 0;i<x.size() && bt;i++)
		{
			if(x[i] == 'a' || x[i]=='i' || x[i] =='e' || x[i]=='o' || x[i] =='u')
			{
				if(y[i] == 'a' || y[i]=='i' || y[i] =='e' || y[i]=='o' || y[i] =='u')
				bt = true;
				else
				bt = false;
			}
			else
			{
				if(x[i] == y[i])
				bt = true;
				else
				bt = false;
			}
		
		}
		if(bt)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
		t--;
	}
	return 0;
}