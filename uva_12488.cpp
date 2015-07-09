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
#define graphAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<20
using namespace std;
int main()
{
	int n =0;
	while(scanf("%d",&n)==1)
	{
		vector<int>arr(n);
		for(int i =0;i<n;i++)
		cin>>arr[i];
		vector<int>brr(n);
		for(int i =0;i<n;i++)
		cin>>brr[i];
		int nas =0;
		for(int i =0;i<n;i++)
		{
			vector<int>temp;
			for(int j =0;j<n;j++)
			{
				if(arr[j]==brr[i])
				break;
				else
				temp.PB(arr[j]);
			}
			for(int k =0;k<temp.size();k++)
			{
				bool bt= false;
				for(int m =0;m<i;m++)
				{
					if(temp[k]==brr[m])
					bt= true;
				}
				if(!bt)
				nas++;
			}
		}
		cout<<nas<<endl;
	}
	return 0;
}