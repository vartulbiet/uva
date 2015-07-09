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
vector<string>mymap;
vector<string>vec;
bool rest(vector<bool>mecc,string ans,int k)
{
	string h;
	for(int i =0;i<vec.size();i++)
	{
		if(i!=k && mecc[i] == false)
		h+=vec[i];
	}
	for(int j =0;j<ans.size();j++)
	{
		for(int m =0;m<h.size();m++)
		{
			if(ans[j] == h[m])
			return false;
		}
	}
	return true;
}
void DFS( int k,string ans,vector<bool>temp)
{
	if(k == vec.size())
	{
		mymap.PB(ans);
	}
	else
	{
		for( int i =0;i<vec.size();i++)
		{
			vector<bool>mecc = temp;
			if(temp[i] == false && rest(mecc,ans,i))
			{
				string h =ans;
				h+=vec[i];
				mecc[i] =true;
				DFS(k+1,h,mecc);
			}
		}
	}
}
 int main()
{
	 int n =0;
	cin>>n; int tc =1;
	while(n--)
	{
		 int k =0;
		cin>>k;
		
		for( int i =0;i<k;i++)
		{
			string z;
			cin>>z;
			vec.PB(z);
		}
		sort(vec.begin(),vec.end());
		for( int i =0;i<vec.size();i++)
		{
			vector<bool>temp;
			for( int k =0;k<vec.size();k++)
			temp.PB(false);
			temp[i] = true;
			DFS(1,vec[i],temp);
		} int ans =0;
		for(std::vector<string>::iterator it =mymap.begin();it!=mymap.end();it++)
		{
			string h= *it;
			vector< int>count(30);
			fill(count.begin(),count.end(),0);
			string g = h;
			//cout<<g<<endl;
			for( int i =0;i<g.size();i++)
			{
				count[g[i] -'a']++;
			}
			 int k =0;
			//cout<<h<<endl;
			bool bt =true;
			while(k<h.size() && bt)
			{
				 int c = count[h[k]-'a'];//cout<<c<<" ";
				for( int i = k;i<k+c;i++)
				{
					if(h[i] != h[k])
					{
					bt =false;
					break;
					}
				}
				k= k+c;
			}
			if(bt)
			{
			//cout<<h<<endl;
			ans++;
			}
		}
		ans = ans %1000000007;
		cout<<"Case #"<<tc++<<": "<<ans<<endl;
		vec.clear();
		mymap.clear();
	}
}