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
	int m,n;
	cin>>m>>n;
	while(m!=0 || n!=0)
	{
		int arr[1024];
		ull crr[1024] = {0};
		for(int i =1;i<=m;i++)
		scanf("%d",&arr[i]);
		for(int i =1;i<=m;i++)
		crr[i] =0;
		crr[0] =1;
		for(int i =1;i<=m;i++)
		{
			crr[0] =1;
			for(int k =m;k>=1;k--)
			{
				crr[k]=(ull)(crr[k]+(ull)arr[i]*crr[k-1])%n; 
			}
		}

		ull nas =0;
		for(int i =1;i<=m;i++)
		nas = max(nas,crr[i]);
		cout<<nas<<endl;
		cin>>m>>n;
	}
	return 0;
}