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
 int DP(int sum,int*arr,int step,int sz)
 {
     int table[step][sum+1];
     for(int i =0;i<step;i++)
     {
         for(int j =0;j<=sum;j++)
         {
             table[i][j] =0;
         }
     }
     for(int i =1;i<=sz;i++)
     table[0][i] =1;
     for(int i =1;i<step;i++)
     {
         for(int j =1;j<=sum;j++)
         {
             for(int k =0;k<sz;k++)
             {
                 if(arr[k]<=j)
                 {
                     table[i][j]= table[i][j]+table[i-1][j-arr[k]];
                 }
             }
         }
     }
     return table[step-1][sum];
 }
 int main()
 {
     int arr[]={1,2,3,4,5,6};
     int sum =0;int steps =0;
     cin>>sum>>steps;
     cout<<DP(sum,arr,steps,6);
 }