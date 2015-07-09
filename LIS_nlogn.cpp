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
#define INF 1<<20
using namespace std;
int get_index(vector<int>vec,int i,int j,int k)
{
	while(j-i>1)
	{
		int m = (j+i)/2;
		if(vec[m]>=k)
			j =m;
		else
			i =m;
	}
	return j;
}
void LIS(int*arr,int n)
{
	vector<int>vec;
	vec.PB(arr[0]);
	for(int i =1;i<n;i++)
	{
		if(arr[i]<vec[0])
		vec[0] = arr[i];
		else if(vec[vec.size()-1]<arr[i])
		vec.PB(arr[i]);
		else
		vec[get_index(vec,-1,vec.size()-1,arr[i])] = arr[i];
		for(int i=0;i<vec.size();i++)
	cout<<vec[i]<<" ";
	cout<<endl;
	}
	for(int i=0;i<vec.size();i++)
	cout<<vec[i]<<" ";
	cout<<endl;
}
int main()
{
	int arr[]={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int n = ARRAY_SIZE(arr);
	LIS(arr,n);
}