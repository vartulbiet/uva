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
typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{
	string s;
	cin>>s;
	while(s !="#")
	{
		vector<string>vec;
		map<char,char>ant;
		map<int,char>nat;

		nat[0] = 'A';nat[1] = 'G';nat[2] = 'N';nat[3] = 'P';nat[4] = 'S';

		while(s[0] != 'e')
		{
			vec.PB(s);
			//cout<<s<<endl;
			cin>>s;
		}
		map<char,vector<int> >mymap;
		for(int i =0;i<5;i++)
			mymap['r'].PB(0);
		for(int i =0;i<5;i++)
			mymap['o'].PB(0);
		for(int i =0;i<5;i++)
			mymap['y'].PB(0);
		for(int i =0;i<5;i++)
			mymap['g'].PB(0);
		for(int i =0;i<5;i++)
			mymap['b'].PB(0);
		for(int i =0;i<vec.size();i++)
		{
			string t = vec[i];
			for(int k = 2;k<t.size();k = k+4)
			if(t[k] == 'A')
			{
				mymap[t[k-2]][0]++;
			}
			else if(t[k] == 'G')
			{
				mymap[t[k-2]][1]++;
			}
			else if(t[k] == 'N')
			{
				mymap[t[k-2]][2]++;
			}
			else if(t[k] == 'P')
			{
				mymap[t[k-2]][3]++;
			}
			else if(t[k] == 'S')
			{
				mymap[t[k-2]][4]++;
			}	
		}
		for(std::map<char,vector<int> >::iterator it =mymap.begin();it != mymap.end();it++)
		{
			vector<int>att = it->second;
			int ans = 0,store =0;
			for(int j = 0;j<5;j++)
			{
				if(att[j]>ans)
				{
					store = j;
					ans = att[j];
				}
			}
			ant[it->first] = nat[store];
			//cout<<it->first <<" "<<nat[store]<<endl;
		}
		int index  = 0;
		for(int i =0;i<vec.size();i++)
		{
			string t = vec[i];int c =0;
			for(int k =2;k<t.size();k =k+4)
			{
				if(t[k] == ant[t[k-2]])
					c++;
			}
			if(c==5){
				index = i;
			break;}
		}
		cout<<index+1<<endl;
		cin>>s;
	}
	return 0;
}