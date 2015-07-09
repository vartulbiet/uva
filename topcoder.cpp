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
	map<vector<ull>,bool >mymap;
	int n;
	ull sum(vector<ull>vec,int f)
	{
		ull su =0ull;
		reverse(vec.begin(),vec.end());
		for(int i =0;i<f;i++)
		su+=vec[i];
		return su;
	}
	bool conflict(ull g,vector<ull>ans)
	{
			if(ans.size()==0)
				return false;
			for(int i =0;i<ans.size();i++)
			{
					if(g>=ans[i])
						return false;
			}
			return true;
	}
	void recurse(vector<ull>touse,ull arr[],vector<ull>ans,int f)
	{
		if(ans.size()==n)
		{
			bool bt =true;
			for(int i =0;i<n-1;i++)
			{
				if(ans[i]>=ans[i+1])
				bt= false;
			}
			ull ff=0;int y =0;
			for(int i =n-1;i>0;i--)
			{
				ff+=ans[i];
				if(ff>arr[y++])
				bt= false;
			}
			if(bt)
			mymap[ans] = true;
		}
		else
		{
			for(int i =0;i<touse.size();i++)
			{
				if(!conflict(touse[i],ans))
				{
				vector<ull>vec = ans;
				vec.PB(touse[i]);
				if(sum(vec,f)<=arr[f-1])
				{
					vector<ull>temp =touse;
					temp.erase(temp.begin()+i);
					recurse(temp,arr,vec,f+1);
				}
				}
			}
		}
	}
int main()
{
	ull arr[] = {1326549, 3212423, 6546565, 8785456};
	n =4;
	vector<ull>touse;
	for(int i =1;i<=arr[0];i++)
	{
		touse.PB(i);
	}
	reverse(touse.begin(),touse.end());
	vector<ull>ans;
	recurse(touse,arr,ans,1);
	cout<<mymap.size();
	return 0;
}