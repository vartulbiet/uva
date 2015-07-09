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
void update(int*arr,int ind,int val)
{
	cout<<ind<<"--";
	while(ind<11)
	{
		arr[ind]  = max(arr[ind],val);
		ind += (ind & -ind);
		cout<<ind<<" ";
	}
	cout<<endl;
}

int get_sum(int*arr,int ind)
{
	int sum =-INF;
	while(ind>0)
	{
		sum =max(sum,arr[ind]);
		ind -= (ind & -ind);
	}
	return sum;
}
int get_val(int x,int y,int *arr)
{
	return max(get_sum(arr,y),get_sum(arr,x));
}
using namespace std;
int main()
{
	int arr[11];
	memset(arr,0,sizeof(arr));
	update(arr,1,2);
	update(arr,2,-2);
	update(arr,3,4);
	update(arr,4,4);
	update(arr,5,4);
	update(arr,6,4);
	update(arr,7,1);
	update(arr,8,3);
	update(arr,9,3);
	update(arr,10,3);
	int x,y;
	for(int i =0;i<11;i++)
	cout<<arr[i]<<" ";cout<<endl;
	cin>>x>>y;
	
	
	cout<<get_val(x,y,arr);
	return 0;
}