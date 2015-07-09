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
int LIS(vector<pair<int,int> >vec)
{
	int n = vec.size();
	int arr[n];
	for(int i =0;i<n;i++)
	arr[i] =vec[i].second;
	for(int i =1;i<n;i++)
	{
		int temp=arr[i];
		for(int j =0;j<i;j++)
		{
			if(vec[i].first>vec[j].first && (arr[j]+arr[i])>temp)
				temp = arr[j]+arr[i];
		}
		arr[i] = temp;
	}
	int mat =0;
	for(int i =0;i<n;i++)
	mat =max(mat,arr[i]);
	return mat;
}
int main()
{
	int n =0;
	cin>>n;
	int tt =1;
	while(n>0)
	{
		int  x =0;
		cin>>x;
		vector<pair<int,int> >arr;
		for(int i =0;i<x;i++)
		{
			int a;
			cin>>a;
			arr.push_back(make_pair(a,0));
		}
		for(int i =0;i<x;i++)
		{
			int a;
			cin>>a;
			pair<int,int>t = arr[i];
			t.second =a;
			arr[i] = t;
		}
		int h =LIS(arr);
		reverse(arr.begin(),arr.end());
		int k = LIS(arr);
		if(k<=h)
		cout<<"Case "<<tt++<<". Increasing ("<<h<<"). Decreasing ("<<k<<")."<<endl;
		else
		cout<<"Case "<<tt++<<". Decreasing ("<<k<<"). Increasing ("<<h<<")."<<endl;
		n--;
	}
	return 0;
}