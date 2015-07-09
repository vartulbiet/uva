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
#define INF 1<<10
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		int a,b;
		cin>>a>>b;
		vector<int>elem;
		queue<pair<int,int> >q;
		for(int i =0;i<a;i++)
		{
			int y =0;
			cin>>y;
			elem.PB(y);
		}
		pair<int,int>ans = make_pair(elem[b],b);
		for(int i = 0;i<elem.size();i++)
		{
			q.push(make_pair(elem[i],i));
		}
		sort(elem.begin(),elem.end());
		int count =0;bool bt = true;
		for(int i =elem.size()-1;i>=0 && bt;i--)
		{
			int y = elem[i];
			while(y!=q.front().first)
			{
				pair<int,int>ss =q.front();
				q.pop();
				q.push(ss);
			}
			count++;
			if(y ==ans.first && q.front().second == ans.second)
			bt = false;
			q.pop();
		}
		cout<<count<<endl;
		n--;
	}
	return 0;
}