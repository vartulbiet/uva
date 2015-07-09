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
		string rev =s;
		//reverse(rev.begin(),rev.end());
		int nas =0;int pos=0;
		for(int i =rev.size()-1;i>=0;i--)
		{
			int k = i;int n =0;
			for(int j =0;j<s.size(),k>=0;j++)
			{
				if(rev[k--]==s[j])
				n++;
				else break;
			}
			if(nas<n)
			{
				nas =n;
				pos =i;
			}
		}
		//cout<<nas<< "  "<<pos<<endl;
		cout<<s.substr(pos-nas+1,nas)<<endl;
		n--;
	}
	return 0;
}