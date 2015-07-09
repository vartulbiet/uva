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

    bool reach(int curr,int n,int arr[],bool visited[])
    {
        if(curr==n-1)
        return true;
		if(curr>n-1)
		return false;
        else
        {
        int s = arr[curr];bool ans = false;
        for(int i =1;i<=s;i++)
        {
			if(visited[curr+i]== false)
			{
				visited[curr+i] = true;
				ans = ans || reach(curr+i,n,arr);
			}
        }
        return ans;
        }
    }
    bool canJump(int arr[], int n) {
        int i =0;int x =0;
		bool visited[n] ={false};
		visited[0] = true;
       return reach(i,n,arr,visited);
    }
	int main()
	{
		int arr[]={2,0};
		int n =2;
		cout<<canJump(arr,n);
		return 0;
	}