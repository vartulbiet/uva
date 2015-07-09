#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#define REP(i, a, b) for ( int i = int(a); i <= int(b); i++ )
#define PB push_back
#define MP make_pair
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define MAXN 1000
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define INF 1<<30
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;

#define STAR '*'

int  getNonStarElementPosition(string expr,int prevPosition)
{
	for(int i = prevPosition; i < expr.size() ; i++)
	{
		if(expr[i] != STAR)
			return i;
	}
	return expr.size();
}
bool match(string str,string exp)
{
	int exp_pos = 0;
	int prev_pos = 0;
	int str_pos = 0;
	if(exp[0] == STAR)
	{
		exp_pos = getNonStarElementPosition(exp,0);
		prev_pos = exp_pos;
	}
	else
	{
		while(exp_pos < exp.size() && str_pos < str.size() && (str[str_pos] == exp[exp_pos]))
		{
			str_pos++;
			exp_pos++;
		}
		if(exp[exp_pos] == STAR)
		{
			exp_pos = getNonStarElementPosition(exp,0);
			prev_pos = exp_pos;
		}
		else
		{
			return false;
		}
	}
	while(str_pos<str.size())
	{
		while(str_pos<str.size() && exp_pos < exp.size() && str[str_pos] != exp[exp_pos])
		{
			str_pos++;
		}
		while(exp_pos < exp.size() && str_pos < str.size() && str[str_pos] == exp[exp_pos])
		{
			str_pos++;
			exp_pos++;
		}
		if(exp_pos == exp.size() && str_pos == str.size())
		return true;
		else
		{
			if(exp[exp_pos] != STAR)
			{
				exp_pos = prev_pos;
			}
			else
			{
				exp_pos = getNonStarElementPosition(exp,exp_pos);
				prev_pos = exp_pos;
				if(exp_pos == exp.size())
				{
					return true;
				}
			}
		}
	}
	if(exp_pos<exp.size() || str_pos<str.size())
	return false;
	else
	return true;
}

int main()
{
	string str;
	string exp;
	cin>>str>>exp;
	//cout<<str<<exp<<endl;
	bool t = match(str,exp);
	if(t)
	cout<<"true"<<endl;
	else
	cout<<"false"<<endl;
	return 0;
}