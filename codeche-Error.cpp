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
	int n =0;
	cin>>n;
	string s;
		getline(cin,s);
	while(n>0)
	{
		getline(cin,s);
		bool bt = false;
		for(int i =0;i+2<s.size();i++)
		{
			if((s[i]=='1'  && s[i+1]=='0' && s[i+2]=='1') ||(s[i]=='0'  && s[i+1]=='1' && s[i+2]=='0'))
			{
				bt = true;
				break;
			}
		}
		if(bt)
		cout<<"Good"<<endl;
		else
		cout<<"Bad"<<endl;
		n--;
	}
}