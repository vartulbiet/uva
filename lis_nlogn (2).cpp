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

int mid_index(vector<int>temp,int l,int r,int value)
{ int m;
 
    while( r - l > 1 ) {
        m = l + (r - l)/2;
        (temp[m] >= value ? r : l) = m; // ternary expression returns an l-value
    }
 
    return r;
}

int LongestIncreasingSubsequenceLength(vector<int>arr,int n)
{
		vector<int>temp(n);
		temp[0] =arr[0];
int len =1;
	for(int i =1;i<n;i++)
	{
		if(arr[i]<temp[0])
		temp[0] = arr[i];
		else if(arr[i]>temp[len-1])
		temp[len++] = arr[i];
		else
			temp[mid_index(temp,-1,len-1,arr[i])] =arr[i];
	}
	for(int k =0;k<temp.size();k++)
		cout<<temp[k]<<" ";
		cout<<endl;
		return len;
}

int main() {
     vector< int> arr;
 int n;
 cin>>n;
 for(int i =0;i<n;i++)
 {
	int y;
	cin>>y;
	arr.PB(y);
 }
    printf("Length of Longest Increasing Subsequence is %d\n",
            LongestIncreasingSubsequenceLength( arr,n));
 
    return 0;
}