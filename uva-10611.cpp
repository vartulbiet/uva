#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#define INF 1<<30
using namespace std;

int binary_search(vector<int>vec,int item,int i,int j)
{
	if(i<j)
	{
			int t = (i+j)/2;
		if(vec[t]<= item && vec[(t)+1]>= item)
		{cout<<vec[t]<<vec[(t)+1];
		return 0;}
		else
		if(vec[t] >item)
		binary_search(vec,item,i,t);
		else
		binary_search(vec,item,t,j);
	}
	else
	return -1;
}

int main()
{
	int n =0;
	cin>>n;
	vector<int>vec;
	for(int i =0;i<n;i++)
	{
		int x =0;
		cin>>x;
		vec.push_back(x);
	}
	int q =0;
	cin>>q;
	for(int i =0;i<q;i++)
	{
		int t =0;
		cin>>t;
		int z =0;
		z  = binary_search(vec,t,0,vec.size());
		cout<<z;
		if(z!=-1 && z-1>=0 && z-1<n)
		cout<<vec[z-1]<<" ";
		else
		cout<<"X ";
		if(z!=-1 && z+1>=0 && z+1<n)
		cout<<vec[z+1]<<endl;
		else
		cout<<"X"<<endl;
	}
	return 0;
}