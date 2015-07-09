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
	string g;
	cin>>n;
	string s;
	getline(cin,g);
	getline(cin,g);
	while(n>0)
	{
		getline(cin,s);
		getline(cin,g);
		int ans =0;
		for(int i =1;i<=s.size();i++)
		{
			string z = s.substr(0,i);
			int j =0;
			for(j =0;j<s.size();)
			{
				string h =s.substr(j,i);
				if(h==z)
				j+=i;
				else
				break;
			}
			if(j ==s.size())
			{
				ans =i;
				break;
			}
		}
		cout<<ans<<endl;
		if(n!=1)
		cout<<endl;
		n--;
	}
}