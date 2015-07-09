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
#define INF 1<<30
using namespace std;
int main()
{
	ull n =0;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		ull c =0;
		stack<pair<char,int> >st;
		for(ull i =0;i<s.size();i++)
		{
			if(s[i] == '<')
			st.push(make_pair(s[i],i+1));
			else if(s[i] == '>')
			{
				if(st.empty())
					break;
				char t = st.top().first;
				if(t == '<')
				{
				st.pop();
				c=c+2;}
				else
				break;
			}
		}
		if(st.empty())
		cout<<c;
		else
		{
		while(!st.empty())
		{
			c =st.top().second;
			st.pop();
		}
		cout<<c-1;
		}
		cout<<endl;
	}
	return 0;
}