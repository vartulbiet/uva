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
vector<int>vec;
int n;
void init_segment_tree(int x)
{
	double z =ceil((log (x))/(log (2)));
	cout<<z<<endl;
	int size =2*pow(2,z)-1;
	cout<<size<<endl;
	for(int i =0;i<size;i++)
	vec.PB(0);
}

void build_segment_tree(int*arr,int node,int f,int e)
{
	cout<<node<<"--"<<left<<right<<f<<e<<endl;
	if(f==e)
	vec[node] = f;
	else
	{
		int left = 2*node+1;
		int right =2*node+2;
		build_segment_tree(arr,left,f,(f+e)/2);
		build_segment_tree(arr,right,(f+e)/2+1,e);
		int x = vec[left];
		int y = vec[right];
		vec[node] = arr[x]>arr[y]?y:x;
	}
}
int main()
{
	int arr[]={1,3,5,7,9,11};
	n =ARRAY_SIZE(arr);
	init_segment_tree(n);
	build_segment_tree(arr,0,0,n-1);
	for(int i =0;i<vec.size();i++)
	cout<<arr[vec[i]]<<" ";
	return 0;
}