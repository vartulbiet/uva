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

map<string,int>hold;
vector<pair<int,int> >ans;

void update(string s)
{
	map<char,int>pos;
	pos['T'] = 0;pos['C'] = 0;pos['G'] = 0;pos['A'] = 0;
	map<char,int>till;
	till['T'] = 0;till['C'] = 0;till['G'] = 0;till['A'] = 0;
	vector<int>x(s.size());
	for(int i =s.size()-1;i>=0;i--)
	{
		if(s[i] == 'T')
		{
			
			till['T'] = pos['A']+pos['C']+pos['G'];
			x[i] = till['T'];pos['T']++;
		}
		else if(s[i] == 'G')
		{
			
			till['G'] = pos['A']+pos['C'];
			x[i] = till['G'];pos['G']++;
		}
		else if(s[i] == 'C')
		{
			
			till['C'] = pos['A'];
			x[i] = till['C'];pos['C']++;
		}
		else
		{
			pos['A']++;
			till['A'] = 0;
			x[i] = 0;
			//cout<<x[i]<<"--";
		}
	}
	//cout<<endl;
	int sum =0;
	for(int i =s.size()-1;i>=0;i--)
	{
		sum+=x[i];
	}
	//cout<<sum<<endl;
	ans.PB(make_pair(sum,hold[s]));
}
int main()
{
	int n =0;
	cin>>n;
	while(n>0)
	{
		int a,b;
		cin>>a>>b;
		string s;
		vector<string>k;
		for(int i =0;i<b;i++)
		{
			cin>>s;
			hold[s] =i;
			k.PB(s);
			update(s);
		}
		sort(ans.begin(),ans.end());
		for(int i =0;i<ans.size();i++)
		{
			cout<<k[ans[i].second]<<endl;
		}
		hold.erase(hold.begin(),hold.end());
		ans.erase(ans.begin(),ans.end());
		if(n!=1)
		cout<<endl;
		n--;
	}
	return 0;
}