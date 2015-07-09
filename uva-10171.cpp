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
#define INF 1<<20
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
using namespace std;
int arr[30][30];
int brr[30][30];
bool young[30][30];
bool mature[30][30];
void init()
{
	for(int i =0;i<30;i++)
	{
		for(int j =0;j<30;j++)
		{
			arr[i][j] = INF;
			brr[i][j] = INF;
			young[i][j] = false;
			mature[i][j] = false;
		}
		arr[i][i] =0;
		brr[i][i] =0;
	}
}
void floyd_warshall_young(int a,map<int,int>&mymap1)
{
	int vall[30][30];
	for(int i =0;i<30;i++)
	{
		for(int j =0;j<30;j++)
		{
			if(young[i][j])
			vall[i][j] = arr[i][j];
			else
			vall[i][j] = INF;
		}
		vall[i][i] =0;
	}
	for(int i =0;i<30;i++)
	{
		for(int k =0;k<30;k++)
		{
			for(int j =0;j<30;j++)
			{
				vall[k][j] = min(vall[k][j],vall[k][i]+vall[i][j]);
			}
		}
	}
	for(int i =0;i<30;i++)
	{
		if(vall[a][i]!=INF)
		{
			//cout<<i<<"--";
			mymap1[i] = vall[a][i];
			}
	}
//cout<<endl;
}
void floyd_warshall_mature(int a,map<int,int>&mymap2)
{
	int vall[30][30];
	for(int i =0;i<30;i++)
	{
		for(int j =0;j<30;j++)
		{
			if(mature[i][j])
			vall[i][j] = brr[i][j];
			else
			vall[i][j] = INF;
		}
		vall[i][i] =0;
	}
	for(int i =0;i<30;i++)
	{
		for(int k =0;k<30;k++)
		{
			for(int j =0;j<30;j++)
			{
				vall[k][j] = min(vall[k][j],vall[k][i]+vall[i][j]);
			}
		}
	}
	for(int i =0;i<30;i++)
	{
		if(vall[a][i]!=INF)
		{
		//	cout<<i<<"--";
			mymap2[i] = vall[a][i];
			}
	}
//	cout<<endl;
}
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		char a,b,c,d;
		int x;
		init();
		for(int i =0;i<n;i++)
		{
		cin>>a>>b>>c>>d>>x;
		if(a=='Y')
		{
			young[c-'A'][d-'A'] = true;
			young[d-'A'][c-'A'] = true;
			if(x<arr[c-'A'][d-'A'])
			arr[c-'A'][d-'A'] = x;
			if(b == 'B')
			arr[d-'A'][c-'A'] = arr[c-'A'][d-'A'];
		}
		else
		{
			mature[c-'A'][d-'A'] = true;
			mature[d-'A'][c-'A'] = true;
			if(x<brr[c-'A'][d-'A'])
			brr[c-'A'][d-'A'] = x;
			if(b == 'B')
			brr[d-'A'][c-'A'] = brr[c-'A'][d-'A'];
		}
		
		}
		char start,end;
		cin>>start>>end;
		int s = start-'A';
		map<int,int>mymap1,mymap2;
		floyd_warshall_young(s,mymap1);
		int e = end-'A';
		floyd_warshall_mature(e,mymap2);
		
		vector<pair<int,char> >vf;
		for(std::map<int,int>::iterator it =mymap1.begin();it!=mymap1.end();it++)
		{
			if(mymap2.find(it->first)!=mymap2.end())
			{
				vf.PB(make_pair(it->second+mymap2[it->first],char(it->first+'A')))	;
			}
		}
		if(vf.size()==0)
		cout<<"You will never meet.";
		else
		{
		sort(vf.begin(),vf.end());
		cout<<vf[0].first;
		for(int i =0;i<vf.size();i++)
		{
			if(vf[0].first == vf[i].first)
			cout<<" "<<vf[i].second;
		}
		}
		cout<<endl;
		cin>>n;
	}
	return 0;
}