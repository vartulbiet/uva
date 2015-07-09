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
#define MP make_pair
#define INF 1<<30
using namespace std;

int main()
    {
    int t =0;
    cin>>t;
    while(t--)
        {
        int n =0;
        cin>>n;
        int x =0,y =0;bool bt =true;
       //3*i+5*j == n
	   for(int i = 0;bt && i<n;i++)
	   {
		for(int j =0;bt && j<n;j++)
		{
			if(3*i+5*j == n)
			{
				x =i;
				y =j;
				bt = false;
			}
		}
	   }
	   x =x*3;
	   y =y*5;
        string s;
        for(int k =0;k<x;k++)
            s.PB('5');
         for(int k =0;k<y;k++)
            s.PB('3');
			if(s.size()!=n)
			cout<<"-1"<<endl;
			else
        cout<<s<<endl;
    }
    return 0;
}