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
int main()
{
	int n =0;
	while(scanf("%d",&n)!=EOF)
	{
		vector<int >arr;
		for(int i =0;i<n;i++)
		{
			int b =0;
			cin>>b;
			arr.PB(b);
		}
		int sum =0;
		for(int i =0;i<n;i++)
		{
			for(int j =i+1;j<n;j++)
			{
				if(arr[j]<arr[i])
				sum++;
			}
		}
		cout<<"Minimum exchange operations : "<<sum<<endl;
	}
	return 0;
}