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
#define INF 1<<30
using namespace std;
map<string,bool>mymap;
vector<char>vec;
void recurse(string s,vector<bool>visited,int c)
{
	if(c>=0)
	{
		if(mymap.find(s)!=mymap.end())
		return;
		mymap[s] = true;
		if(c==0)
		return;
		else
		{
			for(int i =0;i<s.size();i++)
			{
				if(visited[i]==false)
				{
					for(int j =0;j<vec.size();j++)
					{
						string temp = s;
						vector<bool>tt =visited;
						temp[i]=vec[j];
						tt[i] = true;
						recurse(temp,tt,c-1);
					}
				}
			}
		}
	}
}
int main()
{
	int n =0;
	cin>>n;
	vec.PB('A');vec.PB('C');vec.PB('G');vec.PB('T');
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		vector<bool>visited(a);
		for(int i =0;i<a;i++)
		visited[i] = false;
		string s;
		getline(cin,s);
		getline(cin,s);
		recurse(s,visited,b);
		cout<<mymap.size()<<endl;
		for(std::map<string,bool>::iterator it = mymap.begin();it!=mymap.end();it++)
		cout<<it->first<<endl;
		mymap.erase(mymap.begin(),mymap.end());
	}
	return 0;
}