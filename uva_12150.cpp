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
int  main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		bool bt =true;
		vector<int>arr(n);
		fill(arr.begin(),arr.end(),-1);
		for(int i =0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			if(i+b<0 || i+b>=arr.size() || arr[i+b]!=-1)
			bt = false;
			else
			arr[i+b] =a;	
		}
		if(bt)
		{
			for(int i =0;i<n;i++)
			{
			cout<<arr[i];
			if(i!=n-1)
			cout<<" ";
			else
			cout<<endl;
			}
		}
		else
		cout<<"-1"<<endl;
		cin>>n;
	}
	return 0;
}