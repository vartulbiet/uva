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
#define INF 1<<20
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
string codeToString(vector<int>a)
{
	string ans;
	for(int  i =0;i<a.size();i++)
	{
		if(a[i] == 27)
		ans.PB('.');
		else if(a[i] == 0)
		ans.PB('_');
		else ans.PB('a'+a[i] - 1);
	}
	return ans;
}
vector<int>cipher(string s)
{
	vector<int>ans;
	for(int i =0;i<s.size();i++)
	{
		if(s[i] == '_')
		ans.PB(0);
		else if(s[i] == '.')
		ans.PB(27);
		else ans.PB(s[i]-'a'+1);
	}
	return ans;
}
int main()
{
	int k =0;
	cin>>k;
	while(k!=0)
	{
		string s;
		 cin.get();
		getline(cin, s);
		//cout<<s<<endl;
		vector<int>ciph = cipher(s);
		vector<int>plaincode(s.size());
		int n = s.size();
		for(int i=0;i<n;i++)
		{
			int pos=(i*k)%n;
			int val=(ciph[i]+i)%28;
			plaincode[pos]=val;
		}
		cout<<codeToString(plaincode)<<endl;
		cin>>k;
	}
	return 0;
}