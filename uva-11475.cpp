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
	string s;
	while(getline(cin,s))
	{
			int t =0;
			int store =s.size()-1;
			bool bt =true;
			for(int i =1;i<s.size()-1;i++)
			{
				string a,b,subt;
				int n =0;int pos =s.size()-1;
				if(s.size()%2 ==0)
				{
					 a = s.substr(0,i+1);
					reverse(a.begin(),a.end());
				 subt =a.substr(0,s.size()-i-1);
					 b = s.substr(i+1,s.size()-i-1);
				}
				else
				{
					 a = s.substr(0,i);
					reverse(a.begin(),a.end());
					 subt =a.substr(0,s.size()-i-1);
					 b = s.substr(i+1,s.size()-i-1);	
				}
				cout<<subt<<"---"<<b<<endl;
				int j =0;
				for(j =0;j<b.size();j++)
				{
					if(subt[j] == b[j])
					n++;
				}
				if(n>t)
				{
					t =n;
					pos = s.size()-1-j;
				}
			}
			if(!bt)
			cout<<s<<endl;
			else
			{
			string sub =s.substr(0,store-t);
			cout<<sub<<endl;
			reverse(sub.begin(),sub.end());
			//cout<<sub<<endl;
			cout<<s+sub<<endl;
			}
	}
	return 0;
}