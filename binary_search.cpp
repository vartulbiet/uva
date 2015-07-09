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
#define ll long long int
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	int*arr  = (int*)malloc(sizeof(int)*n);
	while(n!=0)
	{
		int y =0;
		cin>>y;
		arr[i] = y;
	}
	int r =0;
	cin>>r;
	while(r--)
	{
	int em = 0;
	cin>>em;
	bool h = b_search(arr,0,n-1,em);
	if(h == false)
	cout<<"Not found"<<endl;
	else
	cout<<"found"<<endl;
	}
	return  0;
}