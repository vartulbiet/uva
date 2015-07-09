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
int arr[20];
int m,n;
int cont =0;
map<vector<int>,bool >mymap;
void get_sum(int ind,int ans[20],int sum,bool vec[20],int k)
{
	if(sum == m )
	{
		vector<int>keep;
		for(int i =0;i<ind;i++)
		keep.PB(ans[i]);
		sort(keep.begin(),keep.end());
		if(mymap.find(keep)==mymap.end())
		{
		cont++;
		mymap[keep] = true;
		for(int i =ind-1;i>=0;i--)
		{
			if(i!=ind-1)
			cout<<"+";
			cout<<keep[i];
		}
		cout<<endl;
		}
		return;
	}
	else
	{
		for(int i=k;i<n;i++)
		{
			if(vec[i]== false)
			{
				vec[i]= true;
				ans[ind] = arr[i];
				int y = sum;
				y +=arr[i];
				get_sum(ind+1,ans,y,vec,i);
				vec[i]= false;
			}
		}
		return;
	}
}
int main()
{
	cin>>m>>n;
	while(m!=0 && n!=0)
	{
		for(int i =0;i<n;i++)
		{
			cin>>arr[i];
		}
		int ans[20];
		cont =0;
		bool vec[20]={false};
		//fill(0,20,false);
		cout<<"Sums of "<<m<<":"<<endl;
		get_sum(0,ans,0,vec,0);
		if(cont == 0)
		cout<<"NONE"<<endl;
		mymap.erase(mymap.begin(),mymap.end());
		cin>>m>>n;
	}
	return 0;
}