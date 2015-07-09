//sliding window.cpp
#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define SIZE sizeof(arr)/sizeof(int)
#define FEL(i,a,b) for(int i=a;i<b;i++)
#define INF 1<<30
using namespace std;
int main()
{
	int arr[]={2, 3, 4, 2, 6, 2, 5, 1};
	int n =8;
	int win =3;
	vector<int>ans;
	deque<int>d;
	for(int i =0;i<win;i++)
	{
		while(d.size()!=0 && arr[i]<arr[d.front()])
		d.pop_front();
		d.push_back(i);
	}
	for(int i = win;i<8;i++)
	{
		ans.push_back(arr[d.front()]);
		if(i-d.front()>=win)
			d.pop_front();
		while(d.size()!=0 && arr[i]<=arr[d.front()])
		d.pop_front();
		d.push_back(i);
	}
	ans.push_back(arr[d.front()]);
	for(int i =0;i<ans.size();i++)
	cout<<ans[i]<<" ";
	return 0;
}