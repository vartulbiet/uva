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
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		int i =0;
		vector<int>arr;
		while(n!=0)
		{
			if(n&1)
			{
				arr.PB(i);
			}
			n = n>>1;
			i++;
		}
		int k =0;
		int p =0;
		for(int i =0;i<arr.size();i++)
		{
		if(i%2==0)
		k += pow(2,arr[i]);
		else
		p += pow(2,arr[i]);
		}
		cout<<k<<" "<<p<<endl;
		cin>>n;
	}
	return 0;
}