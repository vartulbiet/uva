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
int main()
{
	int n =0;
	cin>>n;
	int tc =1;
	string s;
		getline(cin,s);
	while(n>0)
	{
		getline(cin,s);
		map<char,int>mymap;
		stack<char>st;
		st.push(s[0]);
		for(int i =1;i<s.size();i++)
		{
			if(s[i]==st.top())
			{
				st.pop();
			}
			else
			{
				mymap[s[i]]++;
				mymap[st.top()]++;
				st.push(s[i]);
			}
		}
		cout<<"Case "<<tc++<<endl;
		for(std::map<char,int>::iterator it= mymap.begin();it!=mymap.end();it++)
		{
			cout<<it->first<<" = "<<it->second<<endl;
		}
		n--;
	}
	return 0;
}