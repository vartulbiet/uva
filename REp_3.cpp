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
void BFS(vector<string>vec,int max_l)
{
	map<string ,int>mapp;
	for(int i =0;i<vec.size();i++)
	mapp[vec[i]] =-1;
	mapp[vec[0]] =0;
	map<string ,int>mymap;
	mymap[vec[0]] = 0;
	queue<string>q;
	q.push(vec[0]);
	vector<int>arr(vec.size());
	fill(arr.begin(),arr.end(),-1);
	arr[0 ]=0;
	while(!q.empty())
	{
		string h = q.front();
		q.pop();
		if(mapp.find(h) !=mapp.end() )
		{
			mapp[h] =mymap[h];
			for(std::map<string,int>::iterator it = mymap.begin();it!=mymap.end();it++)
			{
				mymap[it->first] =0;
			}
		}
		for(int i =0;i<h.size()-1;i++)
		{
			string temp =h;
			if(h[i] == h[i+1])
			temp.erase(temp.begin()+i);
			if(mymap.find(temp) == mymap.end() && temp.size()<=max_l)
			{
				q.push(temp);
				//cout<<temp<<endl;
				mymap[temp] = mymap[h] +1;
			}
		}
		for(int i =0;i<h.size();i++)
		{
			string temp = h;
			temp.insert(temp.begin()+i,temp[i]);
			if(mymap.find(temp) == mymap.end()&& temp.size()<=max_l)
			{
				q.push(temp);
				//cout<<temp<<endl;
				mymap[temp] = mymap[h] +1;
			}
		}
	}
	int ans =0;bool ct =true;
	for(std::map<string,int>::iterator it = mapp.begin();it!=mapp.end();it++)
			{
				if(it->second ==-1){
				ct =false;
				break;}
				else
				ans+=it->second;
			}
	
	if(ct)
	cout<<ans<<endl;
	else
	cout<<"Fegla Won"<<endl;
	
}
int main()
{
	int n =0;
	cin>>n;int tc =1;
	while(n--)
	{
		int k =0;
		cin>>k;
		vector<string>vec;
		int l =0;
		while(k--)
		{
			string s;
			cin>>s;
			int y =s.size();
			l = max(l,y);
			vec.PB(s);
		}
		cout<<"Case #"<<tc++<<": ";
		BFS(vec,l);
	}
	return 0;
}